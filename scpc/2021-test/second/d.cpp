#include <iostream>
#include <string>
#include <vector>

#define pmax 501

using namespace std;

int n, k, ans;
string s, p;
vector<int> traces;
vector<int> ptraces;
int lastAlpha[26];


void setTraces(string S, int sz, vector<int>& trace) {
    trace = vector<int> (sz, pmax);
    fill (lastAlpha, lastAlpha+26, -1);
    for (int i=0; i<sz; ++i) {
        int& index = lastAlpha[S[i]-'a'];
        if (index != -1) {
            trace[index] = min(pmax, i-index);
        }
        index = i;
    }
};

void setTable(int psz, vector<int>& ptraces, vector<int>& ptable) {
    ptable = vector<int> (psz+1, 0);
    ptable[0] = -1;
    for (int i=1; i<=psz; ++i) {
        for (int j=0; j+i<=psz; ++j) {
            if (ptraces[i+j] != ptraces[i]) {
                break;
            }
            ptable[j+i+1] = max(ptable[j+i+1], j+1);
        }
    }
    for (int i=0; i<psz; ++i) {
        cout << ptraces[i] << ' ';
    }cout << endl;
    for (int i=0; i<psz+1; ++i) {
        cout << ptable[i] << ' ';
    } cout << endl;
};

void solve(int mul) {
    int psz = p.size(); 
    vector<int> ptraces;
    vector<int> ptable;
    setTraces(p, psz, ptraces);
    setTable(psz, ptraces, ptable);
    int i, j;
    while (j<n-psz+1) {
        i=0;
        while (i<psz) {
            if (ptraces[i] == pmax || traces[j+i] == ptraces[i])
                ++i;
            else
                break;
        }
        if (i==psz) {
            ans += mul;
        }
        j += i-ptable[i];
    }
    // for (int j=0; j<n-psz+1; ++j) {
    //     for (int i=0; i<psz; ++i) {
    //         if (ptraces[i] != pmax && traces[j+i] != ptraces[i])
    //             break;
    //         if (i == psz-1)
    //             ans += mul;
    //     }
    // }
};

int main(void) {
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        cin >> n >> k;
        cin >> s;
        setTraces(s, n, traces);

        ans = 0;
        for (int i=0; i<k; ++i) {
            cin >> p;
            solve(i+1);
        }

        cout << "Case #" << zz+1 << endl;
        cout << ans << endl;
    }
}
// 3 9 1 dabacadab nxyxz 20 2 abracadabracadabraaa abracadabra aa 18 2 abracadabracadabra abracadabra a