class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        const int n = s.size();
        std::array<std::stack<int>, 26> stacks;
        for (int i = 0; i < n; i++) {
            char mirror = 25-(s[i]-'a');
            if (!stacks[mirror].empty()) {
                int j = stacks[mirror].top();
                stacks[mirror].pop();
                res += i-j;
            }
            else stacks[s[i]-'a'].push(i);
        }
        return res;
    }
};