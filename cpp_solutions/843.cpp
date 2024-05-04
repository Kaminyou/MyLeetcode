/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int countMatch(const string& s1, const string& s2) {
        int count = 0;
        for (int i = 0; i < 6; ++i) {
            if (s1[i] == s2[i]) count++;
        }
        return count;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        sort(wordlist.begin(), wordlist.end());
        unordered_map<string, unordered_map<int, unordered_set<string>>> mp;
        int n = wordlist.size();
        vector<int> available(n, true);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int count = countMatch(wordlist[i], wordlist[j]);
                mp[wordlist[i]][count].insert(wordlist[j]);
                mp[wordlist[j]][count].insert(wordlist[i]);
            }
        }
        // guess
        while (1) {
            int rnd = rand() % wordlist.size();
            string guess = wordlist[rnd];
            int res = master.guess(guess);
            if (res == 6) break;
            vector<string> newWordList;
            for (auto& word : wordlist) {
                if (mp[guess][res].find(word) != mp[guess][res].end()) {
                    newWordList.push_back(word);
                }
            }
            wordlist = newWordList;
        }
    }
};


// V2
// /**
//  * // This is the Master's API interface.
//  * // You should not implement it, or speculate about its implementation
//  * class Master {
//  *   public:
//  *     int guess(string word);
//  * };
//  */
// class Solution {
// public:
//     int compare(const string& s1, const string& s2) {
//         int count = 0;
//         for (int i = 0; i < 6; ++i) {
//             if (s1[i] == s2[i]) count++;
//         }
//         return count;
//     }
//     void findSecretWord(vector<string>& wordlist, Master& master) {
//         // each time
//         // random pick one and use the response to filter those
//         // are not the same
//         sort(wordlist.begin(), wordlist.end());
//         while (true) {
//             int rnd = rand() % wordlist.size();
//             string query = wordlist[rnd];
//             int response = master.guess(query);
//             if (response == 6) break;
//             vector<string> newWordlist;
//             for (auto& s : wordlist) {
//                 if (compare(s, query) == response) newWordlist.push_back(s);
//             }
//             wordlist = newWordlist;
//         }
//     }
// };