class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        int minIndex = 0, maxIndex = 0;
        if (n == 2 && s[0] > s[1])
            return -1;
        if (std::is_sorted(s.begin(), s.end()))
            return 0;
        for (int i = 0; i < n; i++) {
            if (s[i] < s[minIndex])
                minIndex = i;
            if (s[i] >= s[maxIndex])
                maxIndex = i;
        }
        if (minIndex == 0 || maxIndex == n-1)
            return 1;
        if (maxIndex == 0 && minIndex == n-1)
            return 3;
        return 2;
    }
};