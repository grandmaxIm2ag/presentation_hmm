#ifndef IDS_H
#define IDS_H

#include <string>
#include <vector>
#include "HMM.hpp"

using namespace std;

class Ids {
private:
    Model m;
    vector<string> type_names;
    vector<vector<int>> type_seq;
    float threshold;
public:
    Ids(string filename, float t);
    bool is_intrusion(string file_obs);
    void get_type_intrusion(string file_obs);
};
#endif
