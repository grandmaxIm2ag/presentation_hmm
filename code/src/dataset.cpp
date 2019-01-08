#include "header/utils.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "header/dataset.hpp"
#include <fstream>

using namespace std;

Dataset::Dataset(string filename){
    ifstream infile(filename);
    string line;
    while(getline(infile, line)){
	vector<string> tmp = split(line, ',');
	vector<string> line_data;
	string line_label;
	for(int i=0; i<(int)tmp.size(); i++){
	    if(i < (int)tmp.size()-1){
		line_data.push_back(tmp[i]);
	    }else{
		line_label = tmp[i].substr(0, tmp[i].length()-1);
	    }
	}
	if(!find_elem(Dataset::labels, line_label)){
	    Dataset::labels.push_back(line_label);
	}
	if(line_label.compare("normal")==0){
	    Dataset::normal_data.push_back(line_data);
	}else{
	    Dataset::intrusion_labels.push_back(line_label);
	    Dataset::intrusion_data.push_back(line_data);
	}
    }
}

vector<vector<string>> Dataset::get_normal_data(){
    return Dataset::normal_data;
}
vector<vector<string>> Dataset::get_intrusion_data(){
    return Dataset::intrusion_data;
}
vector<string> Dataset::get_intrusion_labels(){
    return Dataset::intrusion_labels;
}
vector<string> Dataset::get_labels(){
    return Dataset::labels;
}
