class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (beginWord == endWord)
        {
            return 1;
        }

        unordered_set<string> hashy(wordList.begin(), wordList.end());

        if (!hashy.count(endWord))
        {
            return 0;
        }

        return bfs(beginWord, endWord, wordList, hashy);
    }

    int bfs(const string& beginWord, const string& endWord, vector<string>& wordList, unordered_set<string>& hashy)
    {
        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});

        while (!queue.empty())
        {
            auto [word, count] = queue.front();
            queue.pop();

            //Check after each pop!
            if (word == endWord)
            {
                return count;
            }

            string temp = word;
            for (int i = 0; i < (int)temp.size(); i++)
            {
                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == original) continue;
                    temp[i] = c;

                    //Check in hashy
                    if (dict.count(temp))
                    {
                        dict.erase(temp);
                        queue.push({temp, count + 1});
                    }
                }

                temp[i] = original;
            }
        }

        return 0;
    }

private:

};