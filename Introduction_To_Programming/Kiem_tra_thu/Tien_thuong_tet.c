#include<stdio.h>

#define ll long long
#define max(a,b) (a > b) ? (a) : (b)

const ll oo = 1e18;

typedef struct{
    char id[10],name[50];
    ll money;
}data;

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    data log[n];
    for(int i = 0 ; i < n ; ++i){
        int month;
        scanf("%s",log[i].id);
        getchar();
        scanf("%d",&month);
        getchar();
        if(month <= 6){
            log[i].money = 1e6;
        }
        else if (month > 6 && month <= 12){
            log[i].money = 2e6;
        }
        else if (month > 12 && month < 72){
            log[i].money = 5e6;
        }
        else{
            month = (int)(month - 60)/12;
            log[i].money = 5e6 + 1e6 * month;
        }
        fgets(log[i].name,sizeof(log[i].name),stdin);
        log[i].name[strcspn(log[i].name,"\r\n")] = '\0';
    }
    int type;
    scanf("%d",&type);
    if(n <= 0 || type < 1 || type > 2){
        printf("-1");
        return 0;
    }
    if(type == 1){
        for(int i = 0 ; i < n ; ++i){
            printf("%s %lld\n",log[i].name,log[i].money);
        }
    }
    else{
        ll ma = -oo;
        for(int i = 0 ; i < n ; ++i){
            ma = max(ma,log[i].money);
        }
        printf("%lld\n",ma);
        for(int i = 0 ; i < n ; ++i){
            if(log[i].money == ma){
                printf("%s %s\n",log[i].id,log[i].name);
            }
        }
    }
    return 0;
}
