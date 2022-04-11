class LRUCache {
       list<pair<int,int>>l;
        unordered_map<int,list<pair<int,int>>::iterator> m;
    int s,mx;
    
public:
    LRUCache(int capacity) {
        s=0;
        mx=capacity;
    }
    
    int get(int key) {
         if(m.find(key)!=m.end())
        {
            int value=m[key]->second;
            l.erase(m[key]);
            l.push_front({key,value});
            m[key]=l.begin();
            return value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            l.erase(m[key]);
            s--;
        }
        
        l.push_front({key,value});
        m[key]=l.begin();
        s++;
        
        if(s>mx)
        {
            m.erase(l.back().first);
            l.pop_back();
            s--;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
class LRUCache {
public:
    int capacity, size;
    struct node{
        int key, value;
        node *next, *prev;
    }*head, *tail;
    map<int, node*> n;
    
    LRUCache(int capacity) {
        capacity = capacity;
        size = 0;
        head = tail = NULL;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) 
            return -1;
        node *temp = m[key];
        if(temp == head)
            return temp->value;
        if(temp == tail)
            return temp->prev;
        if(temp->prev)
            temp->prev->next = temp->next;
        if(temp->next)
            temp->next->prev = temp->prev;
        temp->prev = NULL;
        temp->next = head;
        head = temp;
        return temp->value;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        
        if(size == 0) {
            head = tail = new node();
            head->key = key;
            head->value = value;
            head->prev = head->next = NULL;
            m[key] = head;
            return ;
        }
        if(size == capacity) {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            size--;
            m.erase(key);
            delete key;
        }
        node *temp = new node();
        temp->key = key;
        temp->value = value;
        temp->prev = NULL;
        temp->next = head;
        m[key] = temp;
        size++;
        head->prev = temp;
        head = temp;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
