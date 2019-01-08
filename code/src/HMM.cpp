#include "header/HMM.hpp"
#include "header/utils.hpp"
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

Model::Model(int N, vector<float> pi, vector<vector<float>> A,
                  vector<int> V,vector<vector<float>> B, int M) {
    Model::N = N;
    Model::M = M;
    Model::pi = pi;
    Model::A = A;
    Model::V = V;
    Model::B = B;

    cout.precision(5);
    for(int t=0; t<N; t++){
	for(int i = 0; i<N; i++){
	    cout << "a" << t << i << " = " <<
		setw(9) << Model::A[t][i] << "\t";
	}
	cout << endl;
    }
    cout << "###############################" << endl;

    cout.precision(5);
    for(int t=0; t<N; t++){
	for(int i = 0; i<M; i++){
	    cout << "b" << t << i << " = " <<
		setw(9) << Model::B[t][i] << "\t";
	}
	cout << endl;
    }
    cout << "###############################" << endl;
    
}

Model::Model(){
    Model::N=0;
    Model::pi = vector<float>();
    Model::A = vector<vector<float>>();
    Model::V=vector<int>();
    Model::B=vector<vector<float>>();
    Model::M=0;
}
int Model::getN(){
    return Model::N;
}

vector<float> Model::getPi(){
    return Model::pi;
}

vector<vector<float>> Model::getA(){
    return Model::A;
}

vector<int> Model::getV(){
    return Model::V;
}

vector<vector<float>> Model::getB(){
    return Model::B;
}

float Model::forward(vector<int> obs){
    float p = 0.0;
    
    int T = obs.size();
    vector<vector<float>> alpha(T);
    for(int t=0; t<T; t++){
	alpha[t] = vector<float>(Model::N);
    }

    //Initialization
    for(int i=0; i<Model::N; i++){
	alpha[0][i] = Model::pi[i]*Model::B[i][obs[0]];
    }
    
    //Induction
    for(int t=1; t<T; t++){
	for(int j=0; j<Model::N; j++){
	    float sum = 0.0;
	    for(int i=0; i<Model::N; i++){		
		//cout << alpha[t-1][i] << " " << Model::A[i][j] << endl;
		sum += (alpha[t-1][i] * Model::A[i][j]);
	    }
	    alpha[t][j] = sum * Model::B[j][obs[t]];
	}
	
    }

    cout.precision(5);
    for(int t=0; t<T; t++){
	for(int i = 0; i<N; i++){
	    cout << alpha[t][i] << "\t";
	}
	cout<< endl;
    }
    cout << "###############################" << endl;

	
    //Termination
    for(int i=0; i<N; i++){
	p+=alpha[T-1][i];
    }
    cout << "P(0|l) = " << p << endl;
    return p;
}

vector<int> Model::viterbi(vector<int> obs){
    float optimal_prob = 0.0;
    
    int T = obs.size();
    vector<int> optimal_sequence = vector<int>(T);
    vector<vector<float>> delta = vector<vector<float>>(T);
    for(int t=0; t<T; t++) delta[t] = vector<float>(N);
    vector<vector<float>> psi = vector<vector<float>>(T);
    for(int t=0; t<T; t++) psi[t] = vector<float>(N);

    //Initialization
    for(int i; i<N; i++){
	delta[0][i] = Model::pi[i]*Model::B[i][obs[0]];
    }

    //Recursion
    for(int t=1; t<T; t++){
	for(int j =0; j<Model::N; j++){
	    vector<float> l = vector<float>(Model::N);
	    for(int k =0; k<Model::N; k++){
		l[k] = delta[t-1][k]*Model::A[k][j]*Model::B[j][obs[t]];
	    }
	    delta[t][j] = max(l);
	    psi[t][j] = argmax(l); 
	}
    }

    cout << "psi = " << endl;
    cout.precision(5);
    for(int t=0; t<T; t++){
	for(int i = 0; i<Model::N; i++){
	    cout << delta[t][i] << "\t";
	}
	cout << endl;
    }
    cout << "###############################" << endl;

    cout << "psi = " << endl; 
    cout.precision(5);
    for(int t=0; t<T; t++){
	for(int i = 0; i<Model::N; i++){
	    cout << psi[t][i] << "\t";
	}
	cout << endl;
    }
    
    //Termination
    optimal_sequence[T-1] = argmax(delta[T-1]);
    optimal_prob = max(delta[T-1]);
    cout << "Probability of optimal sequence " << optimal_prob << "\n"; 

    
    //Backtracking
    for(int t=T-2; t>= 0; t--){
	optimal_sequence[t] = psi[t+1][optimal_sequence[t+1]];
    }
    
    return optimal_sequence;
}
