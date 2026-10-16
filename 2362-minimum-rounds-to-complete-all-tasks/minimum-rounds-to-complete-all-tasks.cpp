class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<int, int> freq;
        for (int x : tasks) {
            freq[x]++;
        }
        int res = 0;
        for (auto [val, f] : freq) {
            if (f == 1)
                return -1;
            res += f/3+((f%3) != 0);
        }
        return res;
    }
};