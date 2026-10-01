#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int check1 = 0,check2 = 0,check3 = 0,check4 = 0,error = 0;
    char car_num[100];
    scanf("%s",car_num);
    getchar();
    if(strlen(car_num) != 9){
        printf("0");
        return 0;
    }
    int num = (car_num[0] - '0') * 10 + (car_num[1] - '0');
    if((!isdigit(car_num[0])) || (!isdigit(car_num[1]) || (num < 11 || num > 99))){
        check1 = 1;
        ++error;
    }
    if(!isalpha(car_num[2]) || (!isalpha(car_num[3]) && !isdigit(car_num[3]))){
        check2 = 1;
        ++error;
    }
    int num1 = 0;
    for(int i = 4 ; i <= 8 ; ++i){
        if(!isdigit(car_num[i])){
            check3 = 1;
            break;
        }
        num1 *= 10;
        num1 += (car_num[i] - '0');
    }
    if(num1 == 0){
        check3 = 1;
    }

    if(check3){
        ++error;
    }
    if(error >= 2){
        printf("0");
        return 0;
    }
    if(check1){
        printf("-1");
    }
    else if (check2){
        printf("-2");
    }
    else if (check3){
        printf("-3");
    }
    else{
        printf("1");
    }
    return 0;
}
