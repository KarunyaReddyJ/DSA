#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> directions;
    vector<vector<int>> dp;
public:
    Solution():dp(200,vector<int>(200,-1)){
        directions={{1,0},{-1,0},{0,1},{0,-1}};
    }
    bool isValid(vector<vector<int>>& matrix,int x,int y,int i,int j){
        return (matrix.size()>x && x>=0  && y>=0 && matrix[0].size()>y && matrix[x][y]>matrix[i][j]);
    } 
    int dpf(vector<vector<int>>& matrix,int x,int y){
        int maxLength=0;
        if(dp[x][y]!=-1) return dp[x][y];
        for(vector<int>& v : directions) maxLength=max(maxLength,1+(isValid(matrix,x+v[0],y+v[1],x,y)?dpf(matrix,x+v[0],y+v[1]):0));
        dp[x][y]=maxLength;
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLength=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxLength=max(maxLength,dpf(matrix,i,j));
            }
        }
        return maxLength;
    }
};
int main(){
    //vector<vector<int>> matrix={{3,4,5}};
    Solution s;
     srand(time(0)); // Seed for random number generation
    int rows = rand()%20+1;
    int cols = rand()%50+1;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        cout<<"{";
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 1000;
            cout<<matrix[i][j]<<","; // Random values between 0 and 999
        }
        cout<<"}"<<endl;
    }
     auto start = std::chrono::high_resolution_clock::now();
    //ans=s.countBits(n);
    cout<<s.longestIncreasingPath(matrix)<<endl;
      auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Output the duration in seconds
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;
}