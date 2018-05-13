class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A);
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                res[i][j] = 1 - A[i][A[i].size()-1-j];
            }
        }
        return res;
    }
};