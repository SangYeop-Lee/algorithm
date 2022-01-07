#include <iostream>
#include <string>
#include <vector>

using namespace std;

string idol;
string fan;

// MM쌍이 없는 회수 출력

// m + n - 1;

void karatsuba(vector<int>& ret, vector<int> a, vector<int> b) {
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<b.size(); ++j)
            ret[i+j] += a[i]&&b[j];
}

int solve() {
    int n = idol.size(), m = fan.size();
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) a[i] = idol[i]=='m';
    for (int i=0; i<m; ++i) b[m-i-1] = fan[i]=='m';
    vector<int> ans(a.size()+b.size()-1, 0);
    karatsuba(ans, a, b);
    int ret = 0;
    for (int i=n-1; i<ans.size()-n+1; ++i)
        if (!ans[i])
            ++ret;

    return ret;
}

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> idol >> fan;
        cout << solve() << endl;
    }
}
