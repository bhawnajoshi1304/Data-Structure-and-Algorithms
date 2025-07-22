#include <bits/stdc++.h>
using namespace std;

string compressedString(string s) {
    string ans = "";
    int c = 0;
    for (int i = 0; i < s.size(); i += 1) {
        if (i == 0) {
            ans += s[i];
        }
        else if (i > 0 && s[i] != s[i - 1]) {
            if (c > 0) {
                ans += to_string(c);
                c = 0;
            }
            ans += s[i];
        }
        c += 1;
    }
    if (c > 0)
        ans += to_string(c);

    if (ans.size() < s.size())
        return ans;
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << compressedString(s) << "\n";
    return 0;
}