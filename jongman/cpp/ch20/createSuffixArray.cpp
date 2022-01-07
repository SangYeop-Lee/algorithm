#include <iostream>
#include <string>

using namespace std;

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {
        group = _group; t = _t;
    }
    bool operator() (int a, int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
}

int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    int res[n+1];
    for (int i=0; i<n; ++i) {
        res[i] = s[i];
    }
    res[n] =  -1;

    
    int t=1;
    while (t<n) {

    }
}