#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& v){
    for(int& x : v) cout<<x<<" ";
    cout<<endl;
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int> last(n,0),up(n,0);
        vector<int> &u=last,&v=up,&temp=obstacleGrid.back();
        for(int i=n-1;i>=0;i--){
            if(temp[i]) break;
            last[i]=1;
        }
        //print(last);
        for(int i=m-2;i>=0;i--){
            v[n-1]=(1-obstacleGrid[i][n-1])*u[n-1];
            for(int j=n-2;j>=0;j--)
                v[j]=(1-obstacleGrid[i][j])*(v[j+1]+u[j]);
           // print(v);
            temp=u;
            u=v;
            v=temp;

        }

        return u[0];
    }
};
int main(){
    Solution s;
    vector<vector<int>> obstacleGrid={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,0,0}};
    cout<<s.uniquePathsWithObstacles(obstacleGrid);
}