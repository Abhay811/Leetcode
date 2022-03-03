class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        if(mat.length*mat[0].length == r*c)
        {
            int[][] result = new int[r][c];
            int row = 0, column = 0;
            for(int i = 0; i<mat.length; i++)
            {
                for (int j = 0; j<mat[0].length; j++)
                {
                    if(column == c)
                    {row+=1; 
                     column = 0;}
                    result[row][column++] = mat[i][j];
                }
            }
            return result;
        }
        return mat;
    }
}