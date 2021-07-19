#include <iostream>
#include <cmath>
#include <algorithm>

#define eps 0.000005

using namespace std;

int num[100];
int n, s;
int cache[100][11];

int qerr(int idx, int len) {
    if (len == 1) return 0;
    int sum = 0;
    int square = 0;
    for (int i=idx; i<idx+len; ++i) {
        sum += num[i];
        square += num[i]*num[i];
    }
    int m = round((float)sum/len);
    return len*m*m - 2*sum*m + square + eps;
};

int solve(int idx, int sep) {
    int& ret = cache[idx][sep];
    if (n-idx <= sep) return 0;
    if (ret != -1) return ret;
    --sep;
    if (sep==0)
        return ret = qerr(idx, n-idx);
    
    ret = 987654321;
    for (int i=1; i<n-idx; ++i) {
        ret = min(ret, solve(idx+i, sep) + qerr(idx, i));
    }
    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> s;
        for (int j=0; j<n; ++j)
            for (int k=0; k<s+1; ++k)
                cache[j][k] = -1;
        for (int j=0; j<n; ++j)
            cin >> num[j];
        sort(num, num+n);

        cout << solve(0, s) << endl;
    }
}
// 2 10 3 3 3 3 1 2 3 2 2 2 1 9 3 1 744 755 4 897 902 890 6 777