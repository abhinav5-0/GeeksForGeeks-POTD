class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Map to store key and its iterator in the list

public:
    // Constructor to initialize cache with the given capacity
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }

        // Move the accessed key-value pair to the front of the list (most recently used)
        auto it = cacheMap[key];
        int value = it->second;
        cacheList.erase(it);
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();

        return value;
    }

    // Function to store key-value pair
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key already exists, update the value and move to the front
            auto it = cacheMap[key];
            cacheList.erase(it);
        } else if (cacheList.size() == capacity) {
            // Cache is full, remove the least recently used item
            auto lru = cacheList.back();
            cacheMap.erase(lru.first);
            cacheList.pop_back();
        }

        // Insert the new key-value pair at the front
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};
