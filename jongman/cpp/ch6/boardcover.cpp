#include <iostream>
#include <string>

using namespace std;

char table[20][20];
int t, n, m;
char blocks[4][2][2] = {
    {{0, 1}, {1, 0}},
    {{0, 1}, {1, 1}},
    {{1, 0}, {1, -1}},
    {{1, 0}, {1, 1}}
};

int routine() {
    int y = n, x = m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (table[i][j]=='.') {
                y = i;
                x = j;
                i = n;
                j = m;
            }
    
    if (y==n && x==m) return 1;
    table[y][x] = '#';

    int ret = 0;
    int ny, nx;
    bool f;
    for (int i=0; i<4; ++i) {
        f = true;
        for (int j=0; j<2; ++j) {
            ny = y+blocks[i][j][0];
            nx = x+blocks[i][j][1];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || table[ny][nx]=='#') {
                f = false;
                break;
            }
        }
        if (f) {
            for (int j=0; j<2; ++j) {
                ny = y+blocks[i][j][0];
                nx = x+blocks[i][j][1];
                table[ny][nx] = '#';
            }
            ret += routine();
            for (int j=0; j<2; ++j) {
                ny = y+blocks[i][j][0];
                nx = x+blocks[i][j][1];
                table[ny][nx] = '.';
            }
        }
    }
    table[y][x] = '.';
    return ret;
}

int main() {
    string line;
    cin >> t;
    for (int iter=0; iter<t; ++iter) {
        cin >> n >> m;
        for (int i=0; i<n; ++i) {
            cin >> table[i];
        }

        cout << routine() << endl;
    }
}