class Solution {
public:
    bool palindrome(const std::string& str) {
        const int n = str.size();
        for (int i = 0; i < n/2; i++) {
            if (str[i] != str[n-i-1])
                return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        const int n = s.size();
        int res = 0;
        int last = n;
        for (int i = n; i >= 0; i--) {
            std::string str = "";
            for (int j = i; j < last; j++) {
                str += s[j];
                int size = j-i+1;
                if (size >= k && palindrome(str)) {
                    // std::cout << "adding to res: " << i << " " << j << " " << str << "\n";
                    res++;
                    last = i;
                    break;
                }
            }
        }
        return res;
    }
};