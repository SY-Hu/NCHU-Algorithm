#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>
#include<fstream>

#include "Hc.h"

using namespace std;

int main(int argc, char *argv[]){
	int bits = stoi(argv[1]);
    int iter = stoi(argv[2]);
    int run = stoi(argv[3]);

	time_t start, end;
	srand (time(NULL));

    Hc hc1;
	start = time(NULL);
    fstream fp;
    fp.open("Output.csv", ios::out);
    fp<< "Iteration" << "," << "Value" << endl;
    fp.close();
    for(int j = 0; j <= iter; j+=10){ 
        vector<int> avg;
        for(int i = 0; i < run; i++){
            int cost = 0, index = 0, count = 0, max = 0;
            vector<int> vec = hc1.init(bits);
            while (cost <= j){
                if(cost != 0 ){
                    index = hc1.transition(vec, bits);
                }
                count = hc1.evaluation(vec);
                hc1.determination(vec, count, index, max);

                cost++;
	        }
            //cout << "Cost:  " << cost << endl;
            avg.push_back(max);
        }
        
        int sum = 0;
        for(auto it = avg.begin(); it != avg.end(); it++){
            sum += *it;
        }
        end = time(NULL);
        double diff = difftime(end, start);

	    //cout << "Time:  " << diff << " sec" << endl;
        fstream fp;
        fp.open("Output.csv", ios::out|ios::app);
        fp<< j << "," << sum/run << endl;
        fp.close();
        cout <<"Iter: " << j << "  AvgMax: " << sum/run << endl;
    
    }
    
    
	
	
	
} 
