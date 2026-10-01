#include<stdio.h>
#include<string.h>
#include<ctype.h>

const int N = 100;

int check_valid(char a[]){
    for(int i = 0 ; i < strlen(a) ; ++i){
        if(!isalpha(a[i]) && a[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void clear(){
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main(){
    int n,valid = 1;
    int idx = 0;
    scanf("%d",&n);
    clear();
    char s[n][N];
    for(int i = 0 ; i < n ; ++i){
        char a[N];
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\r\n")] = '\0';
        int check = 0;
        if(!check_valid(a)){
            valid = 0;
            continue;
        }
        int pos;
        char *last = strrchr(a,' ');
        if(last != NULL){
            pos = last - a;
        }
        else{
            pos = -1;
        }
        int pos1 = 0;
        char tmp[N];
        for(int j = pos + 1; j < strlen(a) ; ++j){
            tmp[pos1] = a[j];
            ++pos1;
        }
        tmp[pos1] = '\0';
        strcpy(s[i],tmp);
    }
    if(!valid){
        printf("INVALID INPUT");
        return 0;
    }
    else{
        int d[N];
        for(int i = 0 ; i < N ; ++i){
            d[i] = 0;
        }
        d[0] = 1;
        for(int i = 1 ; i < n ; ++i){
            int ok = 0;
            for(int j = 0 ; j < i ; ++j){
                if(strcmp(s[i],s[j]) == 0){
                    ok = 1;
                    ++d[j];
                    break;
                }
            }
            if(!ok){
                ++d[i];
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(d[i] > 0){
                printf("%s %d\n",s[i],d[i]);
            }
        }
    }
}
