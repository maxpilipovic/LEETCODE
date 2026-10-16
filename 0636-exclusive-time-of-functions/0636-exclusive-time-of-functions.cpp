class Solution {
public:

    struct Log
    {
        int id;
        bool isStart;
        int time;
    };

    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        
        std::stack<Log> stack;
        std::vector<int> res(n, 0);

        for (int i{}; i < logs.size(); i++)
        {
            const std::string& s = logs[i];

            size_t first  = s.find(':');
            size_t second = s.find(':', first + 1);

            Log log;
            log.id = std::stoi(s.substr(0, first));
            log.isStart = s[first + 1] == 's';
            log.time = std::stoi(s.substr(second + 1));

            if (log.isStart)
            {
                if (!stack.empty())
                {
                   res[stack.top().id] += log.time - stack.top().time;
                }

                stack.push(log);
            }
            else
            {
                res[stack.top().id] += log.time - stack.top().time + 1;
                stack.pop();

                if (!stack.empty())
                {
                    stack.top().time = log.time + 1;
                }
            }

        }

        return res;    
    }
private:

};