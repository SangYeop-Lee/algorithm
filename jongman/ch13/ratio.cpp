#include <iostream>

using namespace std;

long long int n, m;

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> m;
        long long int p = 100 * m / n;
        if (p > 98) {
            cout << -1 << endl;
            continue;
        }
        long long int x = (p+1)*n - 100*m;
        long long int tmp = x;
        x /= (99-p);
        if (tmp%(99-p) != 0) ++x;
        cout << x << endl;
    }
}

// 5 10 8 100 80 47 47 99000 0 1000000000 470000000