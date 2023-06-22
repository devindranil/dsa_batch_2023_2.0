#include <stdio.h>
int fibo(int);
int main()
{
    int n,r,i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    //print the series
    for(i=0;i<=n;i++)
    {
        printf("%d",fibo(i));
    }
    printf("\n");
    r=fibo(n);
    printf("The value of %d term of the fibonacii series is: %d",n,r);
    return 0;
}
int fibo(int x)
{
    //base case
    if(x==0||x==1){
        return x;
    }
    //recursive case
    else{
        return fibo(x-1)+fibo(x-2);
    }
}