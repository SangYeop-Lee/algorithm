#include <iostream>
#include <string>

using namespace std;

string swap(string a) {
    if (a.size()==1) return a;
    string head = "", tail = "", tmp="";
    int tmpSize = 1, lastIndex = 1, chunkIndex = 0;
    for (int i=1; i<a.size(); ++i) {
        if (a[i]=='x') {
            tmpSize += 4;
        } else if (i-lastIndex+1==tmpSize) {
            if (chunkIndex<2) {
                tail += swap(a.substr(lastIndex, tmpSize));
            } else {
                head += swap(a.substr(lastIndex, tmpSize));
            }
            chunkIndex ++;
            lastIndex += tmpSize;
            tmpSize = 1;
        }
    }
    return 'x'+head+tail;
};

string reverse(string::iterator& it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        string input;
        cin >> input;
        string::iterator tmp = input.begin();
        cout << swap(input) << endl;
        cout << reverse(tmp) << endl;
    }
    return 0;
}