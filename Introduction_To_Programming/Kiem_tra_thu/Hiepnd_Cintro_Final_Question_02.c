#include<stdio.h>
#include<string.h>

typedef struct{
	char id[10],car_num[13],date[20],time[20];
} data;

int main(){
	int idx = 0;
	data log[1001];
	while(1){
		scanf("%s",&log[idx].id);
		getchar();
		if(strcmp(log[idx].id,"#") == 0){
			break;
		}
		scanf("%s",&log[idx].car_num);
		getchar();
		scanf("%s",&log[idx].date);
		getchar();
		scanf("%s",&log[idx].time);
		getchar();
		++idx;
	}
	int type;
	char log1[20];
	scanf("%d%s",&type,log1);
	getchar();
	if(type == 1){
		int check = 0;
		for(int i = 0 ; i < idx ; ++i){
			if(strcmp(log[i].car_num,log1) == 0){
				check = 1;
				printf("%s %s\n",log[i].date,log[i].time);
			}
		}
		if(!check){
			printf("-1");
		}
	}
	else{
		int cnt = 0,check1[1001];
		for(int i = 0 ; i < 1000 ; ++i){
			check1[i] = 0;
		}
		if(strcmp(log[0].date,log1) == 0){
			check1[0] = 1;
		}
		int pos = -1;
		for(int i = 1 ; i < idx ; ++i){
			int ok = 1;
			if(strcmp(log[i].date,log1) == 0){
                if(pos == -1){
                    check1[i] = 1;
                    pos = i;
                }
                else{
                    for(int j = pos ; j < i ; ++j){
                        if(strcmp(log[i].car_num,log[j].car_num) == 0){
                            ok = 0;
                            break;
                        }
                    }
                    if(ok){
                        check1[i] = 1;
                    }
                }
            }

		}
		for(int i = 0 ; i < idx ; ++i){
			if(check1[i]){
				++cnt;
			}
		}
		printf("%d",cnt);
	}
	return 0;
}
