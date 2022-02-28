// https://leetcode.com/problems/lru-cache/submissions/
class LRUCache {
public:
    
    
class Node {
public:
    int data;
    int key;
    Node* next;
    Node* prev;
    
    Node(int eleK, int eleV){
        data = eleV;
        key= eleK;
        next=NULL;
        prev=NULL;
    }
    
};

unordered_map<int,Node*> m;
int cap;
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap=capacity;
        
        head->next=tail;
        tail->prev=head;
        
        
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            Node * ele = m[key];
            int retResult = ele->data;
            ele->next->prev=ele->prev;
            ele->prev->next=ele->next;
            ele->next=head->next;
            ele->prev=head;
            head->next->prev=ele;
            head->next=ele;
            return retResult;
            
        }
        
    }
    
    void put(int key, int value) {
        // if(cap)
        
        if(m.find(key)==m.end()){
            // key not found;
//          code   capacity check;
            if(m.size()<cap){
                Node* ele= new Node(key,value);
                m[key]=ele;
                ele->next = head->next;
                ele->prev=head;
                head->next->prev=ele;
                head->next = ele;
            }
            else{
                Node * ele = tail->prev;
                m.erase(ele->key);
                ele->key = key;
                ele->data = value;
                m[key]=ele;
                ele->next->prev=ele->prev;
                ele->prev->next=ele->next;
                ele->next=head->next;
                ele->prev=head;
                head->next->prev=ele;
                head->next=ele;
                
                
                
                
                
            }
            
            
            
            
        }
        else{
            // key found;
            m[key]->data = value;
            
            Node * ele = m[key];
            ele->next->prev=ele->prev;
            ele->prev->next=ele->next;
            ele->next=head->next;
            ele->prev=head;
            head->next->prev=ele;
            head->next=ele;
            
            
            
            
            
        }
        
        
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */