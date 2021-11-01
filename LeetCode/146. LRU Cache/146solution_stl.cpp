#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {}
    
    int get(int key) {
        const auto it = um_.find(key);
        // If key does not exist
        if (it == um_.cend()) return -1;
 
        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = um_.find(key);
        
        // Key already exists
        if (it != um_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry
        if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            um_.erase(node.first);
            cache_.pop_back();
        }
        
        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value);
        um_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> um_;
};
 
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */