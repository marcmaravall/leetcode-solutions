class Solution {
public:
    int digitSum(int n) {
        int res = 0;
        while (n) {
            res += n%10;
            n /= 10;
        }
        return res;
    }

    int minSwaps(vector<int>& nums) {
        std::vector<int> sorted(nums.begin(), nums.end());
        std::sort(sorted.begin(), sorted.end(), [this](int a, int b) {
            int sa = digitSum(a), sb = digitSum(b);
            if (sa == sb) {
                return a < b;
            }
            return sa < sb;
        });
        const int n = nums.size();
        std::unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[sorted[i]] = i;
        }
        std::vector<bool> visited(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[nums[i]] == i) {
                continue;
            }
            int j = i, s = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                s++;
            }
            res += s-1;
        }
        return res;
    }
};