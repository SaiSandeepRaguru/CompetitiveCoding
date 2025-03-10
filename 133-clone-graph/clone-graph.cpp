/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node){
        if(node==nullptr){
            return nullptr;
        }
        if(mp.find(node)==mp.end()){
            Node* temp = new Node(node->val);
            mp[node]=temp;
            vector<Node*> vt;
            for(Node* x: node->neighbors){
                vt.push_back(dfs(x));
            }
            temp->neighbors = vt;
        }
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        Node* root = dfs(node);
        return root;
    }
};