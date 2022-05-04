class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto card : deck) mp[card]++;
        
        vector<int> v;
        for (auto element : mp) v.push_back(element.second);
        for (int i = 1; i < v.size(); i++) {
            v[i] = __gcd(v[i], v[i - 1]);
        }
        return v[v.size() - 1] >= 2;
        
    }
};