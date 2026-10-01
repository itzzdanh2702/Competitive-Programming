#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkValidNumberPlate(char s[]){
    if(strlen(s) > 11){
        return 0;
    }
    for(int i = 0 ; i < strlen(s) ; ++i){
        if((i < 2) || (i >= 4 && i <= 7) || (i >= 9 && i <= 10)){
            if(!isdigit(s[i])){
                return 0;
            }
            if(i == 2){
                if(s[i] != '-'){
                    return 0;
                }
            }
            if(i == 8){
                if(s[i] != '.'){
                    return 0;
                }
            }
            if(i == 3){
                if(!isalpha(s[i])){
                    return 0;
                }
            }

        }
    }
    int first_Two_num = (s[0] - '0') * 10 + s[1] - '0';
    if(first_Two_num < 29 || first_Two_num > 32){
        return 0;
    }
    return 1;
}

int main(){
    char num[10][11],order[10][10] = {"first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth"};
    int total;
    printf("Please enter the number of number plate: ");
    scanf("%d",&total);
    getchar();
    for(int i = 0 ; i < total ; ++i){
        printf("Please enter the %s number plate: ",order[i]);
        scanf("%s",num[i]);
        getchar();
        if(checkValidNumberPlate(num[i])){
            printf("This number plate is valid");
        }
        else{
            printf("This number plate is invalid");
        }
        printf("\n");
    }
    return 0;
}
