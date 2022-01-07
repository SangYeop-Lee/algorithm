#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, r[200], p[200];

int countFactor(int x, int r) {
    int ret = 0;
    while (x%r == 0) {
        ret ++;
        x /= r;
    }
    return ret;
};

int pow (int n, int r) {
    if (r==0)
        return 1;
    return n * pow(n, r-1);
};

int gcd(int a, int b) {
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int main(void) {
    int c; 
    cin >> c;
    for (int z=0; z<c; ++z) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> r[i];
        }
        int rgcd = r[0];
        for (int i=1; i<n; ++i) {
            rgcd = gcd(rgcd, r[i]);
        }
        for (int i=0; i<n; ++i) {
            r[i] /= rgcd;
        }

        int target = 1;
        for (int i=0; i<n; ++i) {
            cin >> p[i];
            target = max(target, (p[i]+r[i]-1)/r[i]);
        }

        for (int i=0; i<n; ++i) {
            cout << r[i]*target-p[i] << ' ';
        }
        cout << endl;
    }
}
// 3 4 4 6 2 4 6 4 2 4 4 4 6 2 4 7 4 2 4 3 4 5 6 1 2 3