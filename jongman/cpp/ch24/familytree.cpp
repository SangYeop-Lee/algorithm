#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> children[100000];
int generation[100000];
int parent;
int preorder[200000];
int minIndex[100000];
int ans[10000];
int n, q;
int a, b;

struct LCP {
    int length;
    vector<int> minGen;
    LCP (int l) {
        length = l;
        minGen.resize(4 * l);
        init(0, length-1, 1);
    }

    int init(int left, int right, int node) {
        if (left == right)
            return minGen[node] = generation[preorder[left]];
        int mid = (left + right) / 2;
        int l = init(left, mid, 2*node);
        int r = init(mid + 1, right, 2*node + 1);

        return minGen[node] = min(l, r);
    }

    int query(int left, int right, int node, int leftNode, int rightNode) {
        if (left > rightNode || right < leftNode) {
            return 100001;
        }
        if (left <= leftNode && rightNode <= right) {
            return minGen[node];
        }

        int mid = (leftNode + rightNode) / 2;
        int l = query(left, right, 2*node, leftNode, mid);
        int r = query(left, right, 2*node+1, mid+1, rightNode);

        return min(l, r);
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, length-1);
    }
};

void insertPre(int& pre, int node) {
    if (minIndex[node] == -1)
        minIndex[node] = pre;
    preorder[pre++] = node;
    
    for (int i=0; i<children[node].size(); ++i) {
        insertPre(pre, children[node][i]);
        preorder[pre++] = node;
    }
};

int main(void) {
    generation[0] = 0;
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        cin >> n >> q;

        for (int i=0; i<100000; ++i) {
            children[i].clear();
        }
        fill(minIndex, minIndex+n, -1);

        for (int i=1; i<n; ++i) {
            cin >> parent;
            generation[i] = generation[parent] + 1;
            children[parent].push_back(i);
        }

        int pre = 0;
        insertPre(pre, 0);

        LCP lcp(2*n-1);

        for (int i=0; i<q; ++i) {
            cin >> a >> b;
            ans[i] = generation[a] + generation[b]
                -2 * lcp.query(min(minIndex[a], minIndex[b]), max(minIndex[a], minIndex[b]));
        }

        for (int i=0; i<q; ++i) {
            cout << ans[i] << endl;
        }
    }
}
// 1 13 5 0 1 1 3 3 0 6 0 8 9 9 8 2 7 10 11 4 11 7 7 10 0