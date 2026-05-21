class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int> hashy;

        int n = arr1.size();
        int m = arr2.size();
        int globalLength = 0;

        for (size_t i{}; i < n; i++)
        {
            addPrefix(arr1[i], hashy);
        }

        for (size_t i{}; i < m; i++)
        {
            int length = checkPrefix(arr2[i], hashy);
            globalLength = max(globalLength, length);
        }

        return globalLength;
    }

    int checkPrefix(int num, unordered_set<int>& hashy)
    {
        std::string x = to_string(num);
        int length = 0;
        int prefix = 0;

        for (char c : x)
        {
            int digit = c - '0';

            prefix = prefix * 10 + digit;

            if (hashy.count(prefix))
            {
                length += 1;
            }
            else
            {
                //Break cause longer number guarenteed to not work
                break;
            }
        }

        return length;
    }

    void addPrefix(int num, unordered_set<int>& hashy)
    {
        string strNum = to_string(num);
        int prefix = 0;

        for (char c : strNum)
        {
            int digit = c - '0';

            prefix = prefix * 10 + digit;

            hashy.insert(prefix);
        }


    }
};