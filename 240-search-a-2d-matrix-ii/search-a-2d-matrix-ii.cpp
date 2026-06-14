class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int r = 0;
        int c = m-1;
        
        while (r <= n-1 && c >= 0){
            if (matrix[r][c]== target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else 
                r++;
        }

        return false;
    }
};