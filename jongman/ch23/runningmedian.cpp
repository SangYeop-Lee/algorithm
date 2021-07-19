#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define seed 1983
#define mod 20090711

int c, n, a, b;
long long int genNum;

void next() {
    genNum = (genNum * a + b) % mod;
};

int main(void) {
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> a >> b;
        int ans = genNum = seed;
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        left.push(genNum);
        for (int i=1; i<n; ++i) {
            next();

            if (i%2) {
                right.push(genNum);
            } else {
                left.push(genNum);
            }

            if (left.top() > right.top()) {
                int tmp = right.top();
                right.pop();
                right.push(left.top());
                left.pop();
                left.push(tmp);
            }

            ans = (ans + left.top()) % mod;
        }
        cout << ans << endl;
    }
}
// 3 10 1 0 10 1 1 10000 1273 4936