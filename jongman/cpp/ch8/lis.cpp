#include <iostream>

using namespace std;

int cache[101], a[101];
int n;

int lis (int index) {
    int &ret = cache[index];
    if (ret != -1) return ret;

    ret = 1;
    for (int i = index+1; i < n; ++i) {
        if (a[i]>a[index]) {
            ret = max(ret, 1 + lis(i));
        }
    }

    return ret;
};

int main (void) {
    cin >> n;
    ++n;
    a[0] = -1;
    cache[0] = -1;
    for (int i=1; i<n; ++i) {
        cin >> a[i];
        cache[i] = -1;
    }
    for (int i=0; i<n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << (lis(0) - 1) << endl;
}