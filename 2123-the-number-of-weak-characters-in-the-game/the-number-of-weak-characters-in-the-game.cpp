class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        const int n = properties.size();
        std::sort(properties.begin(), properties.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int max = INT_MIN;
        for (int i = n-1; i >= 0; i--) {
            if (properties[i][1] < max) {
                res++;
            }
            max = std::max(max, properties[i][1]);
        }
        return res;
    }
};