#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>

#include "Ga.h"

using namespace std;

vector<int> Ga::init(int bits){
	vector<int> vec;
    vec.assign(bits,0); 
    for(int i = 0; i < bits; i++){
		vec[i] = rand() % 2;
	}

    return vec;
}

void Ga::initset(vector<vector<int> >& vecset, vector<int> vec){
    vecset.push_back(vec);

}

vector<int> Ga::fitness(vector<vector<int>> vecset){
    vector<int> vec;
    for(int i = 0; i < vecset.size(); i++){
        int count = 0;
        for(int j = 0; j < vecset[i].size(); j++){
            if(vecset[i][j] == 1){
                count++;
            }
            
        }
        //cout << "Count: " << count;
        vec.push_back(count);
    }

    return vec;
}

vector<vector<int> > Ga::selection(vector<vector<int>> vecset, vector<int> vec){
    vector<vector<int>> temp;
    vector<double> prob;
    int sum = 0;
    
    for(auto it = vec.begin(); it != vec.end(); it++){
        sum += *it;
    }
    //cout << "Sum: " << sum;
    /*for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it;
    }*/
    for(int i = 0; i < vec.size(); i++){
        //cout << vec[i] << " " << sum;
        double pro = (double)vec[i]/sum;
        //cout << "Pro: " << pro;
        prob.push_back(pro);
    }
    //cout << "Probsize: " << prob.size() << endl;
    /*for(int i = 0; i < prob.size(); i++){
        cout << prob[i];
    }*/
    for(int i = 1; i < prob.size(); i++){
        prob[i] = prob[i] + prob[i-1];
    }
    /*for(int i = 0; i < prob.size(); i++){
        cout << prob[i] << endl;
    }*/
    for(int i = 0; i < prob.size(); i++){
        double r = (double) rand() / (RAND_MAX + 1.0);
        for(int j = 0; j < prob.size(); j++){
            if(j == 0){
                if(prob[j] >= r && r > 0){
                    temp.push_back(vecset[j]);
                }
            }else if(prob[j-1] < r && r <= prob[j]){
                temp.push_back(vecset[j]);
            }
        }
    }
    /*cout << "Select: " << endl; 
    for(int i = 0; i < temp.size(); i++){
        int count = 0;
        for(int j = 0; j < temp[i].size(); j++){
            cout << temp[i][j];
        }
        cout << endl;
    }*/
    //cout << temp.size() << endl;
    return temp;
}

vector<vector<int> > Ga::crossover(vector<vector<int>> vecset, int bits){
    vector<vector<int>> temp;
    for(int i = 0; i < vecset.size(); i +=2){
        int index = rand() % bits;
        vector<int> chromosome_a;
        vector<int> chromosome_b;

        for(int j = 0; j < index; j++){
            chromosome_a.push_back(vecset[i][j]);
        }
        for(int j = index; j < vecset[i].size(); j++){
            chromosome_a.push_back(vecset[i+1][j]);
        }

        for(int j = 0; j < index; j++){
            chromosome_b.push_back(vecset[i+1][j]);
        }
        for(int j = index; j < vecset[i].size(); j++){
            chromosome_b.push_back(vecset[i][j]);
        }

        temp.push_back(chromosome_a);
        temp.push_back(chromosome_b);
    }

    /*cout << "Cross: " << endl; 
    for(int i = 0; i < temp.size(); i++){
        int count = 0;
        for(int j = 0; j < temp[i].size(); j++){
            cout << temp[i][j];
        }
        cout << endl;
    }*/

    return temp;

}

void Ga::mutation(vector<vector<int>>& vecset, int bits, double pm){

    for(int i = 0; i < vecset.size(); i++){
        double r = (double) rand() / (RAND_MAX + 1.0);
        if(r <= pm){
            int index = rand() % bits;
            vecset[i][index] = !vecset[i][index];
        }
    }
    /*cout << "Mutat: " << endl; 
    for(int i = 0; i < vecset.size(); i++){
        int count = 0;
        for(int j = 0; j < vecset[i].size(); j++){
            cout << vecset[i][j];
        }
        cout << endl;
    }*/
}

void Ga::determination(vector<vector<int>> vecset, int& max){
    //cout << "Dete: " ;
    for(int i = 0; i < vecset.size(); i++){
        int count = 0;
        for(int j = 0; j < vecset[i].size(); j++){
            if(vecset[i][j] == 1){
                count++;
            }
            //cout << vecset[i][j];
        }
        //cout << "Count: " << count << endl;
        if(count > max){
            max = count;
        }
        //cout << endl;
    }
    //cout << "Max: " << max << endl;
}
