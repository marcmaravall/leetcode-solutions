class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        const int n = s.size();
        std::unordered_map<char, std::stack<int>> stacks;
        for (int i = 0; i < n; i++) {
            char mirror = 'z'-(s[i]-'a');
            if (!stacks[mirror].empty()) {
                int j = stacks[mirror].top();
                stacks[mirror].pop();
                res += i-j;
            }
            else stacks[s[i]].push(i);
        }
        return res;
    }
};