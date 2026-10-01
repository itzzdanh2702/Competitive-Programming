#include<stdio.h>
#include<string.h>

const int N = 1e5 + 1;
typedef struct{
    double temp;
    char location[10],time[20];
}data;


int main(){
    data log[N];
    int idx = 0;
    double a,s;
    scanf("%lf%lf",&a,&s);
    while(1){
        scanf("%s",&log[idx].location);
        if(strcmp(log[idx].location,"#") == 0){
            break;
        }
        scanf("%lf",&log[idx].temp);
        scanf("%s",&log[idx].time);
        ++idx;
    }
    for(int i = 1 ; i < idx ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(strcmp(log[i].location,log[j].location) < 0){
                data temp = log[i];
                log[i] = log[j];
                log[j] = temp;
            }
        }
    }
    int cur_cnt = 0,cnt1 = 0,cnt2 = 0;
    double cur_sum = 0,square = 0;
    strcpy(log[idx].location,"#");
    for(int i = 0 ; i < idx ; ++i){
        cur_sum += log[i].temp;
        square += log[i].temp * log[i].temp;
        ++cur_cnt;
        if(strcmp(log[i].location,log[i + 1].location) != 0){
            cur_sum /= cur_cnt;
            double tmp = (double)(1.00/cur_cnt) * square - cur_sum * cur_sum;
            if(cur_sum <= a){
                ++cnt1;
            }
            if (tmp - s * s <= 0){
                ++cnt2;
            }
            cur_sum = cur_cnt = square = 0;
        }
    }
    printf("%d %d",cnt1,cnt2);
    return 0;
}
