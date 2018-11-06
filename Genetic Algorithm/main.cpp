#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>
#include<fstream>

#include "Ga.h"

using namespace std;

int main(int argc, char *argv[]){
	int bits = stoi(argv[1]);
    int number = stoi(argv[2]);
    int iter = stoi(argv[3]);
    int run = stoi(argv[4]);
    double ps = 0.8, pm = 0.1;

	time_t start, end;
	srand (time(NULL));

    Ga ga1;
	start = time(NULL);
    fstream fp;
    fp.open("Output.csv", ios::out);
    fp<< "Iteration" << "," << "Value" << endl;
    fp.close();
    for(int j = 0; j <= iter; j+=10){ 
        vector<int> avg;
        for(int i = 0; i < run; i++){
            int cost = 0, index = 0, max = 0;
            vector<vector<int>> chromosome;
            for(int x = 0; x < number; x++){
                vector<int> vec = ga1.init(bits);
                ga1.initset(chromosome, vec);
            }
            
            while (cost <= j){
                vector<int> fit;
                if(cost != 0 ){
                    fit = ga1.fitness(chromosome);
                    chromosome = ga1.selection(chromosome, fit);
                    //cout << chromosome.size() << endl;
                    double r = (double) rand() / (RAND_MAX + 1.0);
                    if(r <= ps){
                        chromosome = ga1.crossover(chromosome, bits);
                        ga1.mutation(chromosome, bits, pm);
                    }
                }
                //cout << chromosome.size() << endl;
                ga1.determination(chromosome, max);
                //cout << "111" << endl;

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
    