class Solution {
public:
    int minimumPushes(string word) 
    {
        std::map<char, int> map;

        for (int i{}; i < word.size(); i++)
        {
            map[word[i]] += 1;
        }

        printMap(map);

        std::vector<int> counts;

        for (auto& [key, val] : map)
        {
            counts.push_back(val);
        }

        std::sort(counts.rbegin(), counts.rend());

        int res = 0;
        int count = 0;
        //Loop in reverse.
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
};