#include<bits/stdc++.h>
using namespace std;
void insert(string& str,char c,int ind,int has[]){
    str.push_back(c);
    has[ind]--;
}
void remove(string& str,int ind,int has[]){
    str.pop_back();
    has[ind]++;
}
void generate(string& str,int i,vector<string>& ans,int n,int has[]){
    if(i==2*n){
        ans.push_back(str);
        return;
    }
    if(has[0]>0){
        insert(str,'(',0,has);
        generate(str,i+1,ans,n,has);
        remove(str,0,has);
    }if(has[1]>0 && has[0]<has[1]){
        insert(str,')',1,has);
        generate(str,i+1,ans,n,has);
        remove(str,1,has);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string str="";
    int has[]={n,n};
    generate(str,0,ans,n,has);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> ans=generateParenthesis(n);
    for(string& str : ans)
        cout<<str<<endl;
}