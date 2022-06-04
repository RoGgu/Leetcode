class Solution {
public:
vector < vector < string >> ans ;
    int valid(int row ,int column ,int n , vector < string >& board ){
        if( row == 0)    return true;
        int i , j ;
        for( i =0; i < row ; i ++)		//Determine whether there is a chess piece on the column 
            if( board [ i ][ column ] == 'Q') return false;
        for( i = row -1, j = column -1; i >=0&& j >=0;)	//Determine whether there is a chess piece on the left diagonal 
            if( board [ i --][ j --] == 'Q') return false;
        for( i = row -1, j = column +1; i >=0&& j < n ;)		//Determine whether there is a chess piece on the right diagonal 
            if( board [ i --][ j ++] == 'Q')  return false;
        return true;
    }
    void dfs(int row ,int n ,vector < string > & board ){
        if( row == n ){ 
            ans .push_back( board );
        }
        if( row < n ){
            for(int i =0; i < n ; i ++){
                if(valid( row , i , n , board)){ 
                    board [ row ][ i ] = 'Q';
                    dfs( row +1, n , board ); 
                    board [ row ][ i ] = '.';
                }
            }
        }
    } 
    vector < vector < string >> solveNQueens(int n ) { 
        vector <string > board ; 
        string x ;
        for(int i =0; i < n ; i ++){		//Initialize the board 
            x .append(".");
        }
        for(int i =0; i < n ; i ++)   board .push_back( x );
        dfs(0,n , board );
        return ans ;
    }

};