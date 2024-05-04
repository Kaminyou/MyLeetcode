class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        map<int, int> mp;
        multiset<int> st;
        int n = bulbs.size();
        vector<bool> turnOn(n, false);
        mp[0] = n - 1;
        st.insert(n);
        for (int i = 0; i < n; ++i) {
            int bulb = bulbs[i] - 1;
            turnOn[bulb] = true;
            if (bulb - 1 >= 0 && turnOn[bulb - 1] && k == 0) return i + 1;
            if (bulb + 1 < n && turnOn[bulb + 1] && k == 0) return i + 1;
            auto it = mp.upper_bound(bulb);
            --it;
            int start = it->first;
            int end = it->second;
            mp.erase(it);
            st.erase(st.find(end - start + 1));
            if (start == end) {
                if (k == 0) return i + 1;
            }
            else if (start == bulb) {
                start = start + 1;
                st.insert(end - start + 1);
                mp[start] = end;
                if (end - start + 1 == k) {
                    if (end + 1 < n && turnOn[end + 1] == true) return i + 1;
                }
            }
            else if (end == bulb) {
                end = end - 1;
                st.insert(end - start + 1);
                mp[start] = end;
                if (end - start + 1 == k) {
                    if (start - 1 >= 0 && turnOn[start - 1] == true) return i + 1;
                }
            }
            else {
                mp[start] = bulb - 1;
                st.insert(bulb - start);
                if (bulb - start == k) {
                    if (start - 1 >= 0 && turnOn[start - 1]) return i + 1;
                }
                mp[bulb + 1] = end;
                st.insert(end - (bulb + 1) + 1);
                if (end - (bulb + 1) + 1 == k) {
                    if (end + 1 < n && turnOn[end + 1]) return i + 1;
                }
            }
        }
        return -1;
    }
};