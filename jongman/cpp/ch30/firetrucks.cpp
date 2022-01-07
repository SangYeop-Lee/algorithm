#include <iostream>
#include <queue>

// input
// 1
// 8 12 3 2
// 1 2 3
// 1 6 9 
// 2 3 6
// 3 4 4
// 3 5 2
// 4 5 7
// 6 5 5
// 8 6 5
// 6 7 3
// 8 7 3
// 7 5 1
// 2 8 3
// 2 3 5
// 4 6

// output
// 16

using namespace std;

int C, V, E, N, M;
vector<int> on_fire, fire_station;
vector<pair<int, int> > time0[1000];
int min_time[1000];

#define MAX_TIME 101
#define MAX_TOTAL_TIME 100 * 50 * 100

void solve() {

    priority_queue<pair<int, int> > pq;  // -time, dest
    
    for (int i=0; i<M; ++i) {
        pq.push(make_pair(0, fire_station[i]));
    }

    while (!pq.empty()) {
        int time1 = -pq.top().first;
        int src = pq.top().second;
        pq.pop();

        if (time1 > min_time[src]) continue;

        for (int i=0; i<time0[src].size(); ++i) {
            int dest = time0[src][i].first;
            int time2 = time1 + time0[src][i].second;
            if (min_time[dest] > time2) {
                min_time[dest] = time2;
                pq.push(make_pair(-time2, dest));
            }
        }
    }


    int res = 0;
    for (int i=0; i<N; ++i) {
        res += min_time[on_fire[i]];
    }

    cout << res << endl;
}

int main() {
    cin >> C;
    for (int i=0; i<C; ++i) {
        on_fire.clear();
        fire_station.clear();
        memset(min_time, MAX_TOTAL_TIME, sizeof min_time);
        for (int j=0; j<1000; ++j) {
            time0[j].clear();
        }
        cin >> V >> E >> N >> M;
        for (int j=0; j<E; ++j) {
            int a, b, t;
            cin >> a >> b >> t;
            time0[a].push_back(make_pair(b, t));
            time0[b].push_back(make_pair(a, t));
        }
        int tmp;
        for (int j=0; j<N; ++j) {
            cin >> tmp;
            on_fire.push_back(tmp);
        }
        for (int j=0; j<M; ++j) {
            cin >> tmp;
            fire_station.push_back(tmp);
        }
        solve();
    }
}