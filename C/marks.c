#include <stdio.h>
int main()
{
    int mark;
    printf("What is the mark? ");
    scanf("%d", &mark);

    if(mark>=70 && mark<100){
        printf("A\n");
    }
    else if(mark>=60 && mark<70){
        printf("B\n");
    }
    else if(mark>=50 && mark<60){
        printf("C\n");
    }
    else if(mark>=40 && mark<50){
        printf("D\n");
    }
    else if(mark>=0 && mark<40){
        printf("E\n");
    }
    else {
        printf("invalid mark");
    }
    
    return 0;
}

