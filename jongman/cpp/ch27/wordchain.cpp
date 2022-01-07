#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> words;
vector<int> g[26][26];
int start[26];
vector<int> ans;

void dfs(int p) {
    int pre;
    for (int i=0; i<26; ++i) {
        if (p==i)
            continue;
        while (!g[p][i].empty()) {
            pre = g[p][i].back();
            g[p][i].pop_back();
            dfs(i);
            ans.push_back(pre);
        }
    }
    while (!g[p][p].empty()) {
        ans.push_back(g[p][p].back());
        g[p][p].pop_back();
    }
};

void print(bool hasN) {
    if (hasN) {
        int nI = find(ans.begin(), ans.end(), n) - ans.begin();
        int begin = (nI+n) % (n+1);
        for (int i=begin; i!=nI; i=(i+n)%(n+1)) {
            cout << words[ans[i]] << endl;
        }
    } else {
        for (int i=ans.size()-1; i>=0; --i) {
            cout << words[ans[i]] << endl;
        }
    }
}

int main(void) {
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        cin >> n;
        for (int i=0; i<26; ++i)
            for (int j=0; j<26; ++j)
                g[i][j].clear();
        words.resize(n);
        fill(start, start+26, 0);
        ans.clear();

        int f, b;
        for (int i=0; i<n; ++i) {
            cin >> words[i];
            f = words[i].front()-'a';
            b = words[i].back()-'a';
            g[f][b].push_back(i);
            start[f]++;
            start[b]--;
        }

        int head = words[0].front()-'a';
        int tail = -1;
        for (int i=0; i<26; ++i) {
            if (start[i]>0)
                head = i;
            if (start[i]<0)
                tail = i;
        }
        if (tail != -1) {
            g[tail][head].push_back(n);
        }

        dfs(head);

        if (ans.size() != n + (tail != -1)) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        print(tail != -1);
    }
}
// 3 4 dog god dragon need 3 aa ab bb 2 ab cd