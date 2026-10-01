#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

const int N = 100000;

int main(){
    int a[N],cnt = 0;
    char s[N];
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\r\n")] = '\0';
    for(int i = 0 ; i < N ; ++i){
        a[i] = 0;
    }
    for(int i = 0 ; i < strlen(s) ; ++i){
        if(isdigit(s[i])){
            a[cnt] *= 10;
            a[cnt] += (s[i] - '0');
        }
        else if (s[i] == ' '){
            ++cnt;
        }
    }
    int k, ans = 0;
    scanf("%d",&k);
    for(int i = 0 ; i < cnt ; ++i){
        if(a[i] % k == 0){
            ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}
