class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        std::unordered_map<std::string, int> freq;
        std::string str(k, ' ');
        const int n = word.size();
        int maxFreq = 0;
        const int partitions = n/k;
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < k; j++) {
                str[j] = word[i+j];
            }
            maxFreq = std::max(maxFreq, ++freq[str]);
        }
        return partitions-maxFreq;
    }
};