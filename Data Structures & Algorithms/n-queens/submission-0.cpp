class Solution {
public: 
    void find(int row,vector<vector<string>>&ans,vector<string>&board,
    vector<bool>&col,vector<bool>&right,vector<bool>&left,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!col[i] && !right[n-1+i-row] && !left[i+row])
            {
                col[i]=1;
                right[n-1+i-row]=1;
                left[i+row]=1;
                board[row][i]='Q';
                find(row+1,ans,board,col,right,left,n);
                col[i]=0;
                right[n-1+i-row]=0;
                left[i+row]=0;
                board[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n,'.'));
        vector<bool>col(n,0),right(2*n-1,0),left(2*n-1,0);

        find(0,ans,board,col,right,left,n);
        return ans;
    }
};






//     void solve(int row,vector<vector<string>>& board,vector<int>& col,
//     vector<int>& diag1,vector<int>& diag2,vector<vector<string>>& ans,int n)
// {
//     if(row == n)
//     {
//         ans.push_back(board);
//         return;
//     }

//     for(int c = 0; c < n; c++)
//     {
//         if(col[c] || diag1[row - c + n - 1] || diag2[row + c])
//             continue;

//         board[row][c] = "Q";

//         col[c] = 1;
//         diag1[row - c + n - 1] = 1;
//         diag2[row + c] = 1;

//         solve(row + 1, board, col, diag1, diag2, ans, n);

//         board[row][c] = ".";

//         col[c] = 0;
//         diag1[row - c + n - 1] = 0;
//         diag2[row + c] = 0;
//     }
// }