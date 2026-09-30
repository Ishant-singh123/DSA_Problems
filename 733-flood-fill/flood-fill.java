class Solution {
    void dfs(int[][]image,int i,int j,int color,int start){
        if(i<0 || j<0 || i>=image.length ||j>=image[0].length || image[i][j]!=start){
            return ;
        }
        if(image[i][j]==color){
            return ;
        }
        image[i][j]=color;
        dfs(image,i+1,j,color,start);
        dfs(image,i-1,j,color,start);
        dfs(image,i,j+1,color,start);
        dfs(image,i,j-1,color,start);
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        dfs(image,sr,sc,color,image[sr][sc]);
        return image; 
    }
}