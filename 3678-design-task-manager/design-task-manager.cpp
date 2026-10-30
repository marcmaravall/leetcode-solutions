class TaskManager {
public:
    std::priority_queue<std::pair<int, int>> tasks;
    std::unordered_map<int, int> taskPriority;
    std::unordered_map<int, int> taskOwner;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& tasks : tasks) {
            add(tasks[0], tasks[1], tasks[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
    }

    void edit(int taskId, int priority) {
        tasks.push({priority, taskId});
        taskPriority[taskId] = priority;
    }
    
    void rmv(int taskId) {
        taskPriority[taskId] = -1;
    }
    
    int execTop() {
        while (!tasks.empty()) {
            const auto task = tasks.top();
            tasks.pop();
            if (task.first == taskPriority[task.second]) {
                taskPriority[task.second] = -1;
                return taskOwner[task.second];
            }
        }
        return -1;
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