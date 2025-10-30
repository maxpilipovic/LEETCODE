class Solution {
public:

    Solution() 
    {
        parent.resize(10001);
        size.resize(10001, 1);

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < accounts.size(); i++)
        {
            //Start from j = 1 cause j = 0 is email...
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                
                //If email is there already, we union.
                if (emailToAccount.count(email))
                {
                    uunion(i, emailToAccount[email]);
                }
                else
                {
                    //If not there, add.
                    emailToAccount[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> merged;

        for (auto[email, idx] : emailToAccount)
        {
            int root = find(idx);
            merged[root].push_back(email);
        }

        vector<vector<string>> result;

        for (auto[idx, vec] : merged)
        {
            sort(vec.begin(), vec.end());
            vector<string> account;
            account.push_back(accounts[idx][0]);
            account.insert(account.end(), vec.begin(), vec.end());
            result.push_back(account);
        }

        return result;
    }


private:
    vector<int> parent;
    vector<int> size;

    int find(int x)
    {
        if (parent[x] != x)
        {
            return find(parent[x]);
        }

        return parent[x];
    }

    void uunion(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY)
        {

            if (size[rootX] < size[rootY])
            {
                parent[rootY] = rootX;
                size[rootX] += rootY;
            }
            else 
            {
                parent[rootX] = rootY;
                size[rootY] += rootX;
            }
        }
    }

};