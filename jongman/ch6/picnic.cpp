#include <iostream>
#include <vector>

using namespace std;

int t, n, m, f1, f2;
bool friends[10][10];

int nextTarget(vector<bool> coupled) {
    for (int i=0; i<n; ++i)
        if (!coupled[i])
            return i;
    return n;
};

int routine(vector<bool> coupled) {
    int nT = nextTarget(coupled);
    if (nT==n) return 1;

    int ret = 0;
    coupled[nT] = true;
    for (int i=nT+1; i<n; ++i) {
        if (friends[nT][i]&&!coupled[i]) {
            coupled[i] = true;
            ret += routine(coupled);
            coupled[i] = false;
        }
    }
    return ret;
};

void solve() {
    vector<bool> coupled(n, false);
    cout << routine(coupled) << endl;
};

int main() {
    cin >> t;
    for (int iter=0; iter<t; ++iter) {
        cin >> n >> m;
        memset(friends, 0, 100);
        for (int i=0; i<m; ++i) {
            cin >> f1 >> f2;
            friends[f1][f2] = friends[f2][f1] = true;
        }
        solve();
    }
}