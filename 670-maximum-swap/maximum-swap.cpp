class Solution {
public:
    int maximumSwap(int num) {
        std::string str(std::to_string(num));
        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;
        const int n = str.size();

        for (int i = n-1; i >= 0; --i) {
            if (str[i] > maxdigit) {
                maxdigit = str[i];
                maxidx = i;
                continue;
            }
            if (str[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        if (leftidx == -1) 
            return num;

        std::swap(str[leftidx], str[rightidx]);
        return std::stoi(str);
    }
};