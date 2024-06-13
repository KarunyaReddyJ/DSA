#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    int gifts=0;
    for(int i=1;i<=A.size();i++){
        int f1=A[i-1];
        int f2=A[f1-1];
        if(f2==i && i!=f1)
            gifts++;
    }
    return gifts/2;
}

int main(){
//76 58 3 31 26 48 26 3 72 52 40 7 42 6 13 67 56 66 19 9 37 12 19 46 6 42 15 28 33 64 12 14 52 33 60 35 1 56 51 74 57 23 22 19 8 37 27 20 34 64 64 28 22 49 4 13 51 68 4 51 27 71 49 46 21 2 33 16 42 33 25 40 21 59 14 53 52

int n;
cin>>n;
vector<int> v(n,0);
for(int i=0;i<n;i++)
    cin>>v[i];
cout<<solve(v);
}