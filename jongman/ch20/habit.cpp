#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool find(string large, string small) {
    for (int i=0; i<small.size(); ++i)
        if (large[i] != small[i])
            return false;
    
    return true;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        int repeat;
        string s;
        cin >> repeat >> s;
        int n = s.size();
        vector<string> suffix;

        for (int j=0; j<n; ++j)
            suffix.push_back(s.substr(j));
        sort(suffix.begin(), suffix.end());

        int maxSize = 0;
        for (int j=0; j<n; ++j) {
            int l = suffix[j].size();
            for (int k=maxSize+1; k<l+1; ++k) {
                int count = 1;

                string t = suffix[j].substr(0, k);
                for (int m=j+1; m<n; ++m) {
                    if (find(suffix[m], t))
                        ++count;
                    else
                        break;
                }
                if (count >= repeat)
                    maxSize = k;
                else
                    break;
            }
        }

        cout << maxSize << endl;
    }
}

// 4 2 uhmhellouhmmynameislibe 3 banana 1 thatsagoodquestion 3 hello