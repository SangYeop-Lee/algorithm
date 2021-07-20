#include <iostream>
#include <cmath>

int t, s;

using namespace std;

int main(void) {
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> s;
        cout << (int) ceil(sqrt(s)) << endl;
    }
}