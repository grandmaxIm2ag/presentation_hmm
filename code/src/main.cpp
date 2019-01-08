#include <iostream>
#include <vector>
#include <string>
#include "header/HMM.hpp"
#include "header/dataset.hpp"
#include "header/ids.hpp"

using namespace std;

int main()
{
    Ids ids = Ids("dataset/example_ids_2.hmm", -20.83);
    if(ids.is_intrusion("dataset/example_ids_seq_bad.hmm")){
	ids.get_type_intrusion("dataset/example_ids_seq_bad.hmm");
    }
    return 0;
}
