class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        std::queue<int> q;
        std::unordered_map<int, bool> computed;
        q.push(start);

        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                int index = q.front();
                if (computed[index]) {
                    q.pop();
                    continue;
                }

                computed[index] = true;

                if (arr[index] == 0) {
                    return true;
                }

                if (!computed[index + arr[index]]) {
                    if (index + arr[index] < arr.size())
                        q.push(index + arr[index]);
                }

                if (!computed[index - arr[index]]) {
                    if (index - arr[index] >= 0)
                        q.push(index - arr[index]);
                }

                q.pop();
            }
        }

        return false;
    }
};