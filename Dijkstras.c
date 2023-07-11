#include<stdio.h>
#define MAX 10
#define INFINITY 9999

void Dijkstra(int Graph[MAX][MAX], int n, int start){
    int i,j, nextnode, visited[MAX], pred[MAX],  count, cost[MAX][MAX];
    int dist[MAX], mindistance;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(Graph[i][j]==0){
                cost[i][j]=INFINITY;
            }
            else{
                cost[i][j]=Graph[i][j];
            }
        }
    }
    
    for(i=0; i<n; i++){
        dist[i]=cost[start][i];
        visited[i]=0;
        pred[i]=start;
    }
    
    dist[start]=0;
    pred[start]=start;
    visited[start]=1;
    count=1;
    
    while(count<n-1){
       mindistance=INFINITY;
       for(i=0; i<n; i++){
           if(dist[i]<mindistance && !visited[i]){
               mindistance=dist[i];
               nextnode=i;
           }
       }
       visited[nextnode]=1;
       for(i=0; i<n; i++){
           if(mindistance+cost[nextnode][i]<dist[i] && !visited[i]){
               dist[i]=mindistance+cost[nextnode][i];
               pred[i]=nextnode;
           }
       }
       count++;
}
for(i=0; i<n; i++){
    if(i!=start){
       printf("The distance from source to %d is %d\n", i, dist[i]); 
    }
   
    }
}

int main(){
    int Graph[MAX][MAX], n, u,j, i;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the weight of each edge in the graph: ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("\nGraph[%d][%d]: ", i, j);
            scanf("%d", &Graph[i][j]);
        }
    }
    printf("Enter the source: ");
    scanf("%d", &u);
    Dijkstra(Graph, n, u);
    
    return 0;
                                         
}