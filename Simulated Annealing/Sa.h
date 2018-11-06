#include <vector>
using namespace std;

class Sa{
    private:

    public:
    vector<int> init(int);
    int transition(vector<int>&, int);
    int evaluation(vector<int>&);
    void determination(vector<int>&, int, int, int&, double&);
};