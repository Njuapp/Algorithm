class Solution {
public:
    int BitCount2(unsigned int n)
    {
        unsigned int c =0 ;
        for (c =0; n; ++c)
        {
            n &= (n -1) ; // 清除最低位的1
        }
        return c ;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size()==0)return 0;
        vector<int> a(A.size());
        vector<int> b(B.size());
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                a[i] = ((a[i] << 1) | A[i][j]);
                b[i] = ((b[i] << 1) | B[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < 2*A.size()-1; i++){
            for(int j = 0; j < 2*A.size()-1; j++){
                int ii = i - A.size() + 1;
                int jj = j - A.size() + 1;
                int ans = 0;
                for(int r = 0; r < A.size(); r ++){
                    int rb = r + ii;
                    if(rb < 0 || rb >= B.size())
                        continue;
                    int ar = a[r];
                    int br = b[rb];
                    if(jj < 0){
                        ar = ar << (-jj);
                    }
                    else{
                        ar = ar >> (jj);
                    }
                    ans += BitCount2(ar & br);
                }
                res = max(res, ans);
            }
        }
        return res;

    }
};