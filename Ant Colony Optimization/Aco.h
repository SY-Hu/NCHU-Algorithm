#include <vector>
using namespace std;

class Aco{
    private:

    public:
    vector<int> init(int);
    int selectpoint(vector<vector<double> >, vector<vector<double> >, vector<int>&, int, int, int);
    void localpheromone(vector<vector<double> >, vector<vector<int> >, vector<vector<double> > &, int);
    void updatepheromone(vector<vector<double> >&, vector<vector<double> >);
    int evaluation(vector<int>&);
    void determination(vector<int>&, int, int, int&);
};