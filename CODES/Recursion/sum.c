#include <stdio.h>
int sum(int,int);
int main()
{
    int r;
    r=sum(10,20);
    printf("The sum is: %d",r);
    return 0;
}
int sum(int x,int y)
{
    //body of sum function
    //base case
    if(y==0){
        return x;
    }else{
        return sum(x+1,y-1);
    }
   
}