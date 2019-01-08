#include <vector>
#include "header/ids.hpp"
#include "header/HMM.hpp"
#include "header/utils.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

Ids::Ids(string filename, float t){
    //Read data
    ifstream infile(filename);
    string line;
    state s = STATES_;
    int count = -1;
    int M, N;
    vector<int> v_;
    vector<string> tmp;
    vector<vector<float>> A;
    vector<vector<float>> B;
    while(getline(infile, line)){
	//cout << line << endl; 
	switch(s){
	case STATES_:
	    if(line.compare("") == 0){
		s = V_;
		count = -1;
		break;
	    }
	    
	    if(count == -1){
		N = stoi(line);
		count ++;
	    } else {
		Ids::S.insert(pair<string, int>(line, count++));
	    }
	    break;
	case V_:
	    if(line.compare("") == 0){
		s = A_;
		count = 0;
		break;
	    }
	    
	    if(count == -1){
		M = stoi(line);
		count ++;
	    } else {
		v_.push_back(count);
		Ids::V.insert(pair<string, int>(line, count++));
	    }
	    break;
	case A_:
	    if(line.compare("") == 0){
		s = B_;
		count=0;
		break;
	    }
	    A.push_back(vector<float>(N));
	    tmp = split(line, ' ');
	    for(int i=0; i<N; i++){
		A[count][i] = stof(tmp[i]);
	    }
	    count ++;
	    break;
	case B_:
	    B.push_back(vector<float>(M));
	    tmp = split(line, ' ');
	    for(int i=0; i<M; i++){
		B[count][i] = stof(tmp[i]);
	    }
	    count ++;
	    break;
	}
    }
    vector<float> pi = vector<float>(N);
    pi[0] = 1.0;
    for(int i=1;i<N;i++)pi[i]=0.0;
    Ids::m = Model(N,pi,A, v_,B,M);
    Ids::threshold = t;
}

bool Ids::is_intrusion(string file_obs){
    //Read data
    vector<int> obs=Ids::read_observation(file_obs);

    float p = Ids::m.forward(obs);
    if(log(p) > p){
	return true;
    }else{
	return false;
    }
}

void Ids::get_type_intrusion(string file_obs){
    //Read data;
    vector<int> obs=Ids::read_observation(file_obs);

    vector<int> seq = Ids::m.viterbi(obs);
    vector<float> dist = vector<float>(Ids::type_seq.size());
    for(int i=0; i<(int)Ids::type_seq.size(); i++){
	dist[i] = euclidean_dist(seq, Ids::type_seq[i]);
    }
    cout << type_names[argmax(dist)] << " : " << max(dist) << "\n";
    
}

vector<int> Ids::read_observation(string filename){
    ifstream infile(filename);
    string line;
    getline(infile, line);
    vector<string> tmp = split(line, ',');
    vector<int> obs;
    for(int i=0; i<(int)tmp.size();i++){
	obs.push_back(Ids::V[tmp[i]]);
    }
    return obs;
}

void Ids::print_state_sequence(vector<int> v){
    cout << "Optimal Sequence = ";
    map<string, int>::iterator it;
    for(int i = 0; i<(int)v.size(); i++){
	for (it = Ids::S.begin(); it != Ids::S.end(); ++it ){
	    if (it->second == v[i]){
	        cout << it->first<<  " ";
	    }
	}
    }
    cout << endl;
}
Model Ids::get_m(){
    return Ids::m;
}
