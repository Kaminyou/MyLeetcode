class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = players.size();
        int m = trainers.size();
        int idxN = 0;
        int idxM = 0;
        int res = 0;
        while (idxN < n && idxM < m) {
            if (players[idxN] <= trainers[idxM]) {
                res++;
                idxN++;
                idxM++;
            }
            else {
                idxM++;
            }
        }
        return res;
    }
};