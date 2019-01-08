#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

enum state {STATES_=1, V_=2, A_=3, B_=4, TYPE_};
float max(vector<float> l);
int argmax(vector<float> l);
float min(vector<float> l);
int argmin(vector<float> l);
float euclidean_dist(vector<int> x, vector<int> y);
vector<string> split(string str, char delim);
bool find_elem(vector<string> vect, string val);
#endif
