#include <vector>
#include "header/ids.hpp"
#include "header/HMM.hpp"
#include "header/utils.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Ids::Ids(string filename, float t){
    //Read data
    Ids::threshold = t;
}

bool Ids::is_intrusion(string file_obs){
    //Read data
    vector<int> obs;

    float p = Ids::m.forward(obs);
    if(log(p) > p){
	return true;
    }else{
	return false;
    }
}

void Ids::get_type_intrusion(string file_obs){
    //Read data;
    vector<int> obs;

    vector<int> seq = Ids::m.viterbi(obs);
    vector<float> dist = vector<float>(Ids::type_seq.size());
    for(int i=0; i<(int)Ids::type_seq.size(); i++){
	dist[i] = euclidean_dist(seq, Ids::type_seq[i]);
    }
    cout << type_names[argmax(dist)] << " : " << max(dist) << "\n";
    
}
