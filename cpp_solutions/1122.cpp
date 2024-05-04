class Compare {
private:
    unordered_map<int, int> mp;
public:
    Compare(unordered_map<int, int>& mp) {
        this->mp = mp;
    }
    bool operator()(const int& x, const int& y) {
        auto itX = mp.find(x);
        auto itY = mp.find(y);
        if (itX != mp.end() && itY != mp.end()) {
            return mp[x] < mp[y];
        }
        else if (itX != mp.end() && itY == mp.end()) {
            return true;
        }
        else if (itX == mp.end() && itY != mp.end()) {
            return false;
        }
        else return x < y;
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i;
        }
        Compare* compare = new Compare(mp);
        sort(arr1.begin(), arr1.end(), (*compare));
        return arr1;
    }
};