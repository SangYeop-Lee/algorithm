#include <iostream>
#include <queue>

using namespace std;

int k, n;
uint a;
queue<uint> s;

void generate() {
    s.push(a % 10000+1);
    a = a * 214013 + 2531011;
};

int solve() {
    int ret = 0;
    int ps = 0;
    for (int i=0; i<n; ++i) {
        generate();
        ps += s.back();
        while (ps>=k) {
            if (ps==k)
                ret++;
            ps -= s.front();
            s.pop();
        }
    }

    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> k >> n;
        while (s.size()) {
            s.pop();
        }
        a = 1983;
        cout << solve() << endl;
    }
}
// 3 8791 20 5265 5000 3578452 5000000