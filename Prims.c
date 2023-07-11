#include<stdio.h>
#define MAX 100

int G[MAX][MAX], visited[MAX], parent[MAX], key[MAX];

int minKey(int n){
    int i, minIndex, min=999;
    for(i=0; i<n; i++){
        if(!visited[i] && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void primS(int n){
    int i, j, u, v;
    
    for(i=0; i<n; i++){
        key[i]=9999;
        visited[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    
    for(i=0; i<n-1; i++){
         u=minKey(n);
         visited[u]=1;
         
         for(v=0; v<n; v++){
             if(G[u][v] && !visited[v] && G[u][v]<key[v]){
                 parent[v]=u;
                 key[v]=G[u][v];
             }
         }
    }
    
    printf("Edge Weight\n");
    for(i=1; i<n; i++){
         printf("%d-%d %d\n", parent[i], i, G[i][parent[i]]);
    }
   
}

int main(){
    int i,n, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of graph");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("G[%d][%d]", i,j);
            scanf("%d", &G[i][j]);
        }
    }
    
    primS(n);
    return 0;
}
