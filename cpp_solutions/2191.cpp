class Solution {
public:
    int num2num(int num, vector<int>& mapping) {
        string out = to_string(num);
        for (int i = 0; i < out.size(); i++) {
            out[i] = mapping[out[i] - '0'] + '0';
        }
        return stoi(out);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> translatedNums;
        for (int i = 0; i < nums.size(); i++) {
            translatedNums.push_back(make_pair(num2num(nums[i], mapping), i));
        }
        
        sort(translatedNums.begin(), translatedNums.end());
        vector<int> out;
        for (int i = 0; i < translatedNums.size(); i++) {
            out.push_back(nums[translatedNums[i].second]);
        }
        return out;
    }
};
