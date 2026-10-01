#include<stdio.h>
#include<string.h>

const int N = 1000;
typedef struct{
    char time[20],id[50],p;
}data;

int main(){
    int idx = 0;
    data log[N];
    while(1){
        scanf("%s",log[idx].time);
        getchar();
        if(strcmp(log[idx].time,"#") == 0){
            break;
        }
        scanf("%s",log[idx].id);
        getchar();
        scanf("%c",&log[idx].p);
        getchar();
        ++idx;
    }
    int type;
    scanf("%d",&type);
    if(type < 1 || type > 2){
        printf("-1");
        return 0;
    }
    int check[idx];
    for(int i = 0 ; i < idx ; ++i){
        if(strcmp(log[i].time,"08:00:00") == 1 && strcmp(log[i].time,"17:59:59") == -1){
            check[i] = 1;
        }
        else{
            check[i] = 0;
        }
    }
    for(int i = 1 ; i < idx ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(strcmp(log[i].id,log[j].id) == 0){
                check[i] = check[j] = 0;
                break;
            }
        }
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0 ; i < idx ; ++i){
        if(!check[i]){
            continue;
        }
        if(log[i].p == 'A'){
            ++cnt1;
        }
        else{
            ++cnt2;
        }
    }
    if(type == 1){
        printf("%d",cnt1 + cnt2);
    }
    else{
        printf("%d %d",cnt1,cnt2);
    }
    return 0;
}
