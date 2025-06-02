class Solution {
public:
    vector<int> row={0,-1,0,1};
    vector<int> col={1,0,-1,0};
    void dfs(int i, int j, vector<vector<char>>&board, vector<vector<int>> & visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return ;
        }
        if(board[i][j]=='X' || visited[i][j]){
            return;
        }
        else{
            visited[i][j]=1;
            for(int k=0;k<4;k++){
                int r=i+row[k];
                int c=j+col[k];
                dfs(r,c,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'&& !visited[i][0]){
                dfs(i,0,board, visited);
            }
            if(board[i][board[0].size()-1]=='O'&& !visited[i][board[0].size()-1]){
                dfs(i,board[0].size()-1,board, visited);
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'&& !visited[0][i]){
                dfs(0,i,board, visited);
            }
            if(board[board.size()-1][i]=='O' && !visited[board.size()-1][i]){
                dfs(board.size()-1,i,board, visited);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};