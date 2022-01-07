#include <iostream>
#include <vector>

using namespace std;

struct MinMax {
    int minHeight, maxHeight;
    MinMax(int minh = 20001, int maxh = -1) {
        minHeight = minh; maxHeight = maxh;
    }
    int difficulty() {
        return maxHeight - minHeight;
    }
    MinMax merge(MinMax right);
};

MinMax makeMinMax(int minh, int maxh) {
    MinMax ret(minh, maxh);
    return ret;
};

MinMax MinMax::merge (MinMax right) {
    return makeMinMax(
        min(minHeight, right.minHeight),
        max(maxHeight, right.maxHeight)
    );
};

struct Seg {
    int n;
    vector<MinMax> rangeHeight;

    Seg(const vector<int>& heights) {
        n = heights.size();
        rangeHeight.resize(4 * n);
        init(heights, 0, n-1, 1);
    }

    MinMax init(const vector<int>& array, int left, int right, int node) {
        if (left == right)
            return rangeHeight[node] = makeMinMax(array[left], array[left]);

        int mid = (left + right) / 2;
        MinMax l = init(array, left, mid, node * 2);
        MinMax r = init(array, mid + 1, right, node * 2 + 1);

        return rangeHeight[node] = l.merge(r);
    }

    MinMax query(int left, int right, int node, int leftNode, int rightNode) {
        if (left > rightNode || right < leftNode) return makeMinMax(20001, -1);
        if (left <= leftNode && rightNode <= right) return rangeHeight[node];

        int mid = (leftNode + rightNode) / 2;
        MinMax l = query(left, right, node * 2, leftNode, mid);
        MinMax r = query(left, right, node * 2 + 1, mid + 1, rightNode);

        return l.merge(r);
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, n-1).difficulty();
    }
};

int main(void) {
    int t, n, q;
    int left, right;
    vector<int> heights;
    vector<int> ans;
    cin >> t;
    for (int z=0; z<t; ++z) {
        cin >> n >> q;
        heights.resize(n);
        ans.resize(q);
        for (int i=0; i<n; ++i) {
            cin >> heights[i];
        }
        Seg seg(heights);
        for (int i=0; i<q; ++i) {
            cin >> left >> right;
            ans[i] = seg.query(left, right);
        }
        for (int i=0; i<q; ++i) {
            cout << ans[i] << endl;
        }
    }
}
// 2 3 1 1 2 3 0 2 10 4 3 9 5 6 10 8 7 1 2 4 1 6 4 7 9 9 5 8