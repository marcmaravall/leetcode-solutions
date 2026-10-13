class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long res = 0;
        const int n = instructions.size();
        int i = 0;
        while (0 <= i && i < n) {
            if (values[i] == INT_MIN) {
                break;
            }
            int index = i;
            if (instructions[i] == "add") {
                res += values[i];
                i++;
            } else {
                i += values[i];
            }
            values[index] = INT_MIN;
        }
        return res;
    }
};