class MyHashSet {
public:
    MyHashSet() {
        m_hashy.resize(1000001, false);
    }
    
    void add(int key) {
        m_hashy[key] = true;
    }
    
    void remove(int key) {
        m_hashy[key] = false;
    }
    
    bool contains(int key) {
        return m_hashy[key];
    }

private:
    std::vector<bool> m_hashy;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */