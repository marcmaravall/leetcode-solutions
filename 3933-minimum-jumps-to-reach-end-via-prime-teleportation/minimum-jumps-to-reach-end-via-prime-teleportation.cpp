class Solution {
public:
    bool prime(int n) {
        if (n == 1)
            return false;
        if (n <= 3)
            return true;

        int i = 2;
        while (i <= sqrt(n)) {
            if (n % i == 0)
                return false;
            i++;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int maxElement = 0;
        std::unordered_map<int, std::vector<int>> numToIndex;
        for (int i = 0; i < n; i++) {
            numToIndex[nums[i]].push_back(i);
            maxElement = max(maxElement, nums[i]);
        }
        
        std::unordered_map<int, bool> visited;
        std::queue<int> queue;
        
        queue.push(0);
        visited[0] = true;

        int res = 0;

        while (!queue.empty()) {
            int s = queue.size();

            for (int k = 0; k < s; k++) {
                int i = queue.front();
                queue.pop();

                if (i == n-1)
                    return res;

                if (prime(nums[i])) {
                    int p = nums[i];
                    while (p <= maxElement) {
                        for (int m = 0; m < numToIndex[p].size(); m++) {
                            if (visited[numToIndex[p][m]])
                                continue;

                            queue.push(numToIndex[p][m]);
                            visited[numToIndex[p][m]] = true;
                        }
                        numToIndex[p] = {};
                        p += nums[i];
                    }
                }

                if (i < n-1 && !visited[i+1]) {
                    visited[i+1] = true;
                    queue.push(i+1);
                }

                if (i > 0 && !visited[i-1]) {
                    visited[i-1] = true;
                    queue.push(i-1);
                }
            }
            res++;
        }

        return res;
    }
};