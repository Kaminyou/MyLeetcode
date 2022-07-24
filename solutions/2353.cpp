class FoodRatings {
public:
    unordered_map<string, map<int, set<string>>> cuisine2food;
    unordered_map<string, pair<int, string>> food2cuisineAndRate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            cuisine2food[cuisines[i]][ratings[i]].insert(foods[i]);
            food2cuisineAndRate[foods[i]] = make_pair(ratings[i], cuisines[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [prevRating, cuisine] = food2cuisineAndRate[food];
        cuisine2food[cuisine][prevRating].erase(food);
        if (cuisine2food[cuisine][prevRating].empty()) {
            cuisine2food[cuisine].erase(prevRating);
        }
        cuisine2food[cuisine][newRating].insert(food);
        
        food2cuisineAndRate[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        auto foodSet = cuisine2food[cuisine].rbegin()->second;
        return *foodSet.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */