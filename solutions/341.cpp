/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int index;
    vector<NestedInteger> _nestedList;
    NestedIterator* child;
    NestedIterator(vector<NestedInteger> &nestedList) {
        _nestedList = nestedList;
        index = 0;
        child = nullptr;
    }
    
    int next() {
        hasNext();
        if (!_nestedList[index].isInteger()) {
            return child->next();
        }
        return _nestedList[index++].getInteger();
    }
    
    bool hasNext() {
        while (true) {
            if (index >= _nestedList.size()) return false;
            if (_nestedList[index].isInteger()) return true;
            if (child == nullptr) {
                child = new NestedIterator(_nestedList[index].getList());
            }
            if (child->hasNext()) return true;
            child = nullptr;
            index++;
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */