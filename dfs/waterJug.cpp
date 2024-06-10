#include<bits/stdc++.h>
using namespace std;

bool solve(int x,int y,int capx,int capy,int target,set<pair<int,int>>& set){
    if(x==target || y==target || x+y==target)
        return true;
    else if(set.find({x,y})!=set.end())
        return false;
    set.insert({x,y});
    if (solve(capx, y, capx, capy, target, set)) return true;
    if (solve(x, capy, capx, capy, target, set)) return true;
    if (solve(0, y, capx, capy, target, set)) return true;
    if (solve(x, 0, capx, capy, target, set)) return true;
    if (solve(x - min(x, capy - y), y + min(x, capy - y), capx, capy, target, set)) return true;
    if (solve(x + min(y, capx - x), y - min(y, capx - x), capx, capy, target, set)) return true;
}
bool canMeasureWater(int x, int y, int target) {
      set<pair<int,int>> set;
    return false || solve(0,0,x,y,target,set);
}
int main(){
    int x,y,target;
    cin>>x>>y>>target;
    cout<<canMeasureWater(x,y,target);
}
