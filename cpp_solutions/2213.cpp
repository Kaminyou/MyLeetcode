class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        multiset<int> lengths;
        map<int, int> idx2length;
        char curr = '#';
        int count = 0;
        int start = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == curr) {
                count++;
            }
            else {
                lengths.insert(count);
                idx2length[start] = count;
                curr = c;
                count = 1;
                start = i;
            }
        }
        lengths.insert(count);
        idx2length[start] = count;
        int k = queryCharacters.size();
        vector<int> res(k, -1);
        for (int i = 0; i < k; ++i) {
            char newC = queryCharacters[i];
            int targetIdx = queryIndices[i];
            if (s[targetIdx] == newC) {
                int l = *lengths.rbegin();
                res[i] = l;
                continue;
            }
            char left = '#';
            char right = '#';
            char currC = s[targetIdx];
            if (targetIdx > 0) left = s[targetIdx - 1];
            if (targetIdx < n - 1) right = s[targetIdx + 1];

            auto currP = prev(idx2length.upper_bound(targetIdx));

            int currStart = currP->first;
            int currLength = currP->second;
            int currEnd = currStart + currLength - 1;

            idx2length.erase(currP);
            lengths.erase(lengths.find(currLength));

            // Left part of the original run
            int oldLeftLength = targetIdx - currStart;

            if (oldLeftLength > 0) {
                idx2length[currStart] = oldLeftLength;
                lengths.insert(oldLeftLength);
            }

            // Right part of the original run
            int oldRightLength = currEnd - targetIdx;

            if (oldRightLength > 0) {
                idx2length[targetIdx + 1] = oldRightLength;
                lengths.insert(oldRightLength);
            }

            if (newC != left && newC != right) {
                idx2length[targetIdx] = 1;
                lengths.insert(1);
            }
            else if (newC == left && newC == right) {
                auto leftP = prev(idx2length.upper_bound(targetIdx - 1));

                int leftIdx = leftP->first;
                int leftLength = leftP->second;

                auto rightP = idx2length.find(targetIdx + 1);
                int rightLength = rightP->second;

                idx2length.erase(leftP);
                idx2length.erase(rightP);

                lengths.erase(lengths.find(leftLength));
                lengths.erase(lengths.find(rightLength));

                int newLength = leftLength + 1 + rightLength;

                idx2length[leftIdx] = newLength;
                lengths.insert(newLength);
            }
            else if (newC == left && newC != right) {
                auto leftP = prev(idx2length.upper_bound(targetIdx - 1));

                int leftIdx = leftP->first;
                int leftLength = leftP->second;

                idx2length.erase(leftP);
                lengths.erase(lengths.find(leftLength));

                idx2length[leftIdx] = leftLength + 1;
                lengths.insert(leftLength + 1);
            }
            else if (newC != left && newC == right) {
                auto rightP = idx2length.find(targetIdx + 1);
                int rightLength = rightP->second;

                idx2length.erase(rightP);
                lengths.erase(lengths.find(rightLength));

                idx2length[targetIdx] = rightLength + 1;
                lengths.insert(rightLength + 1);
            }
            s[targetIdx] = newC;
            int l = *lengths.rbegin();
            res[i] = l;
        }
        return res;
    }
};

