#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>

#include "Ts.h"

using namespace std;

int main(int argc, char *argv[]){
	int bits = stoi(argv[1]);
    int iter = stoi(argv[2]);
    int size = 10;
    int cost = 0, index = 0, count = 0, max = 0;
	time_t start, end;
	srand (time(NULL));

    Ts ts1;
	start = time(NULL);

    vector<int> vec = ts1.init(bits);
    vector<vector<int> > history;
    ts1.popqueue(vec, history, size);

	while (iter > 0){
        if(cost != 0 ){
            index = ts1.transition(vec, bits);
        }else{
            count = ts1.evaluation(vec);
            ts1.determination(vec, count, index, max);

            iter--;
            cost++;
        }
        if(!ts1.checkqueue(vec, history)){
            ts1.popqueue(vec, history, size);
            count = ts1.evaluation(vec);
            ts1.determination(vec, count, index, max);

            iter--;
            cost++;
        }
        
	}

    cout << "Queue :" <<endl;
    for(int i = 0; i < history.size(); i++){
        for(int j = 0; j < history[i].size(); j++){
            cout << history[i][j];           
        }
        cout <<endl;
    }
	end = time(NULL);

	double diff = difftime(end, start);

	cout << "Time:  " << diff << " sec" << endl;
	cout << "Cost:  " << cost << endl;
} 
