#include <iostream>
#include <cmath>

using namespace std;

struct P {
    long long int x, y;
    void init(long long int _x, long long int _y) {
        x = 2*_x; y = 2*_y;
    }
    long long int getDist(P there) {
        return abs(x-there.x) + abs(y-there.y);
    }
    long long int xpy() {
        return x+y;
    }
    long long int ymx() {
        return y-x;
    }
};

P ps[8];
P center;

bool pCompare(P a, P b) {
    return a.xpy() < b.xpy();
};
bool mCompare(P a, P b) {
    return a.ymx() < b.ymx();
}

int main(void) {
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        long long int x, y;
        for (int i=0; i<8; ++i) {
            cin >> x >> y;
            ps[i].init(x, y);
        }

    }
}