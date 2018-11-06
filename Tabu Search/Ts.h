#include <vector>
using namespace std;

class Ts{
    private:

    public:
    vector<int> init(int);
    int transition(vector<int>&, int);
    int evaluation(vector<int>&);
    void determination(vector<int>&, int, int, int&);
    bool checkqueue(vector<int>&, vector<vector<int> >&);
    void popqueue(vector<int>&, vector<vector<int> >&, int);
};