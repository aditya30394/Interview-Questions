/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 // capacity // );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it=cache.find(key);
        if(it==cache.end())
            return -1;
        else
        {
            use(it);
            return it->second.first;
        }
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it!=cache.end())
        {
            use(it);
            it->second.first=value;
            return;
        }
        if(cache.size()==this->capacity)
        {
            int last = lru.back();
            lru.pop_back();
            cache.erase(last);
        }
        lru.push_front(key);
        cache.insert( { key, {value, lru.begin()} });
    }
private:
    typedef pair<int,list<int>::iterator> LI;
    list<int>lru;
    unordered_map<int,LI> cache;
    int capacity;
    
    void use(unordered_map<int,LI>::iterator& it)
    {
        lru.erase(it->second.second);
        lru.push_front(it->first);
        it->second.second = lru.begin();
    }
};