#include<stdio.h>
#include<string.h>
#include<ctype.h>

const int N = 100;
typedef struct{
    char car_num[50],date[20],time[20];
    int status;
}data;

void standardlise_string(){
    int c;
    while((c = getchar() != '\n') && c != EOF);
}

int main(){
    int idx = 0;
    data log[N];
    while(1){
        fgets(log[idx].car_num,sizeof(log[idx].car_num),stdin);
        log[idx].car_num[strcspn(log[idx].car_num,"\r\n")] = '\0';
        if(strcmp(log[idx].car_num,"-1") == 0){
            break;
        }
        scanf("%s",log[idx].date);
        getchar();
        scanf("%s",log[idx].time);
        getchar();
        scanf("%d",&log[idx].status);
        getchar();
        ++idx;
    }
    int check[idx - 1];
    for(int i = 0 ; i < idx ; ++i){
        check[i] = 0;
    }
    if(log[idx - 1].status == 1){
        check[idx - 1] = 1;
    }
    for(int i = idx - 2 ; i >= 0 ; --i){
        int ok = 1;
        for(int j = i + 1 ; j < idx ; ++j){
            if(strcmp(log[i].car_num,log[j].car_num) == 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            check[i] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < idx; ++i){
        if(check[i] && log[i].status == 1){
            ++cnt;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0 ; i <= idx ; ++i){
        if(check[i] && log[i].status == 1){
            printf("%s\n",log[i].car_num);
        }
    }
    return 0;
}
