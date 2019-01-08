#include <vector>
#include "header/utils.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

float max(vector<float> l){
    float res = l[0];
    for(int i=1; i<(int)l.size(); i++){
	if(l[i] > res){
	    res = l[i];
	}
    }
    return res;
}

int argmax(vector<float> l){
    int idx = 0;
    for(int i=1; i<(int)l.size(); i++){
	if(l[i] > l[idx]){
	    idx = i;
	}
    }
    return idx;
}

float min(vector<float> l){
    float res = l[0];
    for(int i=1; i<(int)l.size(); i++){
	if(l[i] < res){
	    res = l[i];
	}
    }
    return res;
}

int argmin(vector<float> l){
    int idx = 0;
    for(int i=1; i<(int)l.size(); i++){
	if(l[i] < l[idx]){
	    idx = i;
	}
    }
    return idx;
}


float euclidean_dist(vector<int> x, vector<int> y){
    float res = 0.0;

    for(int i=0; i<(int)x.size(); i++){
	res+=((x[i]-y[i])*(x[i]-y[i]));
    }
    
    return sqrt(res);
}

vector<string> split(string str, char delim) {
    vector<string> res;

    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, delim)) {
	res.push_back(tmp);
    }
    return res;
}

bool find_elem(vector<string> vect, string val){
    for(int i=0; i<(int)vect.size();i++){
	if(vect[i].compare(val) == 0)
	    return true;
    }
    return false;
}
