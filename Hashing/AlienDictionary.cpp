#include<bits/stdc++.h>
using namespace std;
bool isAlienSorted(vector<string> &words, string &order) {
    unordered_map<char,int> alphabeticalOrder;
    for(int i=0;i<order.length();i++)
        alphabeticalOrder[order[i]]=i;
    function <bool(string&,string&)> compare=[&](string& first,string& second)->bool{
        for(int i=0;i<min(first.length(),second.length());i++){
            if(alphabeticalOrder[first[i]]>alphabeticalOrder[second[i]])
                return false;
        }
        return true;
    };
    for(int i=0;i<words.size()-1;i++){
        if(!compare(words[i],words[i+1]))
            return false;
    }
    return true;
}
int main(){
    vector<string> words={"word","world","row"};
    string order="worldabcefghijkmnpqstuvxyz";
    cout<<isAlienSorted(words,order);
}