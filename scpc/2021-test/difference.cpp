#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

#define NC numeric_limits<int>::max()
#define CF numeric_limits<int>::min()

int n, k;
vector<pair<int, int>> e[100001]; // a->b
int distSaved[100001];
bool visited[100001];
vector<int> ans;
int qType, x, y, dist;

void init() {
    for (int i=1; i<100001; i++) {
        e[i].clear();
    }
    ans.clear();
};

vector<pair<int, int>>::iterator findE(int x, int y) {
    return find_if(e[x].begin(), e[x].end(),
        [=](pair<int, int> a) {
            return a.first == y;
        }
    );
}

void insert(int dist) {
    auto it = findE(x, y);
    if (it==e[x].end()) {
        e[x].push_back({y, dist});
        e[y].push_back({x, -dist});
    } else if (it->second != dist) {
        it->second = CF;
        auto tmp = findE(y, x);
        tmp->second = CF;
    }
};

void setConflict(int n) {
    distSaved[n] = CF;
    visited[n] = true;
    for (auto i=e[n].begin(); i!=e[n].end(); ++i) {
        if (distSaved[i->first] != CF)
            setConflict(i->first);
    }
};

void dfs(int root) {
    int& curDist = distSaved[root];
    visited[root] = true;
    for (auto i = e[root].begin(); i != e[root].end(); ++i) {
        if (visited[i->first]) {
            if (distSaved[i->first] == CF) {
                continue;
            } else if (curDist + i->second != distSaved[i->first]) {
                setConflict(i->first);
            }
        } else if (i->second == CF) {
            setConflict(i->first);
        } else {
            distSaved[i->first] = curDist + i->second;
            dfs(i->first);
        }

        if (curDist == CF) {
            setConflict(root);
            return;
        }
    }
};

void printAns(int n) {
    switch(n) {
        case NC: cout << "NC" << endl; return;
        case CF: cout << "CF" << endl; return;
    }
    cout << n << endl;
};

int main(void) {
    int c;
    cin >> c;
    for (int z=0; z<c; ++z) {
        init();
        cin >> n >> k;

        for (int i=0; i<k; ++i) {
            cin >> qType >> x >> y;
            if (qType==1) {
                cin >> dist;
                insert(dist);
            } else {
                for (int i=1; i<=n; ++i) {
                    visited[i] = 0;
                    distSaved[i] = NC;
                }
                visited[x] = 1; distSaved[x] = 0;
                dfs(x);
                ans.push_back(distSaved[y]);
            }
        }
        cout << "Case #" << z+1 << endl;
        for (int i=0; i<ans.size(); ++i) {
            printAns(ans[i]);
        }
    }
}
// 1 3 3 1 2 3 0 1 3 2 0 2 2 3