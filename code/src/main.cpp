#include <iostream>
#include <vector>
#include <string>
#include "header/HMM.hpp"
#include "header/dataset.hpp"
#include "header/ids.hpp"

using namespace std;

int main()
{
    Ids ids = Ids("dataset/example2.hmm", 0.0);
    vector<int> states = ids.get_m().viterbi(ids.read_observation("dataset/example_ok.hmm"));
    ids.print_state_sequence(states);
    return 0;
}
