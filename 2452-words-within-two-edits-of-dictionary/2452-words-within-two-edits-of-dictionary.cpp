class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {


        for (auto& q : queries)
        {
            for (auto& d : dictionary)
            {
                int count = 0;

                for (int i{}; i < q.size() && count <= 2; i++)
                {
                    if (q[i] != d[i])
                    {
                        count += 1;
                    }
                }

                if (count <= 2)
                {
                    res.push_back(q);
                    break;
                }
            }
        }

        return res;
    }

private:
    vector<string> res;
};