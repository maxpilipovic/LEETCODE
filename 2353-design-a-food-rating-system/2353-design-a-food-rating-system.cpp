class FoodRatings {

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for (size_t i{}; i < foods.size(); i++)
        {
            info[foods[i]] = {cuisines[i], ratings[i]};
            pq[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {

        auto& [cuisine, oldRating] = info[food];
        oldRating = newRating;
        pq[cuisine].push({newRating, food});
        
    }
    
    string highestRated(string cuisine) 
    {
        auto& heap = pq[cuisine];

        while (!heap.empty())
        {
            auto current = heap.top();

            if (info[current.food].first == cuisine && info[current.food].second == current.rating)
            {
                return current.food;
            }

            heap.pop();
        }

        return "";
    }

private:

    struct Node
    {
        int rating;
        string food;
    };

    //Comparator for maxHeap
    struct Cmp
    {
        bool operator()(const Node& a, const Node& b) const
        {
            if (a.rating != b.rating)
            {
                return a.rating < b.rating;
            }

            return a.food > b.food;
        }
    };

    unordered_map<std::string, std::pair<std::string,int>> info; // food -> (cuisine, rating)
    unordered_map<string, priority_queue<Node, vector<Node>, Cmp>> pq; // cuisine -> heap


};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */