#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>& cache=matrix;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int minPathSum=INT_MAX;
                for(int k=-1;k<2;k++){
                    if(j+k>=0 && j+k<n)
                        minPathSum=min(minPathSum,cache[i+1][j+k]);
                }
                cache[i][j]+=minPathSum;
            }
        }
        return *min_element(cache[0].begin(),cache[0].end());
    }
private:
    int recursion(vector<vector<int>>& matrix,size_t level,size_t indexChosen){
        if(level==matrix.size()) return 0;
        if(indexChosen<0 || indexChosen==matrix.size()) 
            return INT_MAX;
        int southWest=INT_MAX,south=INT_MAX,southEast=INT_MAX;
        if(indexChosen-1>=0) 
            southWest=matrix[level][indexChosen-1]+recursion(matrix,level+1,indexChosen-1);
        south=matrix[level][indexChosen]+recursion(matrix,level+1,indexChosen);
        if(indexChosen+1<matrix.size())
            southEast=matrix[level][indexChosen+1]+recursion(matrix,level+1,indexChosen+1);
        return min(south,min(southEast,southWest));
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(vector<int>& v : matrix)
        for(int& x : v) cin>>x;
    cout<<s.minFallingPathSum(matrix);
}