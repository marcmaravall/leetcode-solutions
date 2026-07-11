class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        constexpr int MOD = 1e9 + 7;
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue(nums.begin(), nums.end());
        while (k > 0) {
            int s = pqueue.top()+1;
            pqueue.pop();
            pqueue.push(s);
            k--;
        }

        long long res = 1;
        while (!pqueue.empty()) {
            res *= pqueue.top();
            pqueue.pop();
            res %= MOD;
        }
        return res;
    }
};