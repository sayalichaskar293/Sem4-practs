#include<stdio.h>
#include<string.h>

    char s1[20];
    char s2[20];

void lcsAlgo(char s1[], char s2[]){
  
    int i, j, m, n;
    m=strlen(s1);
    n=strlen(s2);
    int lcsTable[20][20];
    
    puts(s1);
    puts(s2);
    
    for(i=0; i<=m; i++){
        lcsTable[i][0]=0;
    }
    for(i=0; i<=n; i++){
        lcsTable[0][i]=0;
    }
    
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1]){
                lcsTable[i][j]=lcsTable[i-1][j-1]+1;
            }
            else if(lcsTable[i-1][j]<=lcsTable[i][j-1]){
                lcsTable[i][j]=lcsTable[i][j-1];
            }
            else{
                lcsTable[i][j]=lcsTable[i-1][j];
            }
        }
    }
    
    
    
    int index=lcsTable[m][n];
    char lcsString[index+1];
    lcsString[index]='\0';
    i=m;
    j=n;
    
    while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcsString[index-1]=s1[i-1];
                i--;
                j--;
                index--;
            }
            else if(lcsTable[i-1][j]>lcsTable[i][j-1]){
                i--;
            }
            else{
                j--;
            }
    }
    
        printf("\nThe lcs is: %s", lcsString);
       
}   

int main(){
    printf("Enter string 1: ");
    gets(s1);
    printf("Enter string 2: ");
    gets(s2);
    lcsAlgo(s1, s2);
    return 0;
}

