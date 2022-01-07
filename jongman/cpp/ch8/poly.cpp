#include <iostream>

#define remainder 10000000

using namespace std;

int n;
int cache[102][102]; // bsize, width;

int memo(int b, int w) {
    int& ret = cache[b][w];
    if (ret != -1) return ret;
    if (b == w) return ret = 1;

    ret = 0;
    b -= w;
    for (int i=1; i<=b; ++i) {
        int tmp = (w+i-1) * memo(b, i);
        tmp %= remainder;
        ret += tmp;
        ret %= remainder;
    }

    return ret;
};

int solve() {
    memo(n+1, 1);
    int ret = 0;
    for (int i=1; i<=n; ++i) {
        ret += memo(n, i);
        ret %= remainder;
    }

    return ret;
};

int main(void) {
    for (int j=0; j<102; ++j)
        for (int k=0; k<102; ++k)
            cache[j][k] = -1;

    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        cout << solve() << endl;
    }
}