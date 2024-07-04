#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<char,int> charCount;
    unordered_map<string,char> WordToDigitMap;
    string res="";
public:
Solution(){
    WordToDigitMap={
        {"zero",'0'},
        {"one",'1'},
        {"two",'2'},
        {"three",'3'},
        {"four",'4'},
        {"five",'5'},
        {"six",'6'},
        {"seven",'7'},
        {"eight",'8'},
        {"nine",'9'}
    };
}
    string originalDigits(string s) {
        for(char & c : s) 
            charCount[c]++;
        for(auto x : WordToDigitMap){
            int minFreq=wordToDigits(x.first);
            for(int i=1;i<=minFreq;i++) 
                res.push_back(x.second);
        }
        return res;
    }
private:
    int wordToDigits(string s){
        int minFreq=INT_MAX;
        for(char& c : s)
            minFreq=min(minFreq,charCount[c]);
        if(minFreq){
            for(char& c : s){ 
                charCount[c]-=minFreq;
                if(charCount[c]==0) charCount.erase(c);
            }
        }
        return minFreq;
    }   
};
int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.originalDigits(str);
}