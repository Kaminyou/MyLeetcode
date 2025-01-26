class TaskManager {
public:
    long long toKey(int taskId, int priority) {
        long long key = 0;
        key += ((long long)priority << 31);
        key += taskId;
        return key;
    }
    unordered_map<int, pair<int, int>> taskID2info;
    set<long long> st;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            taskID2info[task[1]] = {task[0], task[2]}; // taskID: userID, priority
            long long key = toKey(task[1], task[2]);
            st.insert(key);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        long long key = toKey(taskId, priority);
        st.insert(key);
        taskID2info[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, priority] = taskID2info[taskId];
        taskID2info[taskId] = {userId, newPriority};
        long long oldKey = toKey(taskId, priority);
        st.erase(st.find(oldKey));
        long long newKey = toKey(taskId, newPriority);
        st.insert(newKey);
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = taskID2info[taskId];
        long long oldKey = toKey(taskId, priority);
        st.erase(st.find(oldKey));
        taskID2info.erase(taskID2info.find(taskId));
    }
    
    int execTop() {
        if (st.empty()) return -1;
        long long key = *st.rbegin();
        long long mask = 1;
        int taskId = key & ((mask << 31) - 1);
        auto [userId, priority] = taskID2info[taskId];
        taskID2info.erase(taskID2info.find(taskId));
        st.erase(st.find(key));
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
