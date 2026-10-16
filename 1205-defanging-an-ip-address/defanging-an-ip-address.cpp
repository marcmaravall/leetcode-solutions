class Solution {
public:
    string defangIPaddr(string address) {
        int dots = 0;
        for (char c : address) {
            dots += c == '.';
        }
        std::string res(address.size()+2*dots, ' ');
        int index = 0;
        for (char c : address) {
            if (c == '.') {
                res[index++] = '[';
                res[index++] = '.';
                res[index++] = ']';
            } else {
                res[index++] = c;
            }
        }
        return res;
    }
};