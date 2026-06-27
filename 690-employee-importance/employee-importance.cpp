/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// 500th problem solved!
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int, Employee*> graph;
        for (auto* e : employees)
            graph[e->id] = e;
        
        std::function<int(int)> importance = [&](int id) -> int {
            int res = graph[id]->importance;
            for (int e : graph[id]->subordinates) {
                res += importance(e);
            }
            return res;
        };

        return importance(id);
    }
};