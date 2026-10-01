#include<stdio.h> 
#include<string.h> 

int main(){
    char id[10],a[100][100];
    int money[100],idx = 0;
    while(1){
        scanf("%s",id);
        if(strcmp(id,"-1") == 0){
            break; 
        } 
        scanf("%d",&money[idx]); 
        strcpy(a[idx],id);
        ++idx;  
    }
    int n,ans = 0; 
    scanf("%d",&n); 
    while(n--){
        char id1[10]; 
        int num; 
        scanf("%s %d",id1,&num); 
        for(int i = 0 ; i < idx ; ++i){
            if(strcmp(a[i],id1) == 0){
                ans += (num * money[i]); 
            }
        }
    }
    printf("%d",ans); 
    return 0; 
}