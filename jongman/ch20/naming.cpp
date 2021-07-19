#include <iostream>
#include <string>

using namespace std;

string s;

int main(void) {
    cin >> s;
    for (int i=1; i<=s.size(); ++i) {
        string t1 = s.substr(0, i);
        string t2 = s.substr(s.size()-i);
        if (!t1.compare(t2))
            cout << i << ' ';
    }
    cout << endl;
}
// ababbaba