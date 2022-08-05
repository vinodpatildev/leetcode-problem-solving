class LRUCache {
public:
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator> cache_key_map;
    list<pair<int,int>> cache_lru_queue;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache_key_map.count(key)){
            pair<int,int> p = *cache_key_map[key];
            cache_lru_queue.erase(cache_key_map[key]);
            
            cache_lru_queue.push_back(p);
            cache_key_map[key] = --cache_lru_queue.end(); 
            
            return p.second;            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache_key_map.count(key)){
            pair<int,int> p = *cache_key_map[key];
            
            p.second = value;
            cache_lru_queue.erase(cache_key_map[key]);
            
            cache_lru_queue.push_back(p);
            cache_key_map[key] = --cache_lru_queue.end(); 
            
            return;            
        }
        
        if(cache_lru_queue.size()<capacity){
            cache_lru_queue.push_back(make_pair(key,value));
            cache_key_map[key] = (--cache_lru_queue.end());
        }else{
            cache_key_map.erase((*cache_lru_queue.begin()).first);
            cache_lru_queue.erase(cache_lru_queue.begin());
            
            cache_lru_queue.push_back(make_pair(key,value));
            cache_key_map[key] = --cache_lru_queue.end();            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */