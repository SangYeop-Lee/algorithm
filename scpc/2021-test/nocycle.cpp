#include <iostream>
#include <string>

using namespace std;

int n, m, k;
int v[501][501];
int backup[2][501];
string ans;

void print() {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
};

void setV(int i, int j) {
    for (int k=1; k<=n; ++k) {
        backup[0][k] = v[i][k];
        backup[1][k] = v[k][j];
    }
    
    if (!v[i][j])
        v[i][j] = 1;
    for (int k=1; k<=n; ++k) {
        if (v[k][i])
            v[k][j] = 2;
        if (v[j][k])
            v[i][k] = 2;
    }
    for (int k=1; k<=n; ++k) {
        for (int kk=1; kk<=n; ++kk) {
            if (v[k][2] && v[3][kk])
                v[k][kk] = 2;
        }
    }
};

bool check(int x, int y) {
    for (int i=1; i<=n; ++i) {
        if ((v[x][i] && v[i][x] && v[x][i] + v[i][x] > 2) ||
        (v[i][y] && v[y][i] && v[i][y] + v[y][i] > 2))
            return true;
    }
    return false;
};

bool check2(int x, int y) {
    return v[y][x] != 2;
};

int main(void) {
    int c;
    cin >> c;
    for (int z=0; z<c; ++z) {
        cin >> n >> m >> k;
        ans = "";
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                v[i][j] = 0;
            }
        }
        int x, y;
        for (int i=0; i<m; ++i) {
            cin >> x >> y;
            setV(x, y);
            // print();
        }
        for (int i=0; i<k; ++i) {
            cin >> x >> y;
            if (check2(x, y)) {
                setV(x, y);
                ans += '0';
            } else {
                setV(y, x);
                ans += '1';
            }
            // print();
            // setV(x, y);
            // print();
            // if (check(x, y)) {
            //     ans += '1';
            //     for (int k=1; k<=n; ++k) {
            //         v[x][k] = backup[0][k];
            //         v[k][y] = backup[1][k];
            //     }
            //     setV(y, x);
            // } else {
            //     ans += '0';
            // }
        }
        cout << "Case #" << z+1 << endl;
        cout << ans << endl;
    }
}
// 2 3 3 1 1 2 2 3 1 3 3 1 4 2 2 1 2 3 4 2 3 4 1