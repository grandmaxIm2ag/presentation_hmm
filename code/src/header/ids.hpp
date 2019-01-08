#ifndef IDS_H
#define IDS_H

#include <string>
#include <vector>
#include "HMM.hpp"
#include <map>
using namespace std;

class Ids {
private:
    Model m;
    vector<string> type_names;
    vector<vector<int>> type_seq;
    map<string, int> V;
    map<string, int> S;
    float threshold;
public:
    Ids(string filename, float t);
    vector<int> read_observation(string filename);
    bool is_intrusion(string file_obs);
    void get_type_intrusion(string file_obs);
    Model get_m();
    void print_state_sequence(vector<int> v);
};
#endif
