#include<stdio.h>

typedef struct {
    int point;
    char name[30];
}data;

int main(){
    int n;
    data team[20];
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++i){
        team[i].point = 0;
        scanf("%s",team[i].name);
        getchar();
    }
    int match = n * (n - 1)/2;
    for(int i = 0 ; i < match ; ++i){
        int num1,num2,goal1,goal2;
        scanf("%d%d%d%d",&num1,&num2,&goal1,&goal2);
        if(goal1 > goal2){
            team[num1 - 1].point += 3;
        }
        else if (goal1 == goal2){
            ++team[num1 - 1].point;
            ++team[num2 - 1].point;
        }
        else{
            team[num2 - 1].point += 3;
        }
    }
    for(int i = 1 ; i < n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(team[i].point > team[j].point){
                data tmp = team[i];
                team[i] = team[j];
                team[j] = tmp;
            }
        }
    }
    for(int i = 0 ; i < 3 ; ++i){
        printf("%s %d\n",team[i].name,team[i].point);
    }
    return 0;
}
