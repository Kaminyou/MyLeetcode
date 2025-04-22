class TrieNode {
public:
    TrieNode* child[2];
    TrieNode(){
        this->child[0] = nullptr;
        this->child[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int x){
        TrieNode* node = root;
        bitset<32> bs(x);
        for (int i = 31; i >= 0; i--){
            if (node->child[bs[i]] == nullptr) node->child[bs[i]] = new TrieNode();
            node = node->child[bs[i]];
        }
    }
    
    int findMax(int x){
        TrieNode* node = root;
        bitset<32> bs(x);
        int ans = 0;
        for (int i = 31; i >= 0; i--){
            if (node->child[!bs[i]] != nullptr) {
                ans += 1 << i;
                node = node->child[!bs[i]];
            }
            else node = node->child[bs[i]];
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t = Trie();
        for (auto num : nums){
            t.insert(num);
        }
        int ans = 0;
        for (auto num : nums){
            ans = max(ans, t.findMax(num));
        }
        return ans;
    }
};
