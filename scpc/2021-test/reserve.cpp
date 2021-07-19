#include <iostream>
#include <algorithm>

using namespace std;


int n, m, l;
int w[100000];
int odd, even;
int oddw[20000][4], evenw[20000][4];
long long int ans;
int tailw[20000];
int edge[3];

int scoreOdd(int *arr) {
    return arr[0]*2 + arr[1] + arr[2] + arr[3];
};

int scoreO(int *arr) {
    return arr[0] + arr[1] + arr[2] + arr[3];
};

int scoreZ(int *arr) {
    return 2*(arr[0] + arr[1]) + arr[2] + arr[3];
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> m;
        odd = even = 0;
        ans = 0;

        for (int j=0; j<n; ++j) {
            cin >> l;
            for (int k=0; k<l; ++k) {
                cin >> w[k];
            }
            sort(w, w+l);
            if (l%2) {
                for (int as=0; as<4; ++as)
                    oddw[odd][as] = w[as];
                odd ++;
            }
            else {
                for (int as=0; as<4; ++as)
                    evenw[even][as] = w[as];
                even ++;
            }
        }

        if (odd == 2 && even > 0) {
            long long int tmp = 0;
            for (int j=0; j<even; ++j) {
                tmp += scoreZ(evenw[j]);
                ans += scoreO(evenw[j]);
                tailw[j] = evenw[j][2]+evenw[j][3];
            }
            tmp += 2*(oddw[0][0] + oddw[1][0]) + oddw[0][1] + oddw[1][1];
            ans += scoreOdd(oddw[0]) + scoreOdd(oddw[1]);
            sort(tailw, tailw+even, greater<int>());

            edge[0] = max(oddw[0][2]+oddw[0][3], oddw[1][2]+oddw[1][3]);
            edge[1] = tailw[0]; edge[2] = tailw[1];

            sort(edge, edge+3);
            ans -= (edge[1] + edge[2]);
            cout << tmp << ' ' << ans << endl;
            ans = min(tmp, ans);
        } else {
            for (int i=0; i<odd; ++i) {
                ans += scoreOdd(oddw[i]);
                tailw[i] = oddw[i][2] + oddw[i][3];
            }
            for (int i=0; i<even; ++i) {
                ans += scoreO(evenw[i]);
                tailw[i+odd] = evenw[i][2] + evenw[i][3];
            }
            sort(tailw, tailw+n, greater<int>());
            ans -= (tailw[0] + tailw[1]);
        }

        cout << "Case #" << i+1 << endl;
        cout << ans << endl;
    }
    return 0;
}
// 2 2 6 6 1 2 1 3 1 1 6 3 2 2 1 4 1 2 5 5 1 2 3 4 5 5 1 2 3 4 5
// 1 3 8 5 1 2 3 4 5 5 1 2 3 4 5 6 1 2 3 4 5 6
// /usr/bin/clang++ -std=c++17 -stdlib=libc++