#include <iostream>

int n, m;
int cache[101][101][2];
int a[101], b[101];

using namespace std;

int jlis(int left, int right, bool isLeft) {
    int &ret = cache[left][right][isLeft];
    if (ret != -1) return ret;

    int value = isLeft ? a[left] : b[right];
    ret = 1;
    for (int i=left; i<=n; ++i)
        if (a[i] > value)
            ret = max(ret, 1 + jlis(i, right, true));

    for (int j=right; j<=m; ++j)
        if (b[j] > value)
            ret = max(ret, 1 + jlis(left, j, false));

    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> m;
        ++n; ++m;
        for (int j=0; j<n; ++j)
            for (int k=0; k<m; ++k) {
                cache[j][k][0] = -1;
                cache[j][k][1] = -1;
            }
        a[0] = b[0] = -1;
        for (int j=1; j<n; ++j)
            cin >> a[j];
        for (int j=1; j<m; ++j)
            cin >> b[j];
        a[n] = b[m] = -1;
        cout << (jlis(0, 0, true) - 1) << endl;
    }
}
// 3 3 3 1 2 4 3 4 7 3 3 1 2 3 4 5 6 5 3 10 20 30 1 2 10 20 30