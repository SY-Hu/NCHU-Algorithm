#include <iostream>
#include <cstdlib> 

#include "Ts.h"

using namespace std;

vector<int>::iterator it;

vector<int> Ts::init(int bits){
	vector<int> vec;
    vec.assign(bits,0); 
    for(it = vec.begin(); it != vec.end(); it++){
		*it = rand() % 2;
	}

    return vec;
}

int Ts::transition(vector<int> &vec, int bits){
    int index = rand() % bits;
	vec[index] = !vec[index];

    return index;
}

int Ts::evaluation(vector<int> &vec){
    int count = 0;
    for(it = vec.begin(); it != vec.end(); it++){
		if(*it == 1){
			 count++;
		}
	}

    return count;
}

void Ts::determination(vector<int> &vec, int count, int index, int &max){
    for(it = vec.begin(); it != vec.end(); it++){
		cout << *it;
	}
    if(max <= count){
		max = count;
		cout << "  Count: " << count << "  Max: " << max << "   New solution" << endl;
	}else{
		vec[index] = !vec[index];
		cout << "  Count: " << count << "  Max: " << max << "   Not new solution" << endl;
    }
}

bool Ts::checkqueue(vector<int> &vec, vector<vector<int> > &history){
    for(int i = 0; i < history.size(); i++){
        for(int j = 0; j < history[i].size(); j++){
            if(vec[j] != history[i][j]){
                return false;
            }
            
        }
    }
    return true;
}

void Ts::popqueue(vector<int> &vec, vector<vector<int> > &history, int queuesize){
    history.push_back(vec);
    //cout << "Histroy size: " << history.size();
    if(history.size() - 1 == queuesize){
        history.erase( history.begin( ) );
    }
}