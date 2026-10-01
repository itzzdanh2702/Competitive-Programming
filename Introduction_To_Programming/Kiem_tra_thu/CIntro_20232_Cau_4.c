#include<stdio.h>
#include<string.h>
#include<ctype.h>

int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ok(char a){
    if(isdigit(a)){
        return 1;
    }
    return 0;
}

int check(char a[]){
    if(strlen(a) != 10){
        return 0;
    }
    if(!ok(a[0]) || !ok(a[1]) || !ok(a[3]) || !ok(a[4]) || !ok(a[6]) || !ok(a[7]) || !ok(a[8]) || !ok(a[9])){
        return 0;
    }
    if(a[2] != '/' || a[5] != '/'){
        return 0;
    }
}

int check_year(int year){
    if(year % 4 == 0 && year % 100 == 0){
        return 0;
    }
    return 1;
}

int check1(char s[]){
    int month = (s[0] - '0') * 10 + (s[1] - '0');
    int day = (s[3] - '0') * 10 + (s[4] - '0');
    int year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    if(!check_year(year)){
        return 0;
    }
    if(month < 1 || month > 12){
        return 0;
    }
    if(day < 1 || day > date[month - 1]){
        return 0;
    }
    return 1;
}

int main(){
    char s[100];
    scanf("%s",s);
    getchar();
    if(!check(s)){
        printf("-1");
    }
    else{
        if(!check1(s)){
            printf("-2");
            return 0;
        }
        int month = (s[0] - '0') * 10 + (s[1] - '0');
        int day = (s[3] - '0') * 10 + (s[4] - '0');
        int year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
        printf("ngay %d, thang %d, nam %d",day,month,year);
    }
    return 0;
}
