#include <iostream>

using namespace std;

int n;
int input, ans;

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        ans = 0;
        for (int j=0; j<n; ++j) {
            cin >> input;
            if (input+j>=n) ans++;
        }
        cout << "Case #" << i+1 << endl;
        cout << ans << endl;
    }
    return 0;
}
// 2 5 1 1 3 3 3 10 8 10 5 4 2 5 1 3 1 9