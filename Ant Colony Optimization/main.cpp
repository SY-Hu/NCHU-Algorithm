#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>

#include "Aco.h"

using namespace std;

int main(int argc, char *argv[])
{
    int ant = stoi(argv[1]);
    int iter = stoi(argv[2]);
    int run = stoi(argv[3]);
    int h = 0;
    while (h < run)
    {
        vector<vector<int>> eil51;
        vector<int> eiline;
        vector<int> x;
        vector<int> y;
        int filesize = 51;

        time_t start, end;
        srand(time(NULL));

        start = time(NULL);
        ifstream fp;
        fp.open("eil51.tsp.txt");
        if (!fp)
        {
            cout << "Cannot Open\n";
        }
        for (int i = 0; i < filesize; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                int temp;
                fp >> temp;
                eiline.push_back(temp);
            }
            eil51.push_back(eiline);
            eiline.clear();
        }

        fp.close();

        /*for(int i = 0; i < filesize; i++){
        for(int k = 0; k < 3; k++){ 
            cout << eil51[i][k] << " "; 
        }
        cout << endl;
    }*/

        for (int i = 0; i < filesize; i++)
        {
            x.push_back(eil51[i][1]);
            y.push_back(eil51[i][2]);
        }

        /*for(int i = 0; i < x.size(); i++){
        cout << x[i] << " " << y[i] << endl;
    }*/

        /*double map [x.size()][y.size()] = {0};
    double pheromone [x.size()][y.size()] = {1};*/
        vector<vector<double>> map;
        vector<vector<double>> pheromone;

        for (int i = 0; i < x.size(); i++)
        {
            vector<double> temp;
            for (int j = 0; j < y.size(); j++)
            {
                temp.push_back(0);
            }
            map.push_back(temp);
        }

        for (int i = 0; i < x.size(); i++)
        {
            vector<double> temp;
            for (int j = 0; j < y.size(); j++)
            {
                temp.push_back(1);
            }
            pheromone.push_back(temp);
        }

        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < y.size(); j++)
            {
                if (i == j)
                {
                    map[i][j] = 0.0;
                }
                else
                {
                    map[i][j] = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
                }
            }
        }

        /*for(int i = 0; i < x.size(); i++){
        for(int j = 0; j < y.size(); j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }*/
        Aco aco1;

        double ph, alpha, beta;
        int n = 0;
        double min = 1000;
        vector<int> sol;
        while (n < iter)
        {

            vector<vector<int>> antmap;

            for (int w = 0; w < ant; w++)
            {
                vector<int> unpoint;
                for (int i = 0; i < filesize; i++)
                {
                    unpoint.push_back(i + 1);
                }

                int pointtemp = 0;
                pointtemp = unpoint[0];
                unpoint[0] = unpoint[w];
                unpoint[w] = pointtemp;

                /*for(int i = 0; i < unpoint.size(); i++){
        cout << unpoint[i] << " ";
        }
        cout << endl;*/
                vector<int> point;
                point.push_back(unpoint[0]);

                for (int i = 0; i < filesize - 1; i++)
                {
                    //cout << "Point : " << point[i] << endl;
                    point.push_back(aco1.selectpoint(map, pheromone, unpoint, point[i] - 1, 1, 2));
                    for (int j = 0; j < unpoint.size(); j++)
                    {
                        if (point[i + 1] == unpoint[j])
                        {
                            unpoint.erase(unpoint.begin() + j);
                            //cout << "Size: " << unpoint.size();
                        }
                    }
                }
                point.push_back(unpoint[0]);
                antmap.push_back(point);

                /*for(int i = 0; i < unpoint.size(); i++){
        cout << unpoint[i] << " ";
        }*/

                /*if (n > 800)
            {
                for (int i = 0; i < point.size(); i++)
                {
                    cout << point[i] << " ";
                }
            }*/
                /*for (int i = 0; i < point.size(); i++)
            {
                cout << point[i] << " ";
            }*/
                //cout << "Size : " << point.size();
                double dist = 0.0;

                for (int i = 1; i < point.size(); i++)
                {
                    dist += map[point[i - 1] - 1][point[i] - 1];
                }
                //cout << dist << endl;

                if (dist < min)
                {
                    min = dist;
                    vector<int> best;

                    for (int i = 0; i < point.size(); i++)
                    {
                        best.push_back(point[i]);
                        //cout << best[i];
                    }
                    sol = best;
                }
            }

            if (n == iter - 1)
            {
                cout << n << "-----------------------------------" << endl;
                cout << "BEST : ";
                for (int i = 0; i < sol.size(); i++)
                {
                    cout << sol[i] << " ";
                }

                cout << "dist : " << min << endl;
            }

            vector<vector<double>> localpheromone;

            for (int i = 0; i < map.size(); i++)
            {
                vector<double> temp;
                for (int j = 0; j < map[i].size(); j++)
                {
                    temp.push_back(0.0);
                }
                localpheromone.push_back(temp);
            }

            aco1.localpheromone(map, antmap, localpheromone, 100);
            aco1.updatepheromone(pheromone, localpheromone);

            n++;
        }
        h++;
    }
}
