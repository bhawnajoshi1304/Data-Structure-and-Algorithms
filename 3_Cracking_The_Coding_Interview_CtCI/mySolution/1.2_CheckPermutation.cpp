#include<bits/stdc++.h>
using namespace std;
bool checkPermutation1(string a,string b){
    if(a.size()!=b.size()) return false;
    unordered_map<char,int> m;
    for(int i=0;i<a.size();i+=1){
        if(m.find(a[i])!=m.end()) m[a[i]]+=1;
        else m[a[i]]=1;
        if(m.find(b[i])!=m.end()) m[b[i]]-=1;
        else m[b[i]]=-1;
    }
    for(auto i:m) if(i.second!=0) return false;
    return true;
}
bool checkPermutation2(string a, string b){
    if(a.size()!=b.size()) return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i+=1)
    if(a[i]!=b[i]) return false;
    return true;
}

int main(){
string a,b;
cin>>a>>b;
cout<<checkPermutation1(a,b)<<"\n";
cout<<checkPermutation2(a,b)<<"\n";
}