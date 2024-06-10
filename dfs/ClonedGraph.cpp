#include "GraphClass.cpp"
Node* clone(Node* node,map<Node*,Node*>& set){
    if(!node)
        return nullptr;
    auto it=set.find(node);
    if(it!=set.end())
        return it->second;
    Node* newNode=new Node(node->val);
    set[node]=newNode;
    for(Node* neighbour : node->neighbors)
        newNode->neighbors.push_back(clone(neighbour,set));
    return newNode;
}
Node* cloneGraph(Node* node) {
    map<Node*,Node*> set;
    return clone(node,set);
}
