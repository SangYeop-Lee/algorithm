#include <iostream>

using namespace std;
int n;
int a[3001], b[3001];
int k;
int psa[3001], psb[3001];
int cache[3001][3001];
int l;

int getPs(int i, int j) {
    if (i < 0 || j < 0) return 0;
    return cache[i][j];
};

void fill() {
    int rec, sum;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            if (cache[i][j] != -1) continue;

            rec = max(getPs(i-1, j), getPs(i, j-1));
            sum = psa[i]+psb[j];
            if (sum-rec > k) {
                l++;
                rec = sum;
            }
            cache[i][j] = rec;
        }
    }
};

int main(void) {
    int c;
    cin >> c;
    a[0] = b[0] = psa[0] = psb[0] = 0;
    for (int z=1; z<=c; ++z) {
        cin >> n >> k;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
        }
        for (int i=1; i<=n; ++i){
            cin >> b[i];
            psb[i] = psb[i-1] + b[i];
        }

        for (int i=0; i<=n; ++i)
            for (int j=0; j<=n; ++j) {
                cache[i][j] = -1;
            }

        cache[0][0] = 0;
        cache[1][0] = a[1];
        cache[0][1] = b[1];
        
        l = 2;

        fill();

        cout << "Case #" << z << endl;
        cout << (n+1)*(n+1) - l << ' ' << l << endl;
    }
}
// 2 2 3 3 3 3 3 2 3 1 2 1 2