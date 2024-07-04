#include<bits/stdc++.h>
using namespace std;
class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
            int t=q.front();
            q.pop();
            q.push(t);
        }
    }
    
    int pop() {
        int t=q.front();
        q.pop();
        return 1;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */