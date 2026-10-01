#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ll long long

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;


int isValid(char s[N]){
    int len = strlen(s);
    if(s[0] == '+' || s[0] == '*' || s[len - 1] == '+' || s[len - 1] == '*'){
        return 0;
    }
    for(int i = 1 ; i < len - 1; ++i){
        if(s[i] == '+' || s[i] == '*'){
            if(!isdigit(s[i + 1]) || !isdigit(s[i - 1])){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    char a[N];
    scanf("%s",a);
    getchar();
    if(!isValid(a)){
        printf("NOT_CORRECT");
    }
    else{
        int check = 0;
        ll sum = 0,product = 1,tmp = 0;
        a[strlen(a)] = '+';
        for(int i = 0 ; i <= strlen(a) ; ++i){
            if(isdigit(a[i])){
                tmp *= 10;
                tmp += (a[i] - '0');
                tmp %= MOD;
            }
            else{
                if(a[i] == '*'){
                    check = 1;
                    product *= tmp;
                    product %= MOD;
                }
                else{
                    if(check){
                        check = 0;
                        sum += (product % MOD) * (tmp % MOD);
                        sum %= MOD;
                        product = 1;
                    }
                    else{
                        sum += tmp;
                        sum %= MOD;
                    }
                }
                tmp = 0;
            }
        }
        printf("%lld",sum);
    }
    return 0;
}
