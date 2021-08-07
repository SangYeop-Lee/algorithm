#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Fenwick {
    vector<int> a;
    long long int res;
    Fenwick(int length) {
        a.resize(length+1);
        fill(a.begin(), a.end(), 0);
        res = length * (length-1) / 2;
    }
    void add(int n) {
        int m = n;
        while (m > 0) {
            res -= a[m];
            m &= (m-1);
        }
        while (n < a.size()) {
            ++ a[n];
            n += (n & -n);
        }
    }
    void ans() {
        cout << res << endl;
    }
};

int main(void) {
    int n, c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        cin >> n;
        int tmp;
        Fenwick f(n);
        for (int i=0; i<n; ++i) {
            cin >> tmp;
            f.add(tmp);
        }

        f.ans();
    }
}
// 2 5 5 1 4 3 2 10 7 8 6 6 1 9 4 4 3 10