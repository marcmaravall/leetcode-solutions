class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0;
        int maxArea = 0;
        for (auto& rectangle : rectangles) {
            int area = std::min(rectangle[0], rectangle[1]);
            if (area == maxArea) {
                res++;
            } else if (area > maxArea) {
                maxArea = area;
                res = 1;
            }
        }
        return res;
    }
};