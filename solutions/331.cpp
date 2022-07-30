class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodes = 1;
        stringstream ss(preorder);
        string token;
        while (getline(ss, token, ',')) {
            nodes--;
            if (nodes < 0) return false;
            if (token != "#") nodes += 2;
        }
        return nodes == 0;
    }
};

// V2
// class Solution {
// public:
//     int index = 0;
//     bool flag = true;
//     void build(vector<string>& nodes) {
//         if (!flag) return;
//         if (nodes[index] == "#") {
//             index++;
//             return;
//         }
//         index++;
//         if (index == nodes.size()) {
//             flag = false;
//             return;
//         }
//         build(nodes);
//         if (index == nodes.size()) {
//             flag = false;
//             return;
//         }
//         build(nodes);
//     }
//     bool isValidSerialization(string preorder) {
//         vector<string> nodes;
//         string token;
//         stringstream ss(preorder);
//         while (getline(ss, token, ',')) {
//             nodes.push_back(token);
//         }
        
//         build(nodes);
//         if (index != nodes.size()) flag = false;
//         return flag;
//     }
// };