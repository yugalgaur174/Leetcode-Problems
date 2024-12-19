class Solution {
public:
    bool ans=false;
    void find(int i, int j, string a, vector<vector<char>>& board,  string word,int index){
        if(index==word.size()){
            ans=true;
            return ;
        }
        if(i<0 || j>board[0].size()-1 || j<0 || i>board.size()-1 ||board[i][j]=='#' || word[index]!=board[i][j])return;
        
        char temp=board[i][j];
        
        a+=word[index];
        // cout<<word[index];
        board[i][j]='#';
        find(i+1,j,a,board,  word, index+1);
        find(i-1,j,a,board,  word, index+1);
        find(i,j+1,a,board,  word, index+1);
        find(i,j-1,a,board,  word, index+1);
        board[i][j]=temp;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // vector<vector<int>> check(board.size(), vector<int>(board[0].size(),0));
        string a="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    find(i,j,a,board, word,0);
                }
                if(ans)return true;
            }
        }
        return false;;
    }
};