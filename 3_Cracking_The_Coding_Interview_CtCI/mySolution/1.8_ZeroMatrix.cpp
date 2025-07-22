#include<bits/stdc++.h>
using namespace std;
void zeroMatrix(vector<vector<int>> &v){
    int m=v.size(),n=v[0].size();
    int x=v[0][0];
    for(int i=0;i<m;i++){
        if(v[i][0]==0) x=0;
        for(int j=1;j<n;j++)
            if(v[i][j]==0)
                v[i][0]=v[0][j]=0;
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=1;j--)
            if(v[i][0]==0||v[0][j]==0)
                v[i][j]=0;
        if(x==0)
            v[i][0]=0;
    }
}

int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cin>>v[i][j];
        }
    }
    cout<<"Zero v:\n";
    zeroMatrix(v);
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}