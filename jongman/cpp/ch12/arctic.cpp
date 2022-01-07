#include <iostream>
#include <cmath>
#include <sstream>

#define square(x) ((x)*(x))

using namespace std;

int c, n;
double x, y;
double xs[100], ys[100];
bool visited[100];
double maxDistanceSquare; // l2 of max distance

void preCalc() {
    for (int i=0; i<n; ++i) {
        visited[i] = false;
    }
    maxDistanceSquare = 0;
};

void dfs(int index, double dSquare) {
    visited[index] = true;
    for (int i=0; i<n; ++i) {
        if (visited[i]) continue;

        double l2 = square(xs[index]-xs[i])+square(ys[index]-ys[i]);
        if (l2 < dSquare) {
            dfs(i, dSquare);
            if (l2 > maxDistanceSquare)
                maxDistanceSquare = l2;
        }
    }
};

bool checkVisited() {
    for (int i=0; i<n; ++i)
        if (visited[i]==false)
            return false;
    return true;
};

double solve() {
    double dSquare = 987654321;
    double ansSquare;

    do {
        ansSquare = maxDistanceSquare;
        preCalc();
        dfs(0, dSquare);
        dSquare = maxDistanceSquare;
    } while (checkVisited());

    return sqrt(ansSquare);
};

int main(void) {
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        for (int j=0; j<n; ++j) {
            cin >> xs[j] >> ys[j];
        }

        stringstream sstream;
        sstream.setf(ios::fixed);
        sstream.precision(2);
        sstream << solve();
        cout << sstream.str() << endl;
    }
}
// 2 5 0 0 1 0 1 1 1 2 0 2 6 1.0 1.0 30.91 8 4.0 7.64 21.12 6.0 11.39 3.0 5.31 11.0