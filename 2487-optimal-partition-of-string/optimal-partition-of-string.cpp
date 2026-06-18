class Solution {
public:
    int partitionString(string s) {
        std::vector<uint8_t> last(127, false);
        int res = 1;

        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (last[s[i]]) {
                res++;
                for (auto& c : last)
                    c = false;
            } 

            last[s[i]] = true;
        }

        return res;
    }
};