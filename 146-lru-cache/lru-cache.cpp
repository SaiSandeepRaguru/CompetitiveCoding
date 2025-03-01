class Node {
public:
    int key;
    int val;
    int capacity;
    Node* prev;
    Node* next;
    
    Node(int _key,int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int _capacity) {
        head = new Node(-1,-1); //head and tail will always be empty
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        capacity = _capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            moveToHead(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            Node* node = new Node(key,value);
            mp[key]=node;
            insertAtHead(mp[key]);
            if(mp.size()>capacity){
                removeTail();
            }
            return;
        }
        mp[key]->val = value;
        moveToHead(mp[key]);
        return;  
    }
    ~LRUCache() {
        // Delete all nodes in the linked list
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        // Clear the hash map
        mp.clear();
    }

private:
    void insertAtHead(Node* node){
        node->next = head->next; //head should be always dummy;
        node->prev= head;
        head->next->prev = node;
        head->next = node;
    }
    void moveToHead(Node* node){
        removeNode(node);
        insertAtHead(node);
    }
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void removeTail(){
        Node* lastNode = tail->prev; // tail will always be dummy
        removeNode(lastNode);
        mp.erase(lastNode->key);
        delete lastNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */