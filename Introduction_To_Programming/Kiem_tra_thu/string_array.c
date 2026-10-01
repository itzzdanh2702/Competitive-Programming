#include<stdio.h>
#include<string.h>
#include<ctype.h>

const int N = 256;

int main(){
    char a[N];
    fgets(a,sizeof(a),stdin);
    a[strcspn(a,"\r\n")] = '\0';
    int n = strlen(a),pos = 0;
    char tmp[N];
    //strcpy(tmp,'\0');
    for(int i = 0 ; i < n ; ++i){
        if(isalpha(a[i]) || isdigit(a[i]) || a[i] == ' '){
            tmp[pos] = a[i];
            ++pos;
        }
    }
    char tmp1[N],pos1 = 0;
    int check = 0,space = 0;
    for(int i = 0 ; i < pos ; ++i){
        if(tmp[i] == ' '){
            if(!check){
                continue;
            }
            else{
                if(!space){
                    space = 1;
                    tmp1[pos1] = ' ';
                    ++pos1;
                }
            }

        }
        if(isalpha(tmp[i])){
            space = 0;
            check = 1;
            tmp1[pos1] = tmp[i];
            ++pos1;
        }
    }
    int pos2 = 1;
    char ans[N];
    ans[0] = tmp1[0];
    for(int i = 1 ; i < pos1 ; ++i){
        if(tmp1[i] == tmp1[i - 1]){
            continue;
        }
        else{
            ans[pos2] = tmp1[i];
            ++pos2;
        }
    }
    for(int i = 0 ; i < pos2 ; ++i){
        printf("%c",ans[i]);
    }
    return 0;
}

