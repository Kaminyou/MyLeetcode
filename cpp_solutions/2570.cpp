class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for (auto& num : nums1) {
            mp[num[0]] += num[1];
        }
        for (auto& num : nums2) {
            mp[num[0]] += num[1];
        }
        vector<vector<int>> res;
        for (auto& [id, value] : mp) {
            res.push_back({id, value});
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int index1 = 0;
        int index2 = 0;
        vector<vector<int>> res;

        int m = nums1.size();
        int n = nums2.size();
        while (index1 < m || index2 < n) {
            if (index1 < m && index2 < n) {
                int id1 = nums1[index1][0];
                int id2 = nums2[index2][0];
                if (id1 == id2) {
                    int sum = nums1[index1][1] + nums2[index2][1];
                    res.push_back({id1, sum});
                    index1++;
                    index2++;
                }
                else if (id1 > id2) {
                    res.push_back({id2, nums2[index2][1]});
                    index2++;
                }
                else if (id1 < id2) {
                    res.push_back({id1, nums1[index1][1]});
                    index1++;
                }
            }
            else if (index1 < m) {
                res.push_back(nums1[index1]);
                index1++;
            }
            else if (index2 < n) {
                res.push_back(nums2[index2]);
                index2++;
            }
        }
        return res;
    }
};
