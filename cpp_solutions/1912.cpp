class MovieRentingSystem {
public:
    unordered_map<long long, int> shopMovice2price;
    unordered_map<int, set<long long>> movie2PriceShop;
    set<long long> rentedMovie;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            long long shopMovie = ((long long)shop << 22) + movie;
            shopMovice2price[shopMovie] = price;
            movie2PriceShop[movie].insert(((long long)price << 22) + shop);
        }
    }
    
    vector<int> search(int movie) {
        // movie -> 5 top {price, shop}
        vector<int> res;
        auto& s = movie2PriceShop[movie];
        auto it = s.begin();
        while (it != s.end() && res.size() < 5) {
            long long val = *it;
            int price = val >> 22;
            int shop = val & ((1 << 22) - 1);
            res.push_back(shop);
            it++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = shopMovice2price[((long long)shop << 22) + movie];
        movie2PriceShop[movie].erase(((long long)price << 22) + shop);
        rentedMovie.insert(((long long)price << 44) + ((long long)shop << 22) + movie);
    }
    
    void drop(int shop, int movie) {
        int price = shopMovice2price[((long long)shop << 22) + movie];
        rentedMovie.erase(((long long)price << 44) + ((long long)shop << 22) + movie);
        movie2PriceShop[movie].insert(((long long)price << 22) + shop);
    }
    
    vector<vector<int>> report() {
        // 5 cheapest rented movie {price, shop, movie}
        vector<vector<int>> res;
        auto it = rentedMovie.begin();
        while (it != rentedMovie.end() && res.size() < 5) {
            long long val = *it;
            int price = val >> 44;
            int shop = (val & ((1LL << 44) - 1)) >> 22;
            int movie = val & ((1LL << 22) - 1);
            res.push_back({shop, movie});
            it++;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

