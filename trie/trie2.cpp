#include <bits/stdc++.h> 
using namespace std;
struct node{
    pair<node*,int> links[26];
    bool flag;
    int allWords;
    int noOfWords;
    node(){
        noOfWords=0;
        flag=false;
        allWords=0;
    }
    bool containKey(char c){
        return links[c-'a'].first!=nullptr;
    }
    void createKey(char c,node* n){
        links[c-'a']={n,0};
    }
    void insertKey(char c){
        links[c-'a'].second+=1;
        allWords+=1;
    }
    void deleteKey(char c){
        links[c-'a'].second-=1;
        allWords-=1;
    }
    node* getReference(char c){
        if(containKey(c))  return links[c-'a'].first;
    }
    void markEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    int getWordsEndingWith(char c){
        node* next=getReference(c);
        return links[c-'a'].second-next->allWords;
    }
    int getWordsMatchingWith(char c){
        return links[c-'a'].second;
    }
    ~node(){
        
    }
};
class Trie{
    node* root;
    public:

    Trie(){
        // Write your code here.
        root=new node();
    }

    void insert(string &word){
        node* n=root;
        for(char& c : word){
            if(!n->containKey(c)) n->createKey(c,new node());
            n->insertKey(c);
            n=n->getReference(c);
        }
        n->markEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        node* temp=root;
        for(int i=0;i<word.length()-1;i++){
            temp=temp->getReference(word[i]);
        }
        return temp->getWordsEndingWith(word.back());
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        node* temp=root;
        for(int i=0;i<word.length()-1;i++){
            temp=temp->getReference(word[i]);
        }
        return temp->getWordsMatchingWith(word.back());
    }

    void erase(string &word){
        // Write your code here.
        node* temp=root,*prev=nullptr;
        for(int i=0;i<word.length()-1 && temp->allWords-1;i++){
            prev=temp;
            temp=temp->getReference(word[i]);
        }
        // if(temp->allWords==1){
            
        // }
        node* last=temp->getReference(word.back());
        if(last->allWords!=0)
            temp->deleteKey(word.back());
        delete last;
        temp->
    }
};
int main(){
    vector<string> words={"apple","app","apex","bagger"};
    Trie* root=new Trie();
    for(string& word : words)
        root->insert(word);
    cout<<root->countWordsEqualTo(words[1])<<endl;
    cout<<root->countWordsEqualTo(words[2])<<endl;
    string parameter="app";
    cout<<root->countWordsStartingWith(parameter)<<endl;
}