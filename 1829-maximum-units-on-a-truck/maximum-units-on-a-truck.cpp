class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) {
            return a[1] > b[1];
        });
        int res = 0;
        int size = 0;
        const int n = boxTypes.size();
        for (int i = 0; i < n; i++) {
            const int boxes = boxTypes[i][1];
            const int units = boxTypes[i][0];
            if (size + units >= truckSize) {
                res += boxes*(truckSize-size);
                break;
            }
            res += boxes*units;
            size += units;
        }
        return res;
    }
};