#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef int Move;
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5

long long int n = 12;
const long long int nS = pow(3, n);
vector<string> hanoi(nS, "");

// index: 3^i => size: n-i
long long int s2i (vector<int>& s) {
    long long int ret = s[0];
    for (int i=1; i<n; ++i) {
        ret *= 3;
        ret += s[i];
    }
    return ret;
};

vector<int> i2s (long long int j) {
    vector<int> ret(n, 0);
    for (int i=n-1; i>=0; --i) {
        ret[i] = j%3;
        j /= 3;
    }
    return ret;
};

// void print(long long int i) {
//     vector<int> tmp = i2s(i);
//     for (int j=0; j<tmp.size(); ++j) {
//         cout << tmp[j];
//     }
//     cout << " : ";
// }

long long int validate(long long int ind, Move m) {
    vector<int> state = i2s(ind);
    
    vector<int> s[3];
    for (int i=0; i<n; ++i) {
        s[state[i]].push_back(i);
    }

    int from, to;
    switch(m) {
        case A: from = 0; to = 1; break;
        case B: from = 0; to = 2; break;
        case C: from = 1; to = 0; break;
        case D: from = 1; to = 2; break;
        case E: from = 2; to = 0; break;
        case F: from = 2; to = 1; break;
    }
    int fSize = s[from].size();
    int tSize = s[to].size();
    if (fSize == 0) {
        return -1;
    }
    int plate = s[from][fSize/2];
    if (tSize == 0 || (tSize == 1 && s[to][0] < plate) ||
        (tSize > 1 && s[to][(tSize-1)/2] < plate && s[to][(tSize-1)/2+1] > plate)) {
            state[plate] = to;
            long long int ret = s2i(state);
            if (hanoi[ret] != "") {
                // print(ret);
                // cout << hanoi[ret] << endl;
                if (hanoi[ret].back() == '\n') {
                    return -ret;
                }
                return -1;
            }
            return ret == 0 ? -1 : ret;
    }

    return -1;
};

char swapYZ(char a) {
    a -= 'A';
    switch(a) {
        case A: return 'B';
        case B: return 'A';
        case C: return 'E';
        case D: return 'F';
        case E: return 'C';
        case F: return 'D';
    }
};

char swapZYX(char a) {
    a -= 'A';
    switch(a) {
        case A: return 'D';
        case B: return 'B';
        case C: return 'F';
        case D: return 'A';
        case E: return 'E';
        case F: return 'C';
    }
};

char swapYZX(char a) {
    a -= 'A';
    switch(a) {
        case A: return 'B';
        case B: return 'D';
        case C: return 'E';
        case D: return 'C';
        case E: return 'F';
        case F: return 'A';
    }
};

void insert(long long int ind, string s) {
    hanoi[ind] = s;
    vector<int> state = i2s(ind);
    vector<int> sswapYZ = state;
    vector<int> ZYX = state;
    vector<int> YZX = state;
    for (int i=0; i<n; ++i) {
        if (state[i] == 2) {
            sswapYZ[i] = 1;
            ZYX[i] = 0;
            YZX[i] = 1;
        }
        if (state[i] == 1) {
            sswapYZ[i] = 2;
            YZX[i] = 0;
        }
        if (state[i] == 0) {
            ZYX[i] = 2;
            YZX[i] = 2;
        }
    }
    string sYZ = "";
    string sZYX = "";
    string sYZX = "";
    for (int i=0; i<s.size(); ++i) {
        sYZ += swapYZ(s[i]);
        sZYX += swapZYX(s[i]);
        sYZX += swapYZX(s[i]);
    }
    reverse(sZYX.begin(), sZYX.end());
    reverse(sYZX.begin(), sYZX.end());
    sZYX += '\n'; sYZX += '\n';
    hanoi[s2i(sswapYZ)] = sYZ;
    hanoi[s2i(ZYX)] = sZYX;
    hanoi[s2i(YZX)] = sYZX;
};

char m2a(Move a) {
    switch(a) {
        case A: return 'A';
        case B: return 'B';
        case C: return 'C';
        case D: return 'D';
        case E: return 'E';
        case F: return 'F';
    }
};

string search() {
    long long int begin = 0;

    queue<long long int> forward;
    forward.push(begin);
    while (!forward.empty()) {
        long long int here = forward.front();
        forward.pop();
        for (int i=A; i<=F; ++i) {
            long long int next = validate(here, i);
            if (next < -1) {
                return hanoi[here] + m2a(i) + hanoi[-next];
            }
            if (next != -1) {
                insert(next, hanoi[here]+m2a(i));
                forward.push(next);
            }
        }
    }
    return "";
};

int main(void) {
    int t, m;
    cin >> t >> m;

    cout << "Case #1" << endl << n << endl;
    cout << search();
}