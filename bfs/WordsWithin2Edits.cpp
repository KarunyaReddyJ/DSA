#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> answer;
public:
    int letterDifferences(string& s1,string& s2){
        int mismatch=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                mismatch++;
                if(mismatch>2) return -1;
            }
        }
        return mismatch;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for(string& s1 : queries){
            for(string& s2 : dictionary){
                int diff=letterDifferences(s1,s2);
                if(diff!=-1){ answer.push_back(s1); break;}
            }
        }
        return answer;
    }
};
int main(){
    Solution s1;
    vector<string> queries={"word","note","ants","wood"},dictionary={"wood","joke","moat"};
    vector<string> answer=s1.twoEditWords(queries,dictionary);
    for(string&s : answer) cout<<s<<" ";
}