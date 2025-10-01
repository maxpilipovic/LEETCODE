class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        if (firstList.empty() || secondList.empty())
        {
            return {};
        }

        for (int i = 0; i < firstList.size(); i++)
        {
            vector<int> currInterval = firstList[i];

            for (int j = 0; j < secondList.size(); j++)
            {
                vector<int> secondInterval = secondList[j];

                if (currInterval[0] <= secondInterval[1] && secondInterval[0] <= currInterval[1])
                {
                    //We found an overlapped interval
                    res.push_back({std::max(currInterval[0], secondInterval[0]), 
                                   std::min(currInterval[1], secondInterval[1])});
                }
            }
        }

        return res;
    }

private:
    vector<vector<int>> res; 
};