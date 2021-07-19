#include <iostream>

using namespace std;

int n, k;
int a[3001], b[3001]; // 1 index
int psa[3001], psb[3001];
int lc[3001][3001], uc[3001][3001];
int l;

int checkLeft(int i, int j, int ps) {
    if (i==0) return -k;
    return (ps - lc[i-1][j] > k) ? -k : lc[i-1][j];
};

int checkUp(int i, int j, int ps) {
    if (j==0) return -k;
    return (ps - uc[i][j-1] > k) ? -k : uc[i][j-1];
};

void solve() {
    int left, up, sum;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            if (lc[i][j] != -k && uc[i][j] != -k) continue;
            sum = psa[i]+psb[j];
            left = checkLeft(i, j, sum); up = checkUp(i, j, sum);
            if (left == -k && up == -k) {
                left = up = ps;
                l++;
            }
            lc[i][j] = left; uc[i][j] = up;
        }
    }
};

int main(void) {
    int c;
    cin >> c;
    psa[0] = psb[0] = 0;
    for (int z=0; z<c; ++z) {
        cin >> n >> k;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
        }
        for (int i=1; i<=n; ++i) {
            cin >> b[i];
            psb[i] = psb[i-1] + b[i];
        }

        for (int i=0; i<=n; ++i) {
            for (int j=0; j<=n; ++j) {
                lc[i][j] = uc[i][j] = -k;
            }
        }
        lc[0][0] = uc[0][0] = 0;
        lc[1][0] = uc[1][0] = a[1];
        lc[0][1] = uc[0][1] = b[1];

        l = 2;

        solve();

        cout << "Case #" << z+1 << endl;
        cout << (n+1)*(n+1) - l << ' ' << l << endl;
    }
}