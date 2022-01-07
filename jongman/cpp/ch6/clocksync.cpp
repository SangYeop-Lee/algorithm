#include <iostream>
#include <vector>

using namespace std;

#define MAX_CLICKS 31

int clocks[16];
int Answer;
vector<vector<int>> buttons {
    {0, 1, 2},
    {0, 2, 14, 15},
    {0, 4, 5, 6, 7},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13},
    {3, 7, 9, 11},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {4, 10, 14, 15},
    {6, 7, 8, 10, 12},
};

bool isTerminated() {
    for (int i=0; i<16; ++i) {
        if (clocks[i]!=12)
            return false;
    }
    return true;
};

void clockWise(int &time) {
    time += 3;
    if (time>12)
        time -= 12;
};

void click(vector<int> button) {
    for (int i=0; i<button.size(); ++i) {
        clockWise(clocks[button[i]]);
    }
};

int solve(int stage) {
    if (isTerminated()) return 0;
    if (stage==10) return MAX_CLICKS;

    int ret = MAX_CLICKS;
    for (int i=0; i<4; ++i) {
        ret = min(ret, solve(stage+1)+i);
        click(buttons[stage]);
    }

    return ret;
};

int main() {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        
        for (int j=0; j<16; ++j)
            cin >> clocks[j];
        
        Answer = solve(0);
        Answer = Answer==MAX_CLICKS ? -1 : Answer;
        cout << Answer << endl;
    }
}