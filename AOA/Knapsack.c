#include<stdio.h>

void knapsack(int n,float ratio[], float weight[], float profit[], int capacity ){
    float x[20], tp=0.0;
    int i, u;
    u=capacity;
    
    for(i=0; i<n; i++){
        x[i]=0.0;
    }
    
    for(i=0; i<n; i++){
        if(weight[i]>u){
            break;
        }
        else{
            x[i]=1;
            u=u-weight[i];
            tp=tp+profit[i];
        }
    }
    
    if(i<n){
        x[i]=u/weight[i];
        tp=tp+(x[i]*profit[i]);
    }
    
    printf("Solution\n");
    for(i=0; i<n; i++){
        printf("%f ", x[i]);
    }
    
    printf("\n The total profit is %f", tp);
    
}

int main(){
    int i, j, num, capacity;
    float weight[20], profit[20], ratio[20];
    
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    
    printf("Enter the elements with their weight and profit repectively: ");
    for(i=0; i<num; i++){
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i]=profit[i]/weight[i];
    }
    
     printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    
    for(i=0; i<num-1; i++){
        for(j=0; j<num-i-1; j++){
            if(ratio[j+1]>ratio[j]){
                int temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;
                
                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;
                
                temp=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp;
            }
        }
    }
    
    knapsack(num, ratio, weight, profit, capacity);
    return 0;
}
