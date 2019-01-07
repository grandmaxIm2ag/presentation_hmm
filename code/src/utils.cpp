#include <vector>
#include "header/utils.hpp"
#include <cmath>

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


float euclidean_dist(vector<int> x, vector<int> y){
    float res = 0.0;

    for(int i=0; i<(int)x.size(); i++){
	res+=((x[i]-y[i])*(x[i]-y[i]));
    }
    
    return sqrt(res);
}
