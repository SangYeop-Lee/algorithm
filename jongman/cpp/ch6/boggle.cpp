#include <iostream>
#include <string>

using namespace std;

char table[5][5];
int i, j;
string tmp;

bool hasWord(int row, int col, int index) {
    if (table[row][col]!=tmp[index]) return false;
    ++index;
    if (index==tmp.size()) return true;

    bool ret = false;

    for (int rMin = max(row-1, 0), rMax = min(row+2, 5);
      rMin<rMax; rMin++) {
          for (int cMin = max(col-1, 0), cMax = min(col+2, 5);
            cMin<cMax; cMin++) {
                if (!(cMin==col&&rMin==row)) {
                    ret = ret || hasWord(rMin, cMin, index);
                }
            }
      }
    
    return ret;
}

bool solve() {
    for (i=0; i<5; ++i)
        for (j=0; j<5; ++j)
            if (hasWord(i, j, 0))
                return true;

    return false;
}

int main (void) {
    for (i=0; i<5; ++i)
        for (j=0; j<5; ++j)
            cin >> table[i][j];

    while (cin >> tmp) {
        cout << (solve() ? "true" : "false") << endl;
    }
}