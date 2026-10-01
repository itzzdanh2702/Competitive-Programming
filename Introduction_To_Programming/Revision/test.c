#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0 ; i < n ; ++i){
        char a[100],b[100];
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\r\n")] = '\0';
        char *pointer = NULL;
        pointer = strchr(a,' ');
        int pos = pointer - a;
        strncpy(b,a,pos);
        b[pos] = '\0';
        printf("%s",b);
    }
}
