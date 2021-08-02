#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n, m;
double nx[100], ny[100], mx[100], my[100];
int nl, nr, ml, mr;
vector<pair<double, double>> nUp;
vector<pair<double, double>> nDown;
vector<pair<double, double>> mUp;
vector<pair<double, double>> mDown;

double getY(double x, pair<double, double> p1, pair<double, double> p2) {
    if (p1.first == p2.first)
        return p1.second;
    return ((p2.second-p1.second)*x + p2.first*p1.second - p1.first*p2.second) / (p2.first-p1.first);
};

double calcDist(double x) {
    int i=0;
    while (x >= mUp[i].first) {
        ++i;
    }
    double up = getY(x, mUp[i-1], mUp[i]);
    i=0;
    while (x >= nUp[i].first) {
        ++i;
    }
    up = min(up, getY(x, nUp[i-1], nUp[i]));

    i=0;
    while (x >= mDown[i].first) {
        ++i;
    }
    double down = getY(x, mDown[i-1], mDown[i]);
    i=0;
    while (x >= nDown[i].first) {
        ++i;
    }
    down = max(down, getY(x, nDown[i-1], nDown[i]));
    return up - down;
};

double solve() {
    double left = max(nx[nl], mx[ml]);
    double right = min(nx[nr], mx[mr]);

    for (int i=0; i<100; ++i) {
        double mid1 = (left*2 + right) / 3;
        double mid2 = (left + right*2) / 3;
        if (calcDist(mid1) < calcDist(mid2))
            left = mid1;
        else
            right = mid2;
    }
    return max(0.0, calcDist(right));
};

void preCalc() {
    nUp.clear();
    nDown.clear();
    mUp.clear();
    mDown.clear();
    int i = nl;
    while (i!=nr) {
        nDown.push_back({nx[i], ny[i]});
        i = (i+1)%n;
    }
    nDown.push_back({nx[nr], ny[nr]});

    i = nl;
    while (i!=nr) {
        nUp.push_back({nx[i], ny[i]});
        i = (i-1+n)%n;
    }
    nUp.push_back({nx[nr], ny[nr]});

    i = ml;
    while (i!=mr) {
        mDown.push_back({mx[i], my[i]});
        i = (i+1)%m;
    }
    mDown.push_back({mx[mr], my[mr]});

    i = ml;
    while (i!=mr) {
        mUp.push_back({mx[i], my[i]});
        i = (i-1+m)%m;
    }
    mUp.push_back({mx[mr], my[mr]});
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n >> m;
        nr = mr = -1;
        nl = ml = 101;

        for (int j=0; j<n; ++j){
            cin >> nx[j] >> ny[j];
            if (nx[j] < nx[nl])
                nl = j;
            if (nx[j] > nx[nr])
                nr = j;
        }
        for (int j=0; j<m; ++j) {
            cin >> mx[j] >> my[j];
            if (mx[j] < mx[ml])
                ml = j;
            if (mx[j] > mx[mr])
                mr = j;
        }

        preCalc();

        stringstream sstream;
        sstream.setf(ios::fixed);
        sstream.precision(6);
        sstream << solve();
        cout << sstream.str() << endl;
    }
}

// 2 5 5 35.74 35.85 69.64 50.00 73.52 82.55 43.50 92.22 17.67 76.18 16.47 8.02 60.98 14.62 66.80 37.74 45.89 67.22 13.04 55.19 4 3 73.84 11.41 71.61 32.72 39.87 38.84 22.41 17.87 75.13 51.64 47.72 87.34 15.97 64.56