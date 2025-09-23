class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < version1.size() || index2 < version2.size()) {
            if (version1[index1] == '.') index1++;
            int start1 = index1;
            while (index1 + 1 < version1.size() && version1[index1 + 1] != '.') index1++;
            // start1 <-> index1
            int subRevision1 = 0;
            if (start1 != version1.size()) {
                string subVersion1 = version1.substr(start1, index1 - start1 + 1);
                subRevision1 = stoi(subVersion1);
                index1++;
            }

            if (version2[index2] == '.') index2++;
            int start2 = index2;
            while (index2 + 1 < version2.size() && version2[index2 + 1] != '.') index2++;
            // start2 <-> index2
            int subRevision2 = 0;
            if (start2 != version2.size()) {
                string subVersion2 = version2.substr(start2, index2 - start2 + 1);
                subRevision2 = stoi(subVersion2);
                index2++;
            }
            if (subRevision1 > subRevision2) return 1;
            else if (subRevision1 < subRevision2) return -1;
        }
        return 0;
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        string token1;
        stringstream ss2(version2);
        string token2;
        while (true) {
            int val1 = 0;
            int val2 = 0;
            bool flag = false;
            if (getline(ss1, token1, '.')) {
                val1 = stoi(token1);
                flag = true;
            }
            if (getline(ss2, token2, '.')) {
                val2 = stoi(token2);
                flag = true;
            }
            if (!flag) return 0;
            if (val1 > val2) return 1;
            if (val1 < val2) return -1;
        }
        return 0;
    }
};
