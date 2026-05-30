class Solution {
public:
    string mergeCharacters(string s, int k) {
        std::string res=s;
        
        for (int step = 0; step < 100; step++){
            bool check = false;
            for (int i=0; i < res.size(); i++) {
                for (int j=i+1;j<res.size();j++){
                    if(res[i]==res[j] && (j-i)<=k){
                        res.erase(j,1);
                        check = true;
                        break;
                    }
                }
                if(check) break;
            }
            if(!check) break;
        }
        return res;
    }
};