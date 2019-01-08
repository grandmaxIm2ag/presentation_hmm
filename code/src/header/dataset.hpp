#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <vector>

using namespace std;

class Dataset {
private:
    vector<vector<string>> normal_data;
    vector<vector<string>> intrusion_data;
    vector<string> labels;
    vector<string> intrusion_labels;
public:
    Dataset(string filename);
    vector<vector<string>> get_normal_data();
    vector<vector<string>> get_intrusion_data();
    vector<string> get_intrusion_labels();
    vector<string> get_labels();
};
#endif
