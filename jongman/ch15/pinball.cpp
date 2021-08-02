
// TODO
// debug it.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
    double x, y, r;
};

double x, y, dx, dy;
int n;
Circle c[50];
double lineCo[3]; // coeff of x y c;
int prevAns;

void preCalc() {
    double slopeSize = sqrt(dx*dx + dy*dy);
    dx /= slopeSize; dy /= slopeSize;

    lineCo[0] = dy;
    lineCo[1] = -dx;
    lineCo[2] = -x*dy + y*dx;
};

double getCircleLineDistance(Circle c) {
    return abs(lineCo[0]*c.x + lineCo[1]*c.y + lineCo[2]);
};

bool isReflected(Circle c) {
    return getCircleLineDistance(c) < c.r;
};

double innerProduct(Circle c) {
    return (c.x-x)*dx + (c.y-y)*dy;
};

bool isTowardLine(Circle c) {
    return innerProduct(c) > 0;
};

void solve() {
    for (int z=0; z<10; ++z) {
        preCalc();

        vector<int> candidates;
        for (int i=0; i<n; ++i) {
            if (isTowardLine(c[i]) && isReflected(c[i]) && i!=prevAns) {
                candidates.push_back(i);
            }
        }

        if (candidates.size() == 0)
            break;
        
        int targetIndex = 0;
        double targetDist = innerProduct(c[candidates[0]]);
        for (int i=1; i<candidates.size(); ++i) {
            double tmpDist = innerProduct(c[candidates[i]]);
            if (tmpDist < targetDist) {
                targetDist = tmpDist;
                targetIndex = i;
            }
        }
        prevAns = candidates[targetIndex];
        cout << prevAns << ' ';

        Circle t = c[prevAns];
        double coef = targetDist -
            sqrt(pow(t.r, 2) - pow(getCircleLineDistance(t), 2));
        
        x += coef * dx;
        y += coef * dy;

        double rx = x-t.x;
        double ry = y-t.y;
        double cosV = (-dx*rx-dy*ry) / t.r;
        double sinV = sqrt(1-cosV*cosV);
        dx = rx*cosV - ry*sinV;
        dy = sinV*rx + cosV*ry;

        cout << x << ' ' << y << ' ' << dx << ' ' << dy << ' ' << endl;
    }
    cout << endl;
};

int main(void) {
    int z;
    cin >> z;
    for (int i=0; i<z; ++i) {
        cin >> x >> y >> dx >> dy >> n;
        double tmpr;
        prevAns = -1;
        for (int j=0; j<n; ++j) {
            cin >> c[j].x >> c[j].y >> tmpr;
            c[j].r = tmpr+1;
        }
        solve();
    }
}

// 1 5 5 1 1 5 22 40 12 61 26 20 19 78 21 51 86 7 84 57 15