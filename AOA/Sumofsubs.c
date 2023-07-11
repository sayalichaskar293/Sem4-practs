#include<stdio.h>

int n, sum,  currentsum, set[30], subset[30], found=0;

void sumOfSubset(int index, int currentsum){
    int i;
    if(currentsum==sum){
                printf("\nThe subset for the sum %d is ", sum);
                for(i=0; i<n; i++){
                    printf("%d ", subset[i]);
                }
                found=1;
    }
    if(index==n || currentsum>sum){
        return ;
    }
    subset[index]=set[index];
    sumOfSubset(index+1, currentsum+set[index]);
    subset[index]=0;
    sumOfSubset(index+1, currentsum);
}

int main(){
    int i;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("\nEnter the set:\n ");
    for(i=0; i<n; i++){
        scanf("%d", &set[i]);
    }
    printf("\nEnter the sum to be found: ");
    scanf("%d", &sum);
    
    sumOfSubset(0, 0);
    
    if(!found){
        printf("\n No subset exists for this sum");
    }
    return 0;
}
