class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph; //ingred->recipe
        
        unordered_set<string> suppliesHash;
        for (auto& supply : supplies) suppliesHash.insert(supply);
        int n = recipes.size();
        for (int i = 0; i < n; ++i) {
            inDegree[recipes[i]] = 0;
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (suppliesHash.find(ingredients[i][j]) == suppliesHash.end()) {
                    inDegree[recipes[i]]++;
                    graph[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        vector<string> res;
        queue<string> q;
        for (auto& element : inDegree) {
            if (element.second == 0) q.push(element.first);
        }
        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            res.push_back(recipe);
            for (auto& nextRecipe : graph[recipe]) {
                inDegree[nextRecipe]--;
                if (inDegree[nextRecipe] == 0) q.push(nextRecipe);
            }
        }
        return res;
    }
};