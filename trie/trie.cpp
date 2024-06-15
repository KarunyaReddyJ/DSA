#include<iostream>
using namespace std;
typedef struct {
    node* links[26];
    bool flag;
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void createReference(char ch,node* n){
        links[ch-'a']=n;
    }
    node* getReference(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
}node;
class Trie{
    private:
        node *root;
    public:
        Trie(){
            root=new node();
        }
        void insert(string word){
            node* n=root;
            for(char& ch : word){
                if(!n->containsKey(ch))
                    n->createReference(ch,new node());
                n=n->getReference(ch);
            }
            n->setEnd();
        }
        bool search(string& word){
            node* n=root;
            for(char &ch : word){
                if(!n->containsKey(ch)) return false;
                n=n->getReference(ch);
            }
            return n->isEnd();
        }
        bool startsWith(string& word){
            node* n=root;
            for(char& ch : word){
                if(!n->containsKey(ch)) return;
                n=n->getReference(ch);
            }
            return true;
        }
};