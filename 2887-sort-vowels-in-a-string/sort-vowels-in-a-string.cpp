class Solution {
public:
    bool vowel(char v) { 
        return (0x208222>>(v&0x1f))&1;
    }

    string sortVowels(string s) {
        std::string vowels = "";
        for (char& c : s) {
            if (vowel(c)) {
                vowels += c;
                c = '.';
            }
        }

        std::sort(vowels.begin(), vowels.end());
        int current = 0;
        for (char& c : s) {
            if (c == '.') {
                c = vowels[current++];
            }
        }
        return s;
    }
};