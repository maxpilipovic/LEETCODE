class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n = sandwiches.size();

        //(num, -1)
        std::queue<std::pair<int, int>> queue;

        //num(num, no. num inputted in stack)
        std::stack<std::pair<int, int>> stack;

        for (int i = n - 1; i >= 0; i--)
        {
            stack.push({sandwiches[i], i});
        }

        for (int i{}; i < n; i++)
        {
            queue.push({students[i], -1});
        }

        while (!queue.empty())
        {
            auto [queueNum, queueIndex] = queue.front();
            auto [stackNum, stackIndex] = stack.top();

            if (queueNum == stackNum && queueIndex != stackIndex)
            {
                stack.pop();
                queue.pop();
            }
            else if (queueIndex == stackIndex)
            {
                //We've hit the same value again. Return
                return queue.size();
            }
            else 
            {
                queue.pop();
                queue.push({queueNum, stackIndex});
            }
        }

        return 0;
    }

    void printQueue(std::queue<int> q) 
    {
        std::cout << "[";
        while (!q.empty()) {
            std::cout << q.front();
            q.pop();
            if (!q.empty()) std::cout << ", ";
        }
        std::cout << "]\n";
    }


private:
    int count = 0;
};