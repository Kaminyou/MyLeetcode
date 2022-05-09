class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        list<int> stimulate;
        for (int i = 0; i < n; i++) stimulate.push_back(i);
        sort(deck.begin(), deck.end());
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            res[stimulate.front()] = deck[i];
            stimulate.pop_front();
            if (!stimulate.empty()) {
                int temp = stimulate.front();
                stimulate.pop_front();
                stimulate.push_back(temp);
            }
        }
        
        return res;
    }
};