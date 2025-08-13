class LRUCache {
public:

    
    LRUCache(int capacity) : m_capacity(capacity) {
    }

    
    int get(int key) {
        
        auto it = m_cache.find(key);
        if (it == m_cache.end())
        {
            return -1;
        }

        //Move the item? .splice?
        m_lruList.splice(m_lruList.begin(), m_lruList, it->second);
        //Return the value of the key.
        return it->second->second;
    }
    
    void put(int key, int value) {
        
        //Step 1 -> Check if the key exists.
        //Step 2 -> If it does not exist we add to the key-value pair.
        //Step 3 -> If the number of keys exceeds capacity, evict LRU key.

        //Check if key exists
        auto it = m_cache.find(key);
        if (it == m_cache.end())
        {
            //Not in map. Check capacity
            if (m_cache.size() == m_capacity)
            {
                //Delete least recently used node. AND map.
                auto lruKey = m_lruList.back().first;
                m_lruList.pop_back();
                m_cache.erase(lruKey);
            }

            //Put in new value
            m_lruList.push_front({key, value});
            m_cache[key] = m_lruList.begin();
        }
        else 
        {
            //Step 1: Update value of key if key exists
            //Step 2: Move to front
            auto listIt = it->second;
            listIt->second = value;

            //Move to front
            m_lruList.splice(m_lruList.begin(), m_lruList, listIt);

            return;

        }
        //If we are at capacity, evict least recently used item
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;
    std::list<std::pair<int, int>> m_lruList;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */