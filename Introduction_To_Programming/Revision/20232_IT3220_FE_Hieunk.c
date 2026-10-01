#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char name[41];
    int height;
}data;

void sort(int sz,data person[]){
    for(int i = 1 ; i < sz ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(person[i].height < person[j].height){
                data tmp = person[i];
                person[i] = person[j];
                person[j] = tmp;
            }
            else if (person[i].height == person[j].height){
                if(strcmp(person[i].name,person[j].name) < 0){
                    data tmp = person[i];
                    person[i] = person[j];
                    person[j] = tmp;
                }
            }
        }
    }
}
int main(){
    int type;
    scanf("%d",&type);
    int idx1 = 0,idx2 = 0;
    data boys[100],girls[100];
    while(1){
        char name[41];
        int gender,height;
        scanf("%s",name);
        getchar();
        if(strcmp(name,"#") == 0){
            break;
        }
        scanf("%d %d",&gender,&height);
        if(!gender){
            strcpy(boys[idx1].name,name);
            boys[idx1].height = height;
            ++idx1;
        }
        else{
            strcpy(girls[idx2].name,name);
            girls[idx2].height = height;
            ++idx2;
        }
    }
    sort(idx1,boys);
    sort(idx2,girls);
    if(type == 1){
        if(idx2 == 0){
            printf("\n");
            return 0;
        }
        for(int i = 0 ; i < idx2 ; ++i){
            printf("%s %d\n",girls[i].name,girls[i].height);
        }
    }
    else{
        if(idx1 == 0 && idx2 == 0){
            printf("\n");
            return 0;
        }
        int i = 0,j = 0;
        while(i < idx2 || j < idx1){
            if(i < idx2){
                printf("%s %d\n",girls[i].name,girls[i].height);
                ++i;
            }
            if(j < idx1){
                printf("%s %d\n",boys[j].name,boys[j].height);
                ++j;

            }
        }
    }

    return 0;
}
