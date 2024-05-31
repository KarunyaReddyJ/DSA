#include<bits/stdc++.h>
using namespace std;
int countNegatives(vector<vector<int>>& grid) {
    int count=0;
    for(int i=0;i<grid.size();i++){
        if(grid[i][0]<0){
            count+=(grid.size()-i)*grid[0].size();
            break;
        }
        auto it=upper_bound(grid[i].rbegin(),grid[i].rend(),-1);
            //  cout<<*it<<"\n";
        if(it!=grid[i].rend()){
            count+=(it-grid[i].rbegin());
        }
    }  
    return count;
}
int main(){
    vector<vector<int>> v={{3,2},{1,0}};
    cout<<countNegatives(v);
}