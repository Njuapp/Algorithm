class Solution {
    int x[8]={-1,-1,-1,0,0,1,1,1};
    int y[8]={-1,0,1,-1,1,-1,0,1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[i].size(); j++){
                int sum = 0;
                for(int k = 0; k < 8; k++){
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if(xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size())
                        continue;
                    if(board[xx][yy] & 1)
                        sum ++;
                }
                if(board[i][j] & 1){
                    if(sum == 2 || sum == 3)
                        board[i][j] = 3;
                }
                else{
                    if(sum == 3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[i].size(); j++){
                board[i][j] >>=1;
            }
        }
    }
};
