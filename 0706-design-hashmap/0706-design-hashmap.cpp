class MyHashMap {
public:

    using Bucket = std::vector<std::pair<int, int>>; //refers
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = hash(key);

        Bucket& bucket = m_buckets[index];

        for (auto& [k, v] : bucket)
        {
            if (k == key)
            {
                //Update our value
                v = value;
                return;
            }
        }
        //Does not exist 
        bucket.emplace_back(key, value);
    }
    
    int get(int key) {
        int index = hash(key);
        Bucket& bucket = m_buckets[index];

        for (const auto& [k, v] : bucket)
        {
            if (k == key)
            {
                return v;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        Bucket& bucket = m_buckets[index];
        
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->first == key)
            {
                //Remove
                bucket.erase(it);
                return;
            }
        }
    }

private:
    
    static constexpr int BUCKET_COUNT = 1009;

    uint32_t hash(int32_t value) 
    {
        static constexpr uint32_t FNV_OFFSET_BASIS = 2166136261u;
        static constexpr uint32_t FNV_PRIME = 16777619u;
        
        uint32_t hash = FNV_OFFSET_BASIS;
        
        // Hash each byte of the integer
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&value);
        for (size_t i = 0; i < sizeof(value); ++i) 
        {
            hash ^= bytes[i];
            hash *= FNV_PRIME;
        }
        
        return hash % BUCKET_COUNT; //valid index into bucket array.
    }

    std::array<Bucket, BUCKET_COUNT> m_buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */