class Solution {
public:
    bool symetric(int x) {
        std::string str = std::to_string(x);
        const int n = str.size();
        if (n % 2 == 1)
            return false;
        
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (i > n/2-1)
                a -= str[i];
            else a += str[i];
        }

        return a == 0;
    }

    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            res += symetric(i);
        }
        return res;
    }
};