class node{
    public:
    node* v[26];
    bool end=false;

    bool ispresent(char c){
        return this->v[c-'a']!=NULL;
    }

    void make(char c,node* n){
        this->v[c-'a']=n;
    }

    void setend(){
        this->end=true;
    }
};

class Solution {
public:
    unordered_set<string>st;
    vector<int>row={1,-1,0,0};
    vector<int>col={0,0,1,-1};

    void search(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis,node* r1,string &s){

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())return;

        vis[i][j]=1;
        if(r1->end){
            st.insert(s);
        };
        

       for(int k=0;k<4;k++){
           int r=i+row[k],c=j+col[k];

           if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && !vis[r][c] && r1->ispresent(board[r][c])!=NULL){

            
                s+=board[r][c];
                search(r,c,board,vis,r1->v[board[r][c]-'a'],s);
                s.pop_back();
           }
       }

        vis[i][j]=0;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root=new node();
        
        for(auto ele:words){
            node* r1=root;

            for(auto a:ele){
                if(!r1->ispresent(a)){
                    r1->make(a,new node());
                }
                r1=r1->v[a-'a'];
            }
            r1->setend();
        }

        vector<string>ans;
        string s="";

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                node* r1=root;
                if(r1->ispresent(board[i][j])){
                    s+=board[i][j];
                    
                    vector<vector<int>>vis(board.size(),vector<int>(board[0].size()));

                    search(i,j,board,vis,r1->v[board[i][j]-'a'],s);
                    s.pop_back();
                }
            }
        }

        for(auto ele:st)ans.push_back(ele);
        return ans;
    }
};