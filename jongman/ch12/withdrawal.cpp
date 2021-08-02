#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int c[1000], r[1000];
double xs[1000];

double solve() {
    double hi = 1, lo = 0;
    for (int i=0; i<100; ++i) {
        double x = (hi+lo) / 2;
        for (int j=0; j<n; ++j) {
            xs[j] = c[j]*x - r[j];
        }
        sort(xs, xs+n, greater<double>());
        double sum = 0;
        for (int j=0; j<k; ++j) {
            sum += xs[j];
        }
        if (sum >= 0)
            hi = x;
        else
            lo = x;
    }

    return hi;
};

int main(void) {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n >> k;
        for (int j=0; j<n; ++j) {
            cin >> r[j] >> c[j];
        }
        cout << solve() << endl;
    }
}

// 3 3 2 1 4 6 10 10 17 4 2 4 8 9 12 3 10 2 5 10 5 70 180 192 192 1 20 10 200 6 102 60 1000 4 9 1 12 8 127 100 700