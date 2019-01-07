#ifndef HMM_H
#define HMM_H

#include <vector>

#define JUMPLIMIT 2
using namespace std;

class Model {
private:
    int N;
    int M;
    vector<float> pi;
    vector<vector<float>> A;
    vector<int> V;
    vector<vector<float>> B;
public:
    Model(int N, vector<float> pi, vector<vector<float>> A,
          vector<int> V,vector<vector<float>> B, int M);
    Model();
    int getN();
    void train(vector<int> train);
    vector<float> getPi();
    vector<vector<float>> getA();
    vector<int> getV();
    vector<vector<float>> getB();
    float forward(vector<int> obs);
    vector<int> viterbi(vector<int> obs);
};
#endif
