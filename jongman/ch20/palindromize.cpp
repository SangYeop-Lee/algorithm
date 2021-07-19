#include <iostream>
#include <string>

using namespace std;

string s;

int main(void) {
    cin >> s;
    int n = s.size();
    string rs;
    for (auto i=s.rbegin(); i < s.rend(); ++i)
        rs += *i;
    for (int i=0; i<=n; ++i) {
        if (!s.substr(i).compare(rs.substr(0, n-i))) {
            cout << s + rs.substr(n-i, i) << endl;
            return 0;
        }
    }
}