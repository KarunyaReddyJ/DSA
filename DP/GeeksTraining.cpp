//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int maxTrain(vector<vector<int>>& point,int ind,int lastChosen){
    if(ind==point.size()) return 0;
    if(lastChosen!=-1 && dp[ind][lastChosen]!=-1) return dp[ind][lastChosen];
    int points=0;
    for(int i=0;i<3;i++) if(i!=lastChosen) points=max(points,point[ind][i]+maxTrain(point,ind+1,i));
    dp[ind][lastChosen]=points;
    return points;
}
int maximumPoints(vector<vector<int>>& points, int n) {
vector<vector<int>> dp(n,vector<int>(3,-1));
    return maxTrain(points,0,-1);
}

int main(){
    vector<vector<int>> points={{1,2,5},{3,1,1},{3,2,3}};
    cout<<maximumPoints(points,points.size());
}