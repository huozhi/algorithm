/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.
*/

class LRUCache{
    struct node {
        node() {}
        node(int v, list<int>::iterator it):value(v), iter(it) { }
        int value;
        list<int>::iterator iter;
    };
    unordered_map<int, node> hasher;
    list<int> cache;
    int sz;
public:
    LRUCache(int capacity) {
        sz = (capacity < 0) ? 0 : capacity;
        cache.clear();
        hasher.clear();
    }

    int get(int key) {
        if (hasher.find(key) != hasher.end()) {
            node n = hasher[key];
            cache.splice(cache.begin(), cache, n.iter);
            hasher[key].iter = cache.begin();
            return n.value;
        }
        return -1;
    }

    void set(int key, int value) {
        unordered_map<int, node>::iterator it = hasher.find(key);
        if (it == hasher.end()) {
            if (sz == cache.size()) {
                int least = cache.back();
                hasher.erase(least);
                cache.pop_back();
            }
        }
        else {
            cache.erase(it->second.iter);
        }
        cache.push_front(key);
        hasher[key] = node(value, cache.begin());
    }
};