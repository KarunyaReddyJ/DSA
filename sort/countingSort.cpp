#include<bits/stdc++.h>
using namespace std;
vector<int> countingSort(vector<int>& heights){
    int maxHeight=*max_element(heights.begin(),heights.end());
    int minHeight=*min_element(heights.begin(),heights.end());
    int range=maxHeight-minHeight+1;
    vector<int> count(range,0);
    for(int x : heights)
        count[x-minHeight]++;
    for(int i=1;i<range;i++)
        count[i]+=count[i-1];
    vector<int> output(heights.size(),0);
    for(auto it=heights.rbegin();it!=heights.rend();it++){
        output[count[*it-minHeight]-1]=*it;
        count[*it-minHeight]-=1;
    }
    return output;
}
int heightChecker(vector<int>& heights) {
    vector<int> sorted=countingSort(heights);
    int count=0;
    for(int i=0;i<heights.size();i++)
        count+=heights[i]!=sorted[i]?1:0;
    return count;
}
int main(){
    vector<int> heights={5,1,2,3,4};
    cout<<heightChecker(heights);
}