#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max(a,b) (a > b) ? (a) : (b)

int main(){
    int n,cnt = 0,count[100],check[100],assign_idx[100];
    char ans[100][100],assign_str[100][100],str[100][100];
    for(int i = 0 ; i < 100 ; ++i){
        check[i] = 1,count[i] = 0,assign_idx[i] = 0;
    }
    scanf("%d",&n);
    getchar();
    for(int pos = 0 ; pos < n ; ++pos){
        char a[100];
        char *first = NULL;
        int check_letter = 1;
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\r\n")] = '\0';
        first = strchr(a,' ');
        if(first == NULL){
            check[pos] = 0;
            continue;
        }
        for(int i = 0 ; i < strlen(a) ; ++i){
            if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] == ' ')){
                continue;
            }
            check_letter = 0;
            break;
        }
        strncpy(str[pos],a,first - a);
        str[pos][first - a] = '\0';
        if(!check_letter){
            printf("INVALID INPUT"); 
            return 0; 
        }
        int ok = 0;
        for(int i = 0; i <= pos - 1; ++i){
            if(!check[i] || pos == 0){
                continue;
            }
            if(strcmp(str[pos],str[i]) == 0){
                ++count[assign_idx[i]];
                ok = 1;
                break;
            }
        }
        if(!ok){
            assign_idx[pos] = ++cnt;
            ++count[cnt];
            strcpy(assign_str[cnt],str[pos]);
        }
    }
    for(int i = 1 ; i <= cnt ; ++i){
        printf("%s %d\n",assign_str[i],count[i]);
    }
    return 0;
}

