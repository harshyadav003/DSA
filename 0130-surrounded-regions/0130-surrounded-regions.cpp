class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> & vis){
        int r=board.size();
        int c=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int nrow=i+drow[d];
            int ncol=j+dcol[d];
            if(nrow>=0 && ncol>=0 && nrow<r && ncol<c && board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
                 dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
          int r=board.size();
        int c=board[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
               if((row==0 || col==0 || col==c-1 || row==r-1) && board[row][col]=='O' && vis[row][col]==0){
                   dfs(row,col,board,vis);
                    
                }
               
            }
        }

        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
               if( board[row][col]=='O' && vis[row][col]==0){
                   board[row][col]='X';
                    
                }
               
            }
        }


        
    }
};