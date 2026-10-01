#include<stdio.h> 
#include<string.h> 

#define max(a,b) (a > b) ? (a) : (b)

const int oo = 1e9; 

char round(char a[]){ 
    a[strlen(a)] = '0'; 
    for(int i = strlen(a) - 1 ; i >= 0 ; --i){
        if(a[i] != '.'){
            int next_num = a[i + 1] - '0';
            int cur_num = a[i] - '0';
            if(next_num > 5){
                a[i] = itoa(++cur_num); 
            }  
        }
        else{
            break; 
        }
    }
    return *a; 
}


void sort_num(int size,char a[][300]){
    char tmp[300]; 
    for(int i = 1 ; i < size ; ++i){
        for(int j = i - 1 ; j < i ; ++j){
            if(strcmp(a[i],a[j]) < 0){
                strcpy(tmp,a[i]); 
                strcpy(a[i],a[j]); 
                strcpy(a[j],tmp); 
            }
        }
    }
}

int main()
{   
    char a[300][300]; 
    int sz,type; 
    scanf("%d%d",&sz,&type);
    for(int i = 0 ; i < sz ; ++i){
        scanf("%c",a[i]); 
        strcpy(a[i],round(a[i])); 
    }        
    sort_num(sz,a);
    int idx = 0,count = 0,ma = -oo; 
    int cnt[301]; 
    char assign[301];  
    strcpy(a[sz],"-1"); 
    for(int i = 0 ; i <= sz - 1; ++i){ 
        ++count; 
        if(strcpy(a[i],a[i + 1]) == 0){
            ++count; 
        }   
        else{
            cnt[++idx] = count; 
            ma = max(ma,count); 
            strcpy(assign[idx],a[i]); 
            count = 0; 
        }
    }   
    for(int i = 1 ; i <= idx ; ++i){    
        if(cnt[i] == ma){
            if(type == 1){
                printf("%s ",assign[i]);
            }
            else{
                printf("%s\n",assign[i]); 
            }
        }
    }
    return 0; 
}