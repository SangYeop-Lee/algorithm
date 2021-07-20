#include <iostream>

using namespace std;

int t, n, d[200000];
int cache[200000];

int direction(int a, int b) {
    if (a-b < 0)
        return -1;
    if (a-b > 0)
        return 1;
    return 0;
};

bool check(int i) {
    return direction(d[i], d[i-1]) * direction(d[i-1], d[i-2]) < 0;
};

int solve() {
    if (n == 1) return 1;

    int ans = 2*n - 1;

    for (int i=2; i<n; ++i) {
        ans += cache[i] = check(i);
    }
    int mind, maxd;
    for (int i=3; i<n; ++i) {
        mind = min(d[i-1], d[i-2]);
        maxd = max(d[i-1], d[i-2]);
        ans += cache[i-1] && cache[i] &&
            d[i-3] > mind && d[i] > mind &&
            d[i-3] < maxd && d[i] < maxd;
    }
    return ans;
};

int main(void) {
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n;
        for (int j=0; j<n; ++j) {
            cin >> d[j];
        }
        fill(cache, cache+n, 0);
        cout << solve() << endl;;
    }
}