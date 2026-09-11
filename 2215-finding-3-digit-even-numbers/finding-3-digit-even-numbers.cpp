class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        std::vector<int> res;
        for (int x : digits)
            freq[x]++;
        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < 10; j++) 
                for (int k = 0; k < 9; k += 2) { 
                    bool b = freq[i] > 0 &&
                             freq[j] > (i == j) &&
                             freq[k] > (i == k) + (j == k);
                    if (b)
                        res.push_back(i*100+j*10+k);
                }
        return res;
    }
};