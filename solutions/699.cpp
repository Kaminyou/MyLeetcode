class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<pair<int, int>, int> mp;
        vector<int> res;
        int currHeight = 0;
        for (auto position : positions) {
            int left = position[0];
            int right = left + position[1];
            int height = position[1];
            
            //  |---| curr
            //     |xx| find this
            //    ^
            
            auto it = mp.upper_bound(make_pair(left, right));
            if (it != mp.begin()) {
                auto itTemp = it;
                // check 
                //     |---| curr
                //  |ooo| |xx| 
                //      ^
                if ((--itTemp)->first.second > left) it = itTemp;
            }
            
            int baseHeight = 0;
            vector<tuple<int, int, int>> appendix;
            while (it != mp.end() && it->first.first < right) {
                int l = it->first.first;
                int r = it->first.second;
                int h = it->second;
                
                if (left > l) appendix.push_back(make_tuple(l, left, h));
                if (r > right) appendix.push_back(make_tuple(right, r, h));
                
                baseHeight = max(baseHeight, h);
                
                it = mp.erase(it);
            }
            currHeight = max(currHeight, baseHeight + height);
            mp[{left, right}] = baseHeight + height;
            for (auto element : appendix) {
                mp[{get<0>(element), get<1>(element)}] = get<2>(element);
            }
            res.push_back(currHeight);
        }
        return res;
    }
};