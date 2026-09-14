class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        const int x1 = rec1[0];
        const int y1 = rec1[1];
        const int w1 = rec1[2]-rec1[0];
        const int h1 = rec1[3]-rec1[1];

        const int x2 = rec2[0];
        const int y2 = rec2[1];
        const int w2 = rec2[2]-rec2[0];
        const int h2 = rec2[3]-rec2[1];

        return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
    }
};