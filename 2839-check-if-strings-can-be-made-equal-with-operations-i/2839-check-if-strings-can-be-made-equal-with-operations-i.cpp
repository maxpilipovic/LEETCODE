class Solution {
public:
    bool canBeEqual(string s1, string s2) 
    {
        int n = s1.size();

        if (s1 == s2)
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j - i == 2)
                {
                    std::string temp = s1;

                    char c = temp[i];
                    temp[i] = temp[j];
                    temp[j] = c;

                    if (temp == s2)
                    {
                        return true;
                    }

                    for (int x = 0; x < n; x++)
                    {
                        for (int y = x; y < n; y++)
                        {
                            if (y - x == 2)
                            {
                                string temp2 = temp;
                                swap(temp2[x], temp2[y]);

                                if (temp2 == s2)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};