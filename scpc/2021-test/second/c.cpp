#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k;
long long int ans;

long long int px[600][601]; // n, n+1
long long int py[600][601]; // n, n+1
long long int acc[1300];

// x and y are zero index
// y = 3, x = 3, h = 3 => py[x+1][y+h] - py[x+1][y-h+1] + dx(x+1, y, h-1)

long long int getPx(int x, int y1, int y2) { // y1 > y2
    if (x<0 || x>=n || y1 < 0 || y2 >= 600)
        return 0;
    return px[x][min(y1, n)] - px[x][max(y2, 0)];
};

long long int getPy(int x, int y1, int y2) { // y1 > y2
    if (x<0 || x>=n || y1 < 0 || y2 >= 600)
        return 0;
    return py[x][min(y1, n)] - py[x][max(y2, 0)];
};

// return value is plus
long long int mdx(int x, int y, int h) {
    long long int ret = 0;
    for (int i = h; i>0; --i) {
        ret += getPy(x+i-h, y+i, y-i+1);
    }
    return ret;
};

long long int pdx(int x, int y, int h) {
    long long int ret = 0;
    for (int i = h; i>0; --i) {
        ret += getPy(x+1+h-i, y+i, y-i+1);
    }
    return ret;
};

long long int mdy(int x, int y, int h) {
    long long int ret = 0;
    for (int i = h; i>0; --i) {
        ret += getPx(y+i-h, x+i, x-i+1);
    }
    return ret;
};

long long int pdy(int x, int y, int h) {
    long long int ret = 0;
    for (int i = h; i>0; --i) {
        ret += getPx(y+1+h-i, x+i, x-i+1);
    }
    return ret;
};

long long int dx(int x, int y) {
    return pdx(x, y, k) - mdx(x, y, k);
};
long long int dy(int x, int y) {
    return pdy(x, y, k) - mdy(x, y, k);
};

// -k ~ n+k-2
void search() {
    const int iter = n+2*k-1;
    acc[0] = 0;
    ans = 0;
    for (int i=1; i<iter; ++i) {
        acc[i] = acc[i-1]+dx(-k-1+i, -k);
        ans = max(acc[i], ans);
    }
    for (int x=0; x<iter; ++x) {
        for (int y=1; y<iter; ++y) {
            acc[x] += dy(-k+x, -k+y-1);
            ans = max(acc[x], ans);
        }
    }
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<600; ++i) {
        px[i][0] = 0;
        py[i][0] = 0;
    }
    for (int zz=0; zz<c; ++zz) {
        ans = 0;
        cin >> n >> k;
        // px[0][0] ~ px[n-1][n]
        long long int tmp;
        for (int y=0; y<n; ++y) {
            for (int x=0; x<n; ++x) {
                cin >> tmp;
                px[y][x+1] = px[y][x] + tmp;
                py[x][y+1] = py[x][y] + tmp;
            }
        }
        search();
        cout << "Case #" << zz+1 << endl;
        cout << ans << endl;
    }
}
// 3 1 1 3 2 2 -2 3 4 -1 2 2 -2 -2 -2 -2