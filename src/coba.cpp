#include <iostream>

#include <vector>
using namespace std;

int main(){
    vector <float> abc = vector<float>(14,0);
    abc.push_back(44.5);
    cout << abc.size() << " " << abc[0] << endl;
    abc.resize(4);
    cout << abc.size() << " " << abc[0] << endl;
    return 0;
}