#include<bits/stdc++.h>
using namespace std;

bool isUnique1(string s){
    if(s.size()>128) return false;
    vector<bool> v(128,false);
    for(int i=0;i<s.size();i+=1){
        if(v[s[i]]) return false;
        v[s[i]]=true;
    }
    return true;
}

bool isUnique2(string s){
    if(s.size()>128) return false;
    bitset<128> b(0);
    for(int i=0;i<s.size();i+=1){
        if(b.test(s[i])) return false;
        b.set(s[i]);
    }
    return true;
}

bool isUnique3(string s){
    if(s.size()>128) return false;
    for(int i=0;i<s.size();i+=1){
        for(int j=i+1;j<s.size();j+=1){
            if(s[i]==s[j]) return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<isUnique1(s)<<"\n";
    cout<<isUnique2(s)<<"\n";
    cout<<isUnique3(s)<<"\n";
    return 0;
}