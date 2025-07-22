#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3;
    cin>>s1>>s2;
    s3=s1+s2;
    if(s3.find(s1)) cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}