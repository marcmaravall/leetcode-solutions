class Solution {
public:
    int integerReplacement(int n) {
        std::queue<long long> q;
        q.push(n);
        int res;
        for (res = 0; !q.empty(); res++) {
            std::size_t s = q.size();
            for (int i = 0; i < s; i++) {
                long long curr = q.front();
                q.pop();
                if (curr == 1)
                    return res;
                if (curr % 2 == 0)
                    q.push(curr/2);
                else {
                    q.push(curr+1);
                    q.push(curr-1);
                }
            }
        }
        return 0;
    }
};