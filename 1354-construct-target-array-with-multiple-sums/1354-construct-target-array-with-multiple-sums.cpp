class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        priority_queue<long long> pq(target.begin(), target.end());

        long long total = 0;

        //Add every element to total.
        for (int x : target)
        {
            total += x;
        }

        while (pq.top() != 1)
        {
            //Grab top
            long long mx = pq.top();
            long long rest = total - mx;

            //Pop
            pq.pop();

            //Base Cases
            if (rest == 1)
            {
                return true;
            }

            //If rest is 0 obviously does not work. If rest is greater then mx it would not work cause then neg.
            if (rest == 0 || rest >= mx)
            {
                return false;
            }

            //Update prev. Its always the remainder, we are going back a step (CHECK EXAMPLE)
            long long prev = mx % rest;
            if (prev == 0)
            {
                return false;
            }

            //Update the sum with the old value.
            total = rest + prev;

            //Put the old value back in the heap.
            pq.push(prev);
        }

        return true;
    }

private:

};