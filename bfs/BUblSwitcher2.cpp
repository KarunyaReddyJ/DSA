#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> ops;
    string toggle(string& s,string& op){
        string res="";
        for(int i=0;i<s.length();i++){
            if(op[i]=='1') res.push_back('1'-s[i]+'0');
            else res.push_back(s[i]);
        }
        return res;
    }
public:
    Solution(){
       ops=vector<string>(4,"");
    }
    int flipLights(int n, int presses) {
        if(presses==0) return 1;
        string initialState="";
        for(int i=1;i<=n;i++){
             initialState.push_back('1');
             ops[0].push_back('1');
             ops[1].push_back('0'+(i%2==0));
             ops[2].push_back('0'+(i&1));
             ops[3].push_back('0'+(i-1)%3==0);
        }
        queue<pair<string,int>> q;
        set<string> visited,asnwer;
        visited.insert(initialState);
        q.push({initialState,0});
        //bfs

        while(!q.empty()){
            pair<string,int> top=q.front();
            if(top.second==presses) {
                cout<<"answer\n";
                for(string s : asnwer) 
                    cout<<s<<" ";
                cout<<endl;
            return asnwer.size();
            }
            q.pop();
            cout<<top.first<<" "<<top.second<<endl;
            for(string& op : ops){
                string res=toggle(top.first,op);
                cout<<"options\n";
                cout<<op<<" "<<res<<" "<<top.second+1<<endl;
                if(visited.find(res)!=visited.end()) {
                    cout<<"ignored\t";
                    cout<<op<<" "<<res<<" "<<top.second+1<<endl;
                    continue;
                }
                visited.insert(res);
                cout<<"pushed into visited\t"<<res<<endl;
                if(top.second==presses-1){
                    cout<<"res\t"<<res<<endl;
                    asnwer.insert(res);
                }
                q.push({res,top.second+1});
            }
        }
        cout<<'l';
        return asnwer.size();
            }
};
int main(){
    Solution s;
    cout<<"n and presses: ";
    int n,presses;
    cin>>n>>presses;
    cout<<"solution\n";
    cout<<s.flipLights(n,presses);
}