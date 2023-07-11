#include<stdio.h>

int BellmanFord(int G[20][20], int V, int E, int edge[20][2]){
    int i, j, k, u, v, distance[20], parent[20], S, flag=1;
    for(i=0; i<V; i++){
        distance[i]=9999;
        parent[i]=-1;
    }
    
    printf("Enter the source: ");
    scanf("%d", &S);
    distance[S]=0;
    
    for(i=0; i<V-1; i++){
        for(k=0; k<E; k++){
            u=edge[k][0];
            v=edge[k][1];
            if(distance[u]+G[u][v]<distance[v]){
                distance[v]=distance[u]+G[u][v];
                parent[v]=u;
            }
        }
    }
    
    for(k=0; k<E; k++){
        u=edge[k][0];
        v=edge[k][1];
        if(distance[u]+G[u][v]<distance[v]){
             flag=0;
        }
    }
    
    if(flag){
        for(i=0; i<V; i++){
            printf("\nVertex:%d\t Cost:%d\t ", i, distance[i]);
        }
    }
    return flag;
 
    
    
}


int main(){
    int V, k=0, i, j, edge[20][2], G[20][20];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
     printf("Enter the weight edges of the graph in matrix form ");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            printf("G[%d][%d]: ", i, j);
            scanf("%d", &G[i][j]);
            if(G[i][j]!=0){
                edge[k][0]=i;
                edge[k++][1]=j;
            }
        }
    }
    
    if(BellmanFord(G, V, k, edge)){
        printf("\nNo negative cycles found");
    }
    else{
        printf("\nNegative cycle found");
    }
    
}
