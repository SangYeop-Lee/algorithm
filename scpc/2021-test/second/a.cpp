#include <iostream>
#include <cmath>

#define eps 0.000005

using namespace std;


int r;
int x, y;
long long int ans;

int main(void) {
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        cin >> r;
        ans = 1;
        for (x = 0; x<r; ++x) {
            y = floor(sqrt(pow(r, 2)-pow(x, 2)) - eps);
            ans += y*4;
        }
        cout << "Case #" << zz+1 << endl;
        cout << ans << endl;
    }
}