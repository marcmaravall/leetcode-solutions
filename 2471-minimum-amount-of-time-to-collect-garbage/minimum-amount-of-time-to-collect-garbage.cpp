class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const int n = garbage.size();
        int res = 0;
        int lastM = 0, lastP = 0, lastG = 0;
        for (int i = 0; i < n; i++) {
            for (char c : garbage[i]) {
                if (c == 'M') lastM = i;
                else if (c == 'P') lastP = i;
                else if (c == 'G') lastG = i;
                res++;
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (i < lastM)
                res += travel[i];
            if (i < lastP)
                res += travel[i];
            if (i < lastG)
                res += travel[i];
        }

        return res;
    }
};