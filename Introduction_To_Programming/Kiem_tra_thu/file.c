#include<stdio.h>

int main(){
    int a = 10;
    int b = 20;
    int *p1 = &a;
    int *p2 = &b;

    if (p1 < p2) {
        printf("1");
    }
}
