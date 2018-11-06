#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>

#include "Sa.h"

using namespace std;

int main(int argc, char *argv[]){
	int bits = stoi(argv[1]);
    int iter = stoi(argv[2]);
    int cost = 0, index = 0, count = 0, max = 0;
    double temperature = 100.0;
	time_t start, end;
	srand (time(NULL));

    Sa sa1;
	start = time(NULL);

    vector<int> vec = sa1.init(bits);

	while (iter > 0){
        if(cost != 0 ){
            index = sa1.transition(vec, bits);
        }
        count = sa1.evaluation(vec);
        sa1.determination(vec, count, index, max, temperature);

        iter--;
        cost++;
	}
	end = time(NULL);

	double diff = difftime(end, start);

	cout << "Time:  " << diff << " sec" << endl;
	cout << "Cost:  " << cost << endl;
} 