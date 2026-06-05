class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            const int m = 1 << i;
            const bool
                am = a & m, 
                bm = b & m,
                cm = c & m;

            if ((am || bm) != cm) { 
                if (!cm && am && bm)
                    res++;
                res++;
            }
        }
        
        return res;
    }
};