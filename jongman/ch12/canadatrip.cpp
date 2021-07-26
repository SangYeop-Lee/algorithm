#include <iostream>

using namespace std;

int n, k;
int l[5000], m[5000], g[5000];
int dist;

bool isOverK(int dist) {
    int ret = 0;
    for (int i=0; i<n; ++i) {
        if (dist >= l[i]-m[i])
            ret += (min(dist, l[i]) - (l[i] - m[i]))/g[i] + 1;
    }
    return ret >= k;
};

int solve() {
    int lo = -1;
    int hi = 8030001;
    while (lo!=hi) {
        int dist = (hi+lo) / 2;
        if (isOverK(dist))
            hi = dist;
        else
            lo = dist+1;
    }

    return lo;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> k;
        for (int j=0; j<n; ++j) {
            cin >> l[j] >> m[j] >> g[j];
        }
        cout << solve() << endl;
    }
}
// 2 3 15 500 100 10 504 16 4 510 60 6 2 1234567 8030000 8030000 1 2 2 1