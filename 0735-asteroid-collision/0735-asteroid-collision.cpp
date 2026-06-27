class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        std::stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            bool alive = true;

            //Greater DIRECTION
            if (asteroids[i] > 0)
            {
                stack.push(asteroids[i]);
            }
            else 
            {
                //Less DIRECTION
                while (!stack.empty() && stack.top() > 0 && abs(asteroids[i]) >= abs(stack.top()))
                {
                    //SAME DESTROY BOTH
                    if (abs(asteroids[i]) == abs(stack.top()))
                    {
                        stack.pop();
                        alive = false;
                        break;
                    }

                    stack.pop();
                }

                if (!stack.empty() && stack.top() > 0 && abs(asteroids[i]) < abs(stack.top()))
                {
                    alive = false;
                }

                //Finally add
                if (alive)
                {
                    stack.push(asteroids[i]);
                }
            }
        }

        while (!stack.empty())
        {
            res.push_back(stack.top());
            stack.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }

private:
    vector<int> res;
};