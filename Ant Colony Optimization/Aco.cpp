#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "Aco.h"

using namespace std;

vector<int>::iterator it;

int Aco::selectpoint(vector<vector<double>> map, vector<vector<double>> pheromone, vector<int> &unpoint, int a, int alpha, int beta)
{
    double sum = 0.0;
    vector<double> temp;
    vector<double> prob;
    for (int i = 1; i < unpoint.size(); i++)
    {
        temp.push_back((double)((double)pow(pheromone[a][unpoint[i] - 1], alpha) * (double)pow(1 / map[a][unpoint[i] - 1], beta)));
        sum += temp[i - 1];
    }
    //cout << "Sum : " << sum << endl;
    /*for(int i = 0; i < temp.size(); i++){
        cout << i << " " << temp[i] << endl;
    }
    cout << temp.size();*/

    for (int i = 0; i < temp.size(); i++)
    {
        prob.push_back((double)temp[i] / sum);
        //cout << prob[i] << endl;
    }

    //cout << "Prob: " << endl;
    /*for(int i = 1; i < prob.size(); i++){
        prob[i] = prob[i] + prob[i-1];
        //cout << prob[i] << " ";
    }*/
    //cout << endl;

    //int returnpoint;

    double r = (double)rand() / (RAND_MAX + 1.0);
    /*for(int j = 0; j < prob.size(); j++){
        if(j == 0){
            if(prob[j] >= r && r > 0){
                //cout << unpoint[j] << endl;
                returnpoint =  unpoint[j+1];
            }
        }else if(prob[j-1] < r && r <= prob[j]){
            //cout << unpoint[j] << endl;
            returnpoint =  unpoint[j+1];
        }
    }
    return returnpoint;*/

    double cfTotal = 0.0;
    int returnpoint;

    for (int i = 0; i < prob.size(); i++)
    {

        cfTotal += prob[i];
        //cout << cfTotal;

        if (cfTotal > r)
        {
            //cout << "LLLLLLLL";
            returnpoint = unpoint[i + 1];
            break;
        }
    }
    return returnpoint;
}

void Aco::localpheromone(vector<vector<double>> map, vector<vector<int>> antmap, vector<vector<double>> &localpheromone, int Q)
{
    for (int i = 0; i < antmap.size(); i++)
    {
        double sum = 0;
        for (int j = 1; j < antmap[i].size(); j++)
        {
            sum += map[antmap[i][j - 1] - 1][antmap[i][j] - 1];
            /*localpheromone[antmap[i][j-1]-1][antmap[i][j]-1] = (double)Q / sum;
            localpheromone[antmap[i][j]-1][antmap[i][j-1]-1] = localpheromone[antmap[i][j-1]-1][antmap[i][j]-1];
            //cout << localpheromone[antmap[i][j]-1][antmap[i][j-1]-1] << " ";*/
        }
        for (int j = 1; j < antmap[i].size(); j++)
        {
            localpheromone[antmap[i][j - 1] - 1][antmap[i][j] - 1] += (double)Q / sum;
            localpheromone[antmap[i][j]-1][antmap[i][j-1]-1] = localpheromone[antmap[i][j-1]-1][antmap[i][j]-1];
            //cout << localpheromone[antmap[i][j]-1][antmap[i][j-1]-1] << " ";
        }
        //cout <<"HHHH" << endl;
    }
}

void Aco::updatepheromone(vector<vector<double>> &pheromone, vector<vector<double>> localpheromone)
{
    double f = 0.9;
    for (int i = 0; i < localpheromone.size(); i++)
    {
        for (int j = 0; j < localpheromone[i].size(); j++)
        {
            pheromone[i][j] = (double)(f * pheromone[i][j]) + localpheromone[i][j];
            //cout << pheromone[i][j] << " ";
        }
    }
}
