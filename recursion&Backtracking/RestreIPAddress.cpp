#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> ipAddresses;
public:
    vector<string> restoreIpAddresses(string s) {
        string myString="";
        recursion(s,0,myString,3);
        return ipAddresses;
    }
private:
    long long number(string& s,int index,int lastInd=1){
        long long num=0;
        lastInd=s.length()-1;
        for(int i=index;i<=lastInd;i++)
            num=num*10+(s[i]-'0');
        return num;
    }
    void recursion(string& s,int index,string& myString,int dots){
        if(dots==0){
            long long num=number(s,index);
            if(num>=0 && num<256) ipAddresses.push_back(myString);
            return;
        }
        for(int i=index;i<s.length()-1-dots;i++){
            long long num=number(s,index,i);
            if(num>=0 && num<256){
                string temp=myString;
                 myString+=s.substr(index,i-index+1);
                 myString.push_back('.');
                 recursion(s,i+1,myString,dots-1);
                 myString.pop_back();
                 myString=temp;
            }
            else if(num>=256) return;
        }
    } 
};
int main(){

}