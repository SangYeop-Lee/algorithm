#include <iostream>
#include <string>

using namespace std;

int t, n, a, b;
string s;

void solve() {
    cin >> s;
    if (b >= 0) {
        cout << n * (a + b) << endl;
        return;
    }
    int switches = 1;
    for (int i=1; i<s.size(); ++i) {
        switches += s[i-1] != s[i];
    }
    switches /= 2;
    switches ++;
    cout << n * a + b * switches << endl;
    return;
};

int main(void) {
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n >> a >> b;
        solve();
    }
}