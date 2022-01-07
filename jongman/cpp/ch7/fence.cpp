#include <iostream>

using namespace std;

int n;
int fence[20000];

int solve(int left, int right) {
    if (left==right) return fence[left];
    int mid = (left+right)/2;

    int lc = mid;
    int rc = mid+1;
    int height = min(fence[lc], fence[rc]);
    int width = 2;
    int ret = height*width; // height * rc+lc-1

    for (int i=0; i<right-left-1; ++i) {
        if (lc==left || fence[lc-1] < fence[rc+1]) {
            height = min(fence[++rc], height);
        } else {
            height = min(fence[--lc], height);
        }
        ret = max(ret, (++width)*height);
    }

    return max (
        max(
            solve(left, mid),
            solve(mid+1, right)
        ),
        ret
    );
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        for (int j=0; j<n; ++j)
            cin >> fence[j];
        cout << solve(0, n-1) << endl;
    }
    return 0;
}