#include <iostream>
#include <map>

using namespace std;

int ans;
    // 1. p 최적의 위치로 간다.
    //  - 위치를 찾는 중 자신보다 큰 q값을 찾으면 return
    // 2. 아래의 node들을 모두 검사한다.
    //  - 조건에 맞지 않는 node를 삭제할 때마다 elCount - 1

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        int n;
        cin >> n;
        int p, q;
        map<int, int> data;        
        ans = 0;

        for (int j=0; j<n; ++j) {
            cin >> p >> q;
            map<int, int>::iterator k = data.lower_bound(p);
            if (k == data.end() || k->second < q) {
                data.insert({p, q});
                map<int, int>::iterator tmp = data.find(p);
                if (tmp!=data.begin())
                    while (true) {
                        tmp --;
                        if (tmp->second < q) {
                            if (tmp==data.begin()) {
                                data.erase(tmp);
                                break;
                            }
                            data.erase(tmp);
                        } else break;
                    }
            }

            ans += data.size();
        }

        cout << ans << endl;
    }
}

// 2 4 72 50 57 67 74 55 64 60 5 1 5 2 4 3 3 4 2 5 1