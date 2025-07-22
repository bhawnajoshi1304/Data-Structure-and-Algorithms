#include<bits/stdc++.h>
using namespace std;

void urlify(string &s){
    int c=0;
    for(auto i:s)
    if(i==' ') c+=1;
    s.resize(s.size()+2*c);
    for(int i=s.size()-1;i>=0;i--){
        if(s[i-2*c]==' '){
            s[i-2]='%';
            s[i-1]='2';
            s[i]='0';
            c-=1;
            i-=2;
        }else 
        s[i]=s[i-2*c];
    }
}

int main(){
    string s;
    getline(cin,s);
    urlify(s);
    cout<<s<<"\n";
    return 0;
}