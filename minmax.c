#include<stdio.h>

int max, min;
int a[100];

void maxmin(int i, int j)
{
    int mid;
    if(i==j)
    {
        max=a[i];
        min=a[i];
    }
    else
    {
        if(i==j-1)
        {
            if(a[i]<a[j])
            {
                max=a[j];
                min=a[i];
            }
            else
            {
                max=a[i];
                min=a[j];
            }
        }
        else
        {
            mid=(i+j)/2;
            maxmin(i, mid);
            int max1=max;
            int min1=min;
            maxmin(mid+1, j);
            if(max1>max){
                max=max1;
            }
            if(min1<min){
                min=min1;
            }
        }
    }
}

int main(){
    int i,num;
    printf("Enter number of numbers: ");
    scanf("%d", &num);
    printf("\nEnter the numbers: ");
    for(i=1; i<=num; i++){
        scanf("%d", &a[i]);
    }
    max=a[0];
    min=a[0];
    maxmin(1, num);
    printf("\nThe maximum number is: %d", max);
    printf("\nThe minimum number is: %d", min);
    return 0;
}

