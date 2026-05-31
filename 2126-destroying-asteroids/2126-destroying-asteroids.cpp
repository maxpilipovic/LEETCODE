class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        int n = asteroids.size();

        //Sort
        std::sort(asteroids.begin(), asteroids.end());

        long long planet = mass;

        for (int i{}; i < n; i++)
        {
            q.push(asteroids[i]);
        }

        return DestroyAsteroids(planet);
    }

    bool DestroyAsteroids(long long planet)
    {
        int n = q.size();

        for (int i{}; i < n; i++)
        {
            int asteroid = q.front();
            q.pop();

            if (planet >= asteroid)
            {
                planet += asteroid;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

private:
    std::queue<int> q;
};