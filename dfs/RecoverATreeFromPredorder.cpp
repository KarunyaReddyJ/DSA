#include<bits/stdc++.h>
#include "TreeStruct.cpp"
using namespace std;
int to_number(string num){
    int number=0;
    for(char c: num)
        number+=number*10+(c-'0');
    return number;
}
void comprehend(string& traversal,int& ind,int& number,int& depth){
    while(ind<traversal.length() && traversal[ind]=='-'){
        ind++;
        depth++;
    }
    int start=ind;
    while(ind<traversal.length() && traversal[ind]!='-')
        ind++;
    number=to_number(traversal.substr(start,ind-start+1));
}
TreeNode* recoverFromPreorder(string traversal) {
    int ind=0,curDepth=0,number=0;
    comprehend(traversal,ind,number,curDepth);
    TreeNode* root=new TreeNode(number);
    return recover(traversal,ind,++curDepth);
}
TreeNode* recover(string& traversal,int& ind,int& curDepth){
    if(ind==traversal.length())
        return nullptr;
    int depth=0,number=0;
    comprehend(traversal,ind,number,depth);
    if()
}
int main(){

}