#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, l;
string s;

int normalize(int a) {
    return a < 0 ? a + l : a;
}

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> s;
        l = s.size();
        s += s;
        int prev = 0, cur;
        string tmp;
        int ret = 0;
        for (int i=0; i<n; ++i) {
            cin >> tmp;
            cur = s.find(tmp);

            ret += i%2 ? normalize(cur-prev) : normalize(prev-cur);
            prev = cur;
        }

        cout << ret << endl;
    }
}

// 2 3 abbab babab ababb bbaba 2 rmdcmrcd mrcdrmdc dcmrcdrm