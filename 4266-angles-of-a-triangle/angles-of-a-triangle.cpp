class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        const double a = static_cast<float>(sides[0]);
        const double b = static_cast<float>(sides[1]);
        const double c = static_cast<float>(sides[2]);

        if (a >= b + c || b >= a + c || c >= a + b)
            return {};

        std::vector<double> res = {
            acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI,
            acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI,
            acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / M_PI
        };
        std::sort(res.begin(), res.end());
        return res;
    }
};