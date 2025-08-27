class Solution {
public:

    //1.UNION-FIND
    //ADJACENCY + DFS. <>
    unordered_map<string, vector<string>> buildAdjList(vector<vector<string>>& accounts, unordered_map<string, string>& emailToName)
    {
        unordered_map<string, vector<string>> graph;
        //int n = accounts.size();

        for (const auto& acc : accounts)
        {
            //Grab our first value
            string name = acc[0];
            //1. Check if key value exists.
            
            for (int i = 1; i < acc.size(); i++)
            {
                for (int j = i + 1; j < acc.size(); j++) 
                {
                    graph[acc[i]].push_back(acc[j]);
                    graph[acc[j]].push_back(acc[i]);
                }
                
                //accounttoName
                emailToName[acc[i]] = name;
            }
        }
        return graph;
    }

    void printGraph(unordered_map<string, vector<string>> graph)
    {
        //Print
        for (const auto& [key, value] : graph)
        {
            cout << key << "->";
        
            for (int i = 0; i < value.size(); i++)
            {
                cout << value[i];

                if (i < value.size() - 1) cout << ", ";
            }
            cout << std::endl;
        }
    }

    void dfs(string email, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<string>& currentAccount)
    {
        
        //Base Case
        if (visited.find(email) != visited.end())
        {
            return;
        }

        visited.insert(email);
        currentAccount.push_back(email);

        for (const auto& neighbor : graph[email])
        {
            dfs(neighbor, graph, visited, currentAccount);
        }

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //Adjacency List
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph = buildAdjList(accounts, emailToName);
        vector<vector<string>> res;
        unordered_set<string> visited;

        //Print
        printGraph(graph);

        //DFS Implementation. <>
        for (const auto& [email, name] : emailToName)
        {
            if (visited.find(email) == visited.end())
            {
                vector<string> currentAccount;
                
                //dfs
                dfs(email, graph, visited, currentAccount);

                //Sort
                std::sort(currentAccount.begin(), currentAccount.end());

                //Append in specific spot
                currentAccount.insert(currentAccount.begin(), name);
                res.push_back(currentAccount);
            }
        }

        return res;
    }

private:


};