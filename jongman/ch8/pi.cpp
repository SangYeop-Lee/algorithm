#include <iostream>
#include <string>

#define INF 987654321

using namespace std;

string s = "";
int l=0;
int cache[10000];

bool isSameDigits(string& s) {
    bool ret = true;
    for (int i=1; i<s.size(); ++i){
        ret &= s[i]==s[0];
    }

    return ret;
};


bool isRepeated(string &s) {
    for (int i=2; i<s.size(); ++i) {
        if (s[i]!=s[i-2])
            return false;
    }
    return true;
};

bool isDigitsIncreased2(string& s) {
    int diff = s[1]-s[0];
    for (int i=2; i<s.size(); ++i) {
        if (s[i]-s[i-1]!=diff)
            return false;
    }
    return true;
};

bool isDigitsIncreased(string& s) {
    return isDigitsIncreased2(s) && abs(s[1]-s[0])==1;
};

int getScore(string& s) {
    if (isSameDigits(s)) {
        return 1;
    } else if (isDigitsIncreased(s)) {
        return 2;
    } else if (isRepeated(s)) {
        return 4;
    } else if (isDigitsIncreased2(s)) {
        return 5;
    } else {
        return 10;
    }
};

int solve(int index) {
    int& ret = cache[index];
    if (ret != -1) return ret;
    ret = INF;
    for (int i=3; i<6; ++i) {
        if (index+i > l) continue;
        string tmp = s.substr(index, i);
        ret = min(ret, getScore(tmp) + solve(index+i));
    }
    return ret;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> s;
        l = s.size();
        for (int j=0; j<l; ++j) {
            cache[j] = -1;
        }
        cache[l-1] = cache[l-2] = INF;
        cache[l] = 0;
        cout << solve(0) << endl;
    }
}
// 5 12341234 11111222 12122222 22222222 12673939