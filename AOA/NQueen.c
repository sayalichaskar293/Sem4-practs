#include<stdio.h>
#define N 8

void printSoln(int board[N][N]){
    int i, j;
    printf("Solution:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col){
    int i, j;
    
    for(j=0; j<col; j++){
        if(board[row][j]){
            return 0;
        }
    }
    
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return 0;
        }
    }
    
    for(i=row, j=col; i<N && j>=0; i++, j--){
        if(board[i][j]){
            return 0;
        }
    }
    return 1;
}

int SolveQueenUtil(int board[N][N], int col){
    int i;
    
    if(col>=N){
        return 1;
    }
    
    for(i=0; i<N; i++){
        if(isSafe(board, i, col)){
            board[i][col]=1;
            
            
            if(SolveQueenUtil(board, col+1)){
                return 1;
            }
            
            board[i][col]=0;
        }
        
    
    }   
      return 0; 
}

int SolveQueen(){
    int board[N][N]={0};
    if(SolveQueenUtil(board, 0)==0){
        printf("\n There is no solution to the problem");
        return 0;
    }
    
    printSoln(board);
    return 1;
}

int main(){
    SolveQueen();
    return 0;
}


