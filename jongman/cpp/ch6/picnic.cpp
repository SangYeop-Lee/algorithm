#include <iostream>
#include <vector>

using namespace std;

// input
// 3
// 2 1
// 0 1
// 4 6
// 0 1 1 2 2 3 3 0 0 2 1 3
// 6 10
// 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

int cases, n, m, fs[10][10];
int hp[10] = {0};
int res;
vector<int> results;

void find_partner(int index) {
    if (index == n) {
        ++res;
        return;
    }
    if (hp[index]) {
        find_partner(index+1);
        return;
    }
    hp[index] = 1;
    for (int i=index+1; i<n; ++i) {
        if (!hp[i] && fs[index][i]) {
            hp[i] = 1;
            find_partner(index+1);
            hp[i] = 0;
        }
    }
    hp[index] = 0;
}

void solve() {
    // memset(hp, 0, 10*sizeof(int));
    find_partner(0);
    results.push_back(res);
};

int main() {
    cin >> cases;
    for (int i=0; i<cases; ++i) {
        memset(fs, 0, sizeof fs);
        res = 0;
        cin >> n >> m;
        for (int j=0; j<m; ++j) {
            int x, y;
            cin >> x >> y;
            fs[x][y] = fs[y][x] = 1;
        }
        solve();
    }
    for (int i=0; i<cases; ++i) {
        cout << results[i] << endl;
    }
}