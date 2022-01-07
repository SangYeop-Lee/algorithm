#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;

string solve() {
    stack<char> st;
    bool tmp;

    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return "NO";
            }
            char c = st.top();
            st.pop();
            switch(c) {
                case '(': tmp = s[i]==')'; break;
                case '[': tmp = s[i]==']'; break;
                case '{': tmp = s[i]=='}'; break;
            }
            if (!tmp) {
                return "NO";
            }
        }
    }
    return st.empty() ? "YES" : "NO";
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> s;
        cout << solve() << endl;
    }
}
// 3 ()() ({[}]) ({}[(){}])