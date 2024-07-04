#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* head=nullptr,*t=nullptr;
//         for(int c=0;c<lists.size();){
//             int minIndex=-1,minValue=INT_MAX;
//             for(int i=0;i<lists.size();i++){
//                 if(lists[i]!=nullptr && lists[i]->val<minValue){ 
//                     minIndex=i;
//                     minValue=lists[i]->val;
//                 }
//             }
//             if(minValue==INT_MAX) return head;
//             if(t==nullptr){
//                 t=new ListNode(lists[minIndex]->val);
//                 head=t;
//                 lists[minIndex]=lists[minIndex]->next;
//                 if(lists[minIndex]==nullptr) c++;
//                 continue;
//             }
//             t->next=new ListNode(lists[minIndex]->val);
//             t=t->next;
//             lists[minIndex]=lists[minIndex]->next;
//             if(lists[minIndex]==nullptr) c++;
//         }
//         return head;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct comapre{
    bool operator()(const& ListNode* a,const& ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr,*t=nullptr;
        priority_queue<ListNode*,vector<ListNode*>,comapre> pq;
        for(ListNode* list : lists) pq.push(list);
        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            if(t==nullptr){
                t=new ListNode(temp->val);
                head=t;
                if(temp->next) pq.push(temp->next);
                continue;
            }
            t->next=new ListNode(temp->val);
            t=t->next;
            if(temp->next) pq.push(temp->next);
        }
        return head;
    }
};
int main(){

}