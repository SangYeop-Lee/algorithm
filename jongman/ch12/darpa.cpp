#include <iostream>

#define maximum 987654321

using namespace std;

int cache[7][5];
int loc[7] = {0, 70, 90, 120, 200, 210, 220};

// 0 1 2 3 4 5 6
// 1 2 3 4

// 1. location is selected
int solve(int location, int left) {
    if (left==0)
        return maximum;
    
    int& ret = cache[location][left];
    if (ret) return ret;

    for (int i=0; i<7-location-left; ++i) {
        ret = max(ret,
                min(
                    loc[location+1+i]-loc[location],
                    solve(location+1+i, left-1)
                )
            );
    }

    return ret;
};

int main (void) {
    for (int i=0; i<4; ++i) {
        cout << solve(i, 3) << endl;
    }
}