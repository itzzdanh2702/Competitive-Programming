#include <stdio.h> 
#include <string.h> 

#define max(a,b) ((a) > (b) ? (a) : (b))

struct detail{
    char car_num[15]; 
    char time[50]; 
    int status; 
    int assign; 
} car[100];

void standaliseString(char* str){
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\r' || str[len - 1] == '\n')) {
        str[len - 1] = '\0';
        len--;
    }
}

void clearStdin(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    int idx = 0, num = 0; 
    int count[100][2] = {0}; 
    char assign[100][15]; 

    while(1){
        fgets(car[idx].car_num, sizeof(car[idx].car_num), stdin);
        standaliseString(car[idx].car_num); 
        if(strcmp(car[idx].car_num, "-1") == 0){
            break; 
        }
        fgets(car[idx].time, sizeof(car[idx].time), stdin); 
        standaliseString(car[idx].time);
        scanf("%d", &car[idx].status); 
        clearStdin();
        
        int check = 0, pos = -1; 
        for(int i = idx - 1; i >= 0 ; --i){
            if(strcmp(car[i].car_num, car[idx].car_num) == 0){
                check = 1; 
                pos = i; 
                break; 
            }
        }

        if(!check){
            ++num; 
            strcpy(assign[num], car[idx].car_num);
            car[idx].assign = num; 
            count[num][car[idx].status]++;
        }
        else{
            car[idx].assign = car[pos].assign; 
            count[car[idx].assign][car[idx].status]++;
        }
        ++idx;
    }
    int cnt = 0; 
    for(int i = 1 ; i <= num ; ++i){
        if(count[i][0] < count[i][1]){
            ++cnt; 
        }
    }
    printf("%d\n",cnt);
    for(int i = 1 ; i <= num ; ++i){
        if(count[i][0] < count[i][1]){
            printf("%s\n",assign[i]); 
        }
    }
    return 0;
}