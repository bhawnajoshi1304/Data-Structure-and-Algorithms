#include <bits/stdc++.h>
using namespace std;
bool permutationOfPalindrome1(string s)
{
    unordered_map<char, int> m;
    int c = 0;
    for (auto ii : s)
        if ((ii >= 'a' && ii <= 'z') || (ii >= 'A' && ii <= 'Z'))
        {
            char i = ii;
            if (ii >= 'A' && ii <= 'Z')
                i = 'a' + (ii - 'A');
            if (m.find(i) != m.end())
                m[i] += 1;
            else
                m[i] = 1;
            if (m[i] % 2)
                c += 1;
            else
                c -= 1;
        }
    return c <= 1;
}
bool permutationOfPalindrome2(string s){
    vector<bool> v(28,false);
    for(auto ii:s)
    if ((ii >= 'a' && ii <= 'z') || (ii >= 'A' && ii <= 'Z')){
        int i = ii - 'a';
        if(ii >= 'A' && ii <= 'Z')
        i=ii-'A';
        v[i]=~v[i];
    }
    bool b=false;
    for(auto i:v){
        if(i&&b) return false;
        if(i) b=true;
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);
    cout << s << " is permutation of palindrome: " << permutationOfPalindrome1(s) << permutationOfPalindrome2(s)<<"\n";
    return 0;
}