class FrequencyTracker {
public:
    FrequencyTracker() {}
    
    void add(int number) { //2
        int oldFreq = m_numCount[number]; //1
        int newFreq = m_numCount[number] + 1; //2
        m_numCount[number] = newFreq; //2

        if (oldFreq > 0) 
        {
            m_freqCount[oldFreq]--;

            if (m_freqCount[oldFreq] == 0)
            {
                m_freqCount.erase(oldFreq);
            }
        }

        m_freqCount[newFreq]++;
    }
    
    void deleteOne(int number) {

        if (m_numCount[number] == 0)
        {
            return;
        }
        
        int oldFreq = m_numCount[number];
        int newFreq = m_numCount[number] - 1;
        m_numCount[number] = newFreq;

        if (m_numCount[number] == 0)
        {
            m_numCount.erase(number);
        }

        if (oldFreq > 0)
        {
            m_freqCount[oldFreq]--;

            if (m_freqCount[oldFreq] == 0)
            {
                m_freqCount.erase(oldFreq);
            }
        }

        m_freqCount[newFreq]++;
    }
    
    bool hasFrequency(int frequency) {
        
        if (m_freqCount.count(frequency) > 0)
        {
            return true;
        }
        return false;
    }
private:
    std::unordered_map<int, int> m_numCount;
    std::unordered_map<int, int> m_freqCount;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */