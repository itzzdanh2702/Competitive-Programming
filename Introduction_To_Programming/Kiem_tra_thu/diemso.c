#include<stdio.h>
#include<string.h>
#include<math.h>
#define max(a,b) (a > b) ? (a) : (b)

typedef struct{
    int num,freq;
}data;

int main(){
    int n,type;
    scanf("%d%d",&n,&type);
    data point[n];
    for(int i = 0 ; i < n ; ++i){
        point[i].freq = 0;
    }
    for(int i = 0 ; i < n ; ++i){
        double p;
        scanf("%lf",&p);
        point[i].num = round(p * 10);
        if(i > 0){
            for(int j = 0 ; j < i; ++j){
                if(point[i].num == point[j].num){
                    ++point[j].freq;
                    break;
                }
            }
        }
    }
    for(int i = 1 ; i < n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(point[i].num < point[j].num){
                data tmp = point[i];
                point[i] = point[j];
                point[j] = tmp;
            }
        }
    }
    if(type == 1){
        for(int i = 0 ; i < n ; ++i){
            printf("%.1lf ",(double)point[i].num/10);
        }
    }
    else{
        for(int i = 1 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j)
            if(point[i].freq > point[j].freq){
                data tmp = point[i];
                point[i] = point[j];
                point[j] = tmp;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(point[i].freq == point[0].freq){
                 printf("%.1lf\n",(double)point[i].num/10);
            }
        }
    }
    return 0;
}
