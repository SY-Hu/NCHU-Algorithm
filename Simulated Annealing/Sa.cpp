#include <iostream>
#include <cstdlib> 
#include <cmath>

#include "Sa.h"

using namespace std;

vector<int>::iterator it;

vector<int> Sa::init(int bits){
	vector<int> vec;
    vec.assign(bits,0); 
    for(it = vec.begin(); it != vec.end(); it++){
		*it = rand() % 2;
	}

    return vec;
}

int Sa::transition(vector<int> &vec, int bits){
    int index = rand() % bits;
	vec[index] = !vec[index];

    return index;
}

int Sa::evaluation(vector<int> &vec){
    int count = 0;
    for(it = vec.begin(); it != vec.end(); it++){
		if(*it == 1){
			 count++;
		}
	}

    return count;
}

void Sa::determination(vector<int> &vec, int count, int index, int &max, double &temperature){
    double pa = 0.0;
    for(it = vec.begin(); it != vec.end(); it++){
		cout << *it;
	}
    cout << endl;
    pa = exp( (count - max ) / temperature) ;
    double r = (double) rand() / (RAND_MAX + 1.0);
    cout << "Pa: " << pa << "  Temperature: " << temperature << "  Random: " << r;
    if(max <= count){
		max = count;
		cout << "  Count: " << count << "  Max: " << max << "   New solution" << endl;
	}else{
		if(pa > r){
			cout << "  Count: " << count << "  Max: " << max << "   New not best answer" << endl;
            max = count;
        }else{
            vec[index] = !vec[index];
			cout << "  Count: " << count << "  Max: " << max << "   Not new best answer" << endl;
        }
    }

    temperature *= 0.9;
}
