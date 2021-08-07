#include <iostream>
#include <string>

using namespace std;

string s;
int n, t;
bool bs[50000];
bool ans[50000];

void setAns(int i) {
    ans[i] = 1;
    if (i-t>=0)
        bs[i-t] = 1;
    if (i+t<n)
        bs[i+t] = 1;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> t >> s;
        for (int i=0; i<n; ++i) {
            if (s[i]=='1') bs[i] = 0;
            else bs[i] = 1;
        }
        fill_n(ans, n, 0);

        for (int j=0; j<t; ++j) {
            if (s[j]=='1') {
                setAns(j+t);
            }
            if (s[n-1-j]=='1') {
                setAns(n-1-j-t);
            }
        }

        for (int j=0; j<n; ++j) {
            if (bs[j]) continue;
            if (j+2*t >= n || s[j+2*t] == '1') {
                setAns(j+t);
            } else setAns(j-t);
        }

        cout << "Case #" << i+1 << endl;
        for (int j=0; j<n; ++j) {
            cout << ans[j];
        }
        cout << endl;
    }
}
// 2 5 1 00111 10 2 1111111000