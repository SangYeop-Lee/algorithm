#include <iostream>

#define remainder 1000000007

int n;
int cache[100] = {1, 1};

using namespace std;

int countAll(int len) {
    int& ret = cache[len];
    if (ret != -1) return ret;
    return ret = (countAll(len-1) + countAll(len-2))%remainder;
};

int solve() {
    int ret = countAll(n);

    ret -= cache[n/2];

    if (!(n%2))
        ret -= cache[n/2-1];

    while (ret<0)
        ret += remainder;

    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        for (int j=2; j<=n; ++j)
            cache[j] = -1;
        cout << solve() << endl;
    }
}

// 3 2 4 92