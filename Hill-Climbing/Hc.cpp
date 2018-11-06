#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>

#include "Hc.h"

using namespace std;

vector<int>::iterator it;

vector<int> Hc::init(int bits){
	vector<int> vec;
    vec.assign(bits,0); 
    for(int i = 0; i < bits; i++){
		vec[i] = rand() % 2;
	}

    return vec;
}

int Hc::transition(vector<int> &vec, int bits){
    int index = rand() % bits;
	vec[index] = !vec[index];

    return index;
}

int Hc::evaluation(vector<int> &vec){
    int count = 0;
    for(it = vec.begin(); it != vec.end(); it++){
		if(*it == 1){
			 count++;
		}
	}

    return count;
}

void Hc::determination(vector<int> &vec, int count, int index, int &max){
    /*for(it = vec.begin(); it != vec.end(); it++){
		cout << *it;
	}*/
    if(max <= count){
		max = count;
		//cout << "  Count: " << count << "  Max: " << max << "   New solution" << endl;
	}else{
		vec[index] = !vec[index];
		//cout << "  Count: " << count << "  Max: " << max << "   Not new solution" << endl;
    }
}

