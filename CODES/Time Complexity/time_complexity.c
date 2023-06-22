#include <stdio.h>
void sumofNumber(double n)
{
    double sum=0;
    int i;
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("The value of sum is: %lf",sum);
}
void optimizedSumofNumber(double n)
{
    double sum;
    sum = (n*(n+1))/2;//changes
    printf("The optimized value of sum is: %lf",sum);
}
int main()
{
    double num;
    printf("Enter the value of number: ");
    scanf("%lf",&num);
    sumofNumber(num);
    optimizedSumofNumber(num);
    return 0;
}