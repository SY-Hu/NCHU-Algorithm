#include <vector>
using namespace std;

class Ga{
    private:

    public:
    vector<int> init(int);
    void initset(vector<vector<int> >&, vector<int>);
    vector<int> fitness(vector<vector<int>>);
    vector<vector<int> > selection(vector<vector<int>>, vector<int>);
    vector<vector<int> > crossover(vector<vector<int>>, int);
    void mutation(vector<vector<int>>&, int, double);
    void determination(vector<vector<int>>, int&);
};