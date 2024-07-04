#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    stack<int> main,buffer;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        while(main.size()>1){
            buffer.push(main.top());
            main.pop();
        }
        int top=main.top();
        main.pop();
        while(!buffer.empty()){
            main.push(buffer.top());
            buffer.pop();
        }
        return top;
    }
    
    int peek() {
        while(main.size()>1){
            buffer.push(main.top());
            main.pop();
        }
        int top=main.top();
        while(!buffer.empty()){
            main.push(buffer.top());
            buffer.pop();
        }
        return top;
    }
    
    bool empty() {
        return main.size()==0;
    }
};