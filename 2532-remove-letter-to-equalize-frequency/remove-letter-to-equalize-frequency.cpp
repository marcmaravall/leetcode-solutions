class Solution {
public:
    
    bool isEqual(string str, int i) {
    	str.erase(i,1); 
    	std::vector<int> freq(127, 0);
    
    	for (int i = 0; i < str.size(); i++)  
            freq[str[i]]++;
    
    	for (int i = 1; i < str.size(); i++) {
    		if (freq[str[i]] != freq[str[i-1]])
                return false;
        }

    	return true;
    }
    bool equalFrequency(string word) {
    	for (int i = 0; i < word.size(); i++) {
    		if (isEqual(word, i)) 
                return true;	

        }
    	return false;
    }
};