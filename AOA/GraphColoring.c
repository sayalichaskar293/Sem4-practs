#include<stdio.h>
#define MAX 10

void printSoln(int V, int color[]){
    int i;
    for(i=0; i<V; i++){
        printf("\nVertex %d -> Color %d", i, color[i]);
    }
}

int isSafe(int v, int graph[MAX][MAX], int color[], int c, int V){
    int i;
    for(i=0; i<V; i++){
        if(graph[v][i] && color[i]==c){
            return 0;
        }
    }
    return 1;
}

int graphColorUtil( int graph[MAX][MAX], int color[MAX], int m, int v, int V){
    int c;
    if(v==V){
        return 1;
    }
    
    for(c=1; c<=m; c++){
        if(isSafe(v, graph, color, c, V)){
            color[v]=c;
            
            if(graphColorUtil(graph, color, m, v+1, V)){
                return 1;
            }
            
            color[v]=0;
        }
    }
    
}

int graphColor(int graph[MAX][MAX], int m, int V){
    int i;
    int color[MAX];
    for(i=0; i<V; i++){
        color[i]=0;
    }
    
    if(graphColorUtil(graph, color, m, 0, V)==0){
        printf("No solution");
        return 0;
    }
    
    printSoln(V, color );
    return 1;
    
}

int main(){
     int V, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("G[%d][%d]", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColor(graph, m, V);
    return 0;
}

