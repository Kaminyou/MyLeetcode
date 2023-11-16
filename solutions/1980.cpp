class Solution {
public:
    string int2binary(int num) {
        string s;
        while (num) {
            s += to_string(num % 2);
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int binary2int(string& binary) {
        int ans = 0;
        int n = binary.size();
        int index = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans += (binary[i] - '0') * index;
            index *= 2;
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto& num : nums) {
            st.insert(binary2int(num));
        }
        for (int i = 0; i < (2 << n); ++i) {
            if (st.count(i)) continue;
            string ans = int2binary(i);
            string prefix(n - ans.size(), '0');
            return prefix + ans;
        }
        return "-1";
    }
};
