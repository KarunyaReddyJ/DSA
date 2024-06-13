#include<bits/stdc++.h>
using namespace std;
bool safe(int r,int c,int n,int m){
    if(r<0 || c<0 || r>=n || c>=m)
        return false;
    return true;
}
int solve(vector<vector<int> > &A) {
    vector<vector<bool>> visited(A.size(),vector<bool>(A[0].size(),false));
    vector<int> x={-1,0,1};
    function<void(int,int,int&)> dfs=[&](int r,int c,int& nodes){
        nodes++;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j && i==1)
                    continue;
                else if(safe(r+x[i],c+x[j],A.size(),A[0].size()) 
                && A[r+x[i]][c+x[j]]==1 && !visited[r+x[i]][c+x[j]]){
                    visited[r+x[i]][c+x[j]]=1;
                    dfs(r+x[i],c+x[j],nodes);    
                }
            }
        }
    };
    int largest=INT_MIN;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] && !visited[i][j]){
                int nodes=0;
                visited[i][j]=1;
                dfs(i,j,nodes);
                largest=max(nodes,largest);
            }
        }
    }
    return largest;
}

int main(){

}