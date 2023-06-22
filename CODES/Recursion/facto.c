#include <stdio.h>
int facto1(int);
int facto2(int);
int main()
{
    int n,r;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    r=facto1(n);
    printf("The factorial value of %d is: %d",n,r);
    return 0;
}
int facto1(int x)
{
    if(x==0){
        return 1;
    }else{
        return x*facto2(x-1);
    }
}
int facto2(int x)
{
    if(x==0){
        return 1;
    }else{
        return x*facto1(x-1);
    }
}