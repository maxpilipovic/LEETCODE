class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int left = 0;
        int resMax = 0;
        std::unordered_map<int, int> map;

        for (int right = 0; right < fruits.size(); right++)
        {
            map[fruits[right]] += 1;

            while (map.size() > 2)
            {
                map[fruits[left]]--;

                if (map[fruits[left]] == 0)
                {
                    map.erase(fruits[left]);   
                }
                left++;
            }
            
            //Max
            resMax = std::max(resMax, right - left + 1);
        }

        return resMax;
    }
};