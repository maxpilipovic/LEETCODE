using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {

        string res;
        int lowestSize;
        //unordered_map<char, int> currMap;
        unordered_map<char, int> tMap;
        int left = 0;
        //1. Fill our maps. 

        //Fill our t map
        for (int i = 0; i < t.size(); i++)
        {
            tMap[t[i]] += 1; 
        }

        int required = tMap.size();
        int formed = 0;
        unordered_map<char, int> currMap;

        int minLen = INT_MAX;
        int minLeft = 0;

        //Condition for moving left pointer...
        for (int right = 0; right < s.size(); right++)
        {
            currMap[s[right]] += 1;

            //Adds to map to compare
            if (tMap.count(s[right]) && currMap[s[right]] == tMap[s[right]])
            {
                formed++;
            }
            
            //Do we really need this?
            //actualString.push_back(s[i])

            //while 
            //Bounds & and if have required chars in tMap.
            while (left <= right && formed == required)
            {
                if (right - left + 1 < minLen)
                {
                   minLen = right - left + 1;
                   minLeft = left;
                }

                currMap[s[left]]--;
                if (tMap.count(s[left]) && currMap[s[left]] < tMap[s[left]])
                {
                    formed--;
                }
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);
    }
};