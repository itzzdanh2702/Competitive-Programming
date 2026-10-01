#include<stdio.h>
#include<string.h>

typedef struct{
    char ma_sp[100],ten_sp[100];
    int price;
}data;

typedef struct{
    char ma_sp[100];
    int sl;
}data1;

int main(){
    int n,d[100];
    data product[100];
    data1 buy[100];
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++i){
        d[i] = 0;
    }
    for(int i = 0 ; i < n ; ++i){
        scanf("%s",product[i].ma_sp);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(product[i].ten_sp,sizeof(product[i].ten_sp),stdin);
        product[i].ten_sp[strcspn(product[i].ten_sp,"\r\n")] = '\0';
        scanf("%d",&product[i].price);
    }
    char type[100];
    while(1){
        scanf("%s",type);
        getchar();
        if(strcmp(type,"$") == 0){
            break;
        }
        int idx = 0,ok = 1;
        while(1){
            scanf("%s",buy[idx].ma_sp);
            getchar();
            if(strcmp(buy[idx].ma_sp,"#") == 0){
                break;
            }
            scanf("%d",&buy[idx].sl);
            getchar();
            int check = 0;
            for(int i = 0 ; i < n ; ++i){
                if(strcmp(buy[idx].ma_sp,product[i].ma_sp) == 0){
                    d[i] += buy[idx].sl;
                    check = 1;
                }
            }
            if(!check){
                ok = 0;
            }
            ++idx;
        }
        if(!ok){
            for(int i = 0 ; i < idx ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if(strcmp(buy[i].ma_sp,product[j].ma_sp) == 0){
                        d[j] -= buy[i].sl;
                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < idx ; ++i){
            strcpy(buy[i].ma_sp,"");
            buy[i].sl = 0;
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; ++i){
        if(d[i] > 0){
              printf("%s : %d\n",product[i].ten_sp,d[i]);
        }
        else{
            ++cnt;
        }
    }
    if(cnt == n){
        printf("-1");
    }
    return 0;
}
