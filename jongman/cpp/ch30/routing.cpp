// input
// 1
// 7 14
// 0 1 1.3
// 0 2 1.1
// 0 3 1.24
// 3 4 1.17
// 3 5 1.24
// 3 1 2
// 1 2 1.31
// 1 2 1.26
// 1 4 1.11
// 1 5 1.37
// 5 4 1.24
// 4 6 1.77
// 5 6 1.11
// 2 6 1.2

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int t, n, m;
vector<pair<int, float> > noise[10000];
float minimum[10000];
int src, dest;
float multiple;
float maximum = log(3)*20001;

void solve() {
    priority_queue<pair<float, int> > pq;
    pq.push(make_pair(0, 0));
    minimum[0] = 0;
    while (!pq.empty()) {
        float dist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist > minimum[here]) continue;

        for (int i=0; i<noise[here].size(); ++i) {
            int there = noise[here][i].first;
            float dist2 = noise[here][i].second+dist;
            
            if (dist2 < minimum[there]) {
                minimum[there] = dist2;
                pq.push(make_pair(-dist2, there));
            }
        }
    }

    cout << exp(minimum[n-1]) << endl;
}

int main () {
    cin >> t;
    for (int i=0; i<t; ++i) {
        for (int j=0; j<10000; ++j) {
            noise[j].clear();
            minimum[j] = maximum;
        }
        cin >> n >> m;
        for (int j=0; j<m; ++j) {
            cin >> src >> dest >> multiple;
            if (src > dest) {
                int tmp = dest;
                dest = src;
                src = tmp;
            }
            noise[src].push_back(make_pair(dest, log(multiple)));
        }

        solve();
    }
}