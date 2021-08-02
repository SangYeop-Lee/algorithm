#include <iostream>
#include <algorithm>

#define tMil 10000000

using namespace std;

int minFactor[tMil+1] = {};
int numMF[tMil+1] = {};
int factors[tMil+1] = {};

int countFactor(int x, int f) {
    int ret = 0;
    while (x%f == 0) {
        ++ ret;
        x /= f;
    }
    return ret;
};

int main(void) {
    minFactor[1] = 1;
    numMF[1] = 1;
    factors[1] = 1;
    for (int i=2; i<tMil+1; ++i) {
        if (minFactor[i] == 0) {
            for (int j=1, iter = tMil/i; j<=iter; ++j) {
                minFactor[j*i] = i;
                numMF[j*i] = countFactor(j*i, i);
            }
        }

        int prev = i/minFactor[i];
        if (minFactor[i] == i) {
            factors[i] = 2;
        } else if (numMF[i] == 1){
            factors[i] = factors[prev] * 2;
        } else {
            factors[i] = factors[prev] * (numMF[i]+1) / (numMF[prev]+1);
        }
    }

    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        int n, lo, hi;
        cin >> n >> lo >> hi;

        int ans = 0;
        for (int j=lo; j<=hi; ++j) {
            if (factors[j] == n) {
                ++ ans;
            }
        }
        cout << ans << endl;
    }
}
// 3 2 2 10 12 486 486 200 1000000 2000000