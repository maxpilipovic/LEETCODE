class Solution {
public:
    int minDeletions(string s) {
        std::unordered_map<char, int> my_dict;
        int res = 0;
        std::set<int> hashy;

        for (char i : s)
        {
            my_dict[i]++;
        }


        for (auto& [key, freq] : my_dict)
        {
            std::cout << "Key: " << key << ", Frequency: " << freq << std::endl;

            while (hashy.count(freq) && freq > 0)
            {
                res++;
                my_dict[key]--;
            }
            hashy.insert(freq);
        }

        return res;
    }
};