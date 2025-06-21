class Node {
public:
    int val,key;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->val=val;
        this->key=key;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    map<int, Node*> mpp;
    int cap=0;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head->next=tail;
        tail->prev=head;
    }
    void deleteBack(Node * node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        // mpp.erase(node->key);
    }
    void insertFront(Node* node){
        node->prev=head;
        node->next=head->next;
        head->next=node;
        node->next->prev=node;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* temp=mpp[key];
            deleteBack(temp);
            insertFront(temp);
        return temp->val;
        }
            return -1;
        
    }
    
    void put(int key, int value) {
            if(mpp.find(key)!=mpp.end()){
                Node* temp=mpp[key];
                temp->val=value;
                deleteBack(temp);
                insertFront(temp);
                mpp[key]=temp;
            return;
            }
            else{
        if(mpp.size()==cap){
                mpp.erase(tail->prev->key);
                deleteBack(tail->prev);
            }
        Node * node=new Node(key,value);
        insertFront(node);
        mpp[key]=node;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */