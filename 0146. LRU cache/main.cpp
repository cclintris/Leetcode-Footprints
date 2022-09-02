#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

/**
 * I: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * O: [null, null, null, 1, null, -1, null, -1, 3, 4]
    Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
 */

class LRUCache {
   public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = m_.find(key);
        // If key does not exist
        if (it == m_.end()) return -1;

        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it = m_.find(key);

        // Key already exists
        if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }

        // Reached the capacity, remove the oldest entry
        if (cache_.size() == capacity_) {
            pair<int, int> node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }

        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }

   private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};

int main(int argc, char const* argv[]) {
    return 0;
}
