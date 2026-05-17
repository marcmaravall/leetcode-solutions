class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        std::queue<int> q;
        std::vector<int> computed(arr.size(), 0);
        q.push(start);

        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                int index = q.front();
                q.pop();

                if (computed[index]) {
                    continue;
                }

                computed[index] = true;

                if (arr[index] == 0) {
                    return true;
                }

                if ((index + arr[index] < arr.size()) && !computed[index + arr[index]]) {
                    q.push(index + arr[index]);
                }

                if ((index - arr[index] >= 0) && !computed[index - arr[index]]) {
                    q.push(index - arr[index]);
                }
            }
        }

        return false;
    }
};