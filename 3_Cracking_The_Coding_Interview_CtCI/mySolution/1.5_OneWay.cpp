#include <bits/stdc++.h>
using namespace std;

bool oneStepAway(string s1, string s2)
{
    bool l=s1.size()==s2.size();
    if (s1.size() > s2.size())
    {
        string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    int i = 0, j = 0;
    bool f = false;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] != s2[j])
        {
            if (f)
                return false;
            if(l) i+=1;
            j += 1;
            f = true;
        }
        else
        {
            i += 1;
            j += 1;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << "One step away " << s1 << " " << s2 << " :" << oneStepAway(s1, s2) << "\n";
}