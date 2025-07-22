#include<bits/stdc++.h>
using namespace std;
void rotateMatrix1(vector<vector<int>> &v){
    int tmp,n=v.size();
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n/2;j+=1){
            tmp=v[i][j];
            v[i][j]=v[j][i];
            v[j][i]=tmp;
        }
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n/2;j+=1){
            tmp=v[i][j];
            v[i][j]=v[i][n-1-j];
            v[i][n-1-j]=tmp;
        }
    }
}
void rotateMatrix2(vector<vector<int>> &v){
    int temp,n=v.size();
for( int i = 0; i < n/2; ++i ) {
		for( int j = i; j < n-i-1; ++j ) {
				int temp = v[i][j];
				v[i][j] = v[n-j-1][i];
				v[n-j-1][i] = v[n-i-1][n-j-1];
				v[n-i-1][n-j-1] = v[j][n-1-i];
				v[j][n-1-i] = temp;
		}
	}
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            cin>>v[i][j];
        }
    }
    cout<<"rotateMatrix method 1:\n";
    rotateMatrix1(v);
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"rotateMatrix method 2:\n";
    rotateMatrix2(v);
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}