class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int n = differences.size();
        std::vector<long long> hidden(n+1);
        long long min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < n; i++) {
            hidden[i+1] = differences[i]+hidden[i];
            min = std::min(min, hidden[i]);
            max = std::max(max, hidden[i]);
        }
        min = std::min(min, hidden.back());
        max = std::max(max, hidden.back());
        long long diff = max-min;
        if (upper-lower < diff) {
            return 0;
        }
        return upper-lower-diff+1;
    }
};