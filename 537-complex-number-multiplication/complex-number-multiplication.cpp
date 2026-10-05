class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a = std::stoi(num1.substr(0, num1.find('+')));
        int b = std::stoi(num1.substr(num1.find('+')+1, num1.length()-1));
        int c = std::stoi(num2.substr(0, num2.find('+')));
        int d = std::stoi(num2.substr(num2.find('+')+1, num2.length()-1));
        return std::to_string(a*c-b*d) + "+" + std::to_string(a*d+b*c)+"i"; 
    }
};