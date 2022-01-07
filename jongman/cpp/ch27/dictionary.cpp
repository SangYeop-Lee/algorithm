#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> ins;
int alpha[26][26];
bool visited[26];

bool comp(string a, string b) {
    int iter = min(a.size(), b.size());
    for (int i=0; i<iter; ++i) {
        if (a[i] == b[i]) continue;
        int& j = alpha[a[i]-'a'][b[i]-'a'];
        if (j == -1) return false;
        if (j == 1) return true;
        j = 1;
        alpha[b[i]-'a'][a[i]-'a'] = -1;
        return true;
    }

    return a.size() < b.size();
};

string dfs(int index) {
    string ret = "";
    ret += 'a'+index;
    visited[index] = true;
    for (int i=0; i<26; ++i) {
        if (visited[i] == false && alpha[index][i] == 1) {
            ret += dfs(i);
        }
    }
    return ret;
};

string ans() {
    string ret = "";
    fill(visited, visited+26, 0);
    for (int i=0; i<26; ++i) {
        if (visited[i] == false) {
            ret = dfs(i) + ret;
        }
    }

    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int zz=0; zz<c; ++zz) {
        ins.clear();
        memset(alpha, 0, sizeof(alpha[0][0])*26*26);
        cin >> n;
        ins.resize(n);
        for (int i=0; i<n; ++i) {
            cin >> ins[i];
        }

        bool res = true;
        for (int i=1; i<n; ++i) {
            if (res)
                res = comp(ins[i-1], ins[i]);
        }
        cout << (res ? ans() : "INVALID HYPOTHESIS") << endl;
    }
}
// 3 3 ba aa ab 5 gg kia lotte lg hanwha 6 dictionary english is ordered ordinary this