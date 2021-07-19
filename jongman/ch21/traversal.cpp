#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void printPostOrder(vector<int>& pre, vector<int>& in) {
    if (pre.empty()) return;

    int root = pre[0];

    int leftCount = find(in.begin(), in.end(), root) - in.begin();
    // print left
    vector<int> nextPre(pre.begin()+1, pre.begin()+leftCount+1);
    vector<int> nextIn(in.begin(), in.begin()+leftCount);
    printPostOrder(
        nextPre,
        nextIn
    );
    // print right
    nextPre = vector<int>(pre.begin()+leftCount+1, pre.end());
    nextIn = vector<int>(in.begin()+leftCount+1, in.end());
    printPostOrder(
        nextPre,
        nextIn
    );
    cout << root << ' ';
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        vector<int> preorder(n), inorder(n);
        for (int j=0; j<n; ++j) {
            cin >> preorder[j];
        }
        for (int j=0; j<n; ++j) {
            cin >> inorder[j];
        }
        printPostOrder(preorder, inorder);
        cout << endl;
    }
}
// 1 7 27 16 9 12 54 36 72 9 12 16 27 36 54 72