class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        unordered_set<int> visited;
        unordered_set<int> res;
        unordered_map<int, vector<int>> adjList = createAdjList(invocations);    

        printAdjList(adjList);

        //Do the dfs
        dfs(adjList, n, k, visited, res);

        bool blocked = false;
        
        for (auto& inv : invocations)
        {
            int a = inv[0];
            int b = inv[1];

            if (res.count(b) && !res.count(a))
            {
                blocked = true;
                break;
            }
        }

        vector<int> x;

        if (blocked)
        {
            for (int i{}; i < n; i++)
            {
                //Return everything
                x.push_back(i);
            }
        }
        else
        {
            for (int i{}; i < n; i++)
            {
                if (!res.count(i))
                {
                    x.push_back(i);
                }
            }
        }

        return x;
    }

    void dfs(unordered_map<int, vector<int>>& adjList, int n, int k, unordered_set<int>& visited, unordered_set<int>& res)
    {
        //dfs

        //Base Case. If inside hashy
        if (visited.count(k))
        {
            return;
        }

        visited.insert(k);
        res.insert(k);

        //Recursive case
        for (int neighbor : adjList[k])
        {
            if (!res.count(neighbor))
            {
                dfs(adjList, n, neighbor, visited, res);
            }
        }
    }

    std::unordered_map<int, vector<int>> createAdjList(vector<vector<int>>& invocations)
    {
        std::unordered_map<int, vector<int>> res;

        for (auto& pair : invocations)
        {
            int a = pair[0];
            int b = pair[1];

            //Add to map
            res[a].push_back(b);
        }

        return res;
    }

    void printAdjList(const std::unordered_map<int, std::vector<int>>& adjList)
    {
        for (const auto& [key, neighbors] : adjList)
        {
            std::cout << key << " -> [";
            for (size_t i = 0; i < neighbors.size(); ++i)
            {
                std::cout << neighbors[i];
                if (i != neighbors.size() - 1) std::cout << ", ";
            }
            std::cout << "]\n";
        }
    }

private:

};