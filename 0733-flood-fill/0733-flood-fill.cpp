class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int oldcolor,int color){
        int row=image.size();
        int col=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        image[i][j] = color;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];//n=neighbour
            int ncol=j+delcol[k];
            if(ncol<col && nrow<row && nrow>=0 && ncol>=0 && image[nrow][ncol]==oldcolor){ //image[nrow][ncol]==oldcolor It means the neighbor's color must be the same as the starting pixel's original color. Only then will we change its color.
                    dfs(nrow,ncol,image,oldcolor,color);
            }
        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        int oldcolor = image[sr][sc];
        if(oldcolor==color) return image;
        dfs(sr,sc,image,oldcolor,color);
        return image;
    }
};