class Solution {
public:
    int minimumPushes(string word) 
    {
        
        std::map<char, int> freq;

        for (int i{}; i < word.size(); i++)
        {
            freq[word[i]] += 1;
        }

        printMap(freq);

        //Pull frequencies out so they can be sorted descending
        std::vector<int> counts;

        for (auto& [key, val] : freq)
        {
            counts.push_back(val);
        }

        std::sort(counts.rbegin(), counts.rend());

        for (int val : counts)
        {
            int cost;
            if (count < 8)
                cost = 1;
            else if (count < 16)
                cost = 2;
            else if (count < 24)
                cost = 3;
            else
                cost = 4;

            res += val * cost;
            count++;
        }

        return res;
    }

    //print map
    template <typename K, typename V>
    void printMap(const std::map<K, V>& m) 
    {
        for (const auto& [key, value] : m) {
            std::cout << key << ": " << value << "\n";
        }
    }

private:
    int count = 0;
    int res = 0;
};