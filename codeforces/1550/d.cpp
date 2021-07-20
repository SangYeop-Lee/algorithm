#include <iostream>

using namespace std;

#define MOD 1000000007

int t, n, l, r;

int C(int n, int r) {
    if (n==r || r==0)
        return 1;
    else
        return (C(n-1, r-1) + C(n-1, r)) % MOD;
};

int solve() {
    // for diff d
        // range minus is possible [l + d ~ n] // n-1-l-d
        // range plus is possible [1 ~ r - d] // r-d
        // 공통된 부분에서 몇 개를 선택할 것인가. [l+d ~ r-d] C (필수 선택 수)
    int d = 1;
    int ans = 0;
    int half = n/2;
    // even: n, n+1 (2n)
    // odd : n, n+1 or n+1, n+2 (2n+1)
    while (
        l+d <= r-d &&
        n-1-l-d >= half && r-d >= half
    ) {
        int lb = l+d <= 1 ? 1 : l+d,
        ub = r-d >= n ? n : r-d;
        int range = ub - lb + 1;
        ans += C(range, half-lb+1);
        if (n%2 && ub > half) 
            ans += C(range, half-lb+2);
        d ++;
    }
    return ans % MOD;
};

int main(void) {
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n >> l >> r;
        cout << solve() << endl;
    }
}