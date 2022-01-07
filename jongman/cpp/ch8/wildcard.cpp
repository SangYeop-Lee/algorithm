#include <iostream>
#include <string>
#include <vector>

using namespace std;

string pattern;
string target;
int cache[101][101];


int match(int p, int t) {
    int& ret = cache[p][t];
    if (ret!=-1)
        return ret;

    while (pattern[p]!='*'&&p<pattern.size()) {
        if (pattern[p]=='?' || pattern[p]==target[t]) {
            p++;
            t++;
        } else
            return (ret=0);
    }
    if (p==pattern.size()) {
        if (t==target.size())
            return (ret=1);
        else
            return (ret=0);
    }
    p++;
    if (p==pattern.size())
        return (ret=1);
    for (int tmp = t; tmp<target.size(); tmp++) {
        if (match(p, tmp))
            return (ret=1);
    }
    return (ret=0);
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> pattern;
        vector<string> Answer;
        int caseN;
        cin >> caseN;
        
        for (int j=0; j<caseN; ++j) {
            cin >> target;
            for (int x=0; x<101; ++x)
                for (int y=0; y<101; ++y)
                    cache[x][y] = -1;
            if (match(0, 0))
                Answer.push_back(target);
        }
        for (auto j = Answer.begin(); j<Answer.end(); ++j) {
            cout << *j << endl;
        }
    }
}