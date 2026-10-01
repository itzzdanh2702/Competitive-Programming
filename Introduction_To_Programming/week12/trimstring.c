#include<stdio.h> 
#include<string.h> 

void trimRight(char a[]){
    int pos;  
    for(int i = strlen(a) - 1; i >= 0 ; --i){
        if(a[i] != ' '){
            pos = i; 
            break; 
        }
    }   
    printf("The string after trim right is: "); 
    for(int i = 0 ; i <= pos ; ++i){
        printf("%c",a[i]); 
    }
    printf("\n"); 
}

void trimLeft(char a[]){
    int pos;
    for(int i = 0; i < strlen(a) ; ++i){
        if(a[i] != ' '){
            pos = i; 
            break; 
        }
    }   
    printf("The string after trim left is: "); 
    for(int i = pos ; i < strlen(a) ; ++i){
        printf("%c",a[i]);
    }
    printf("\n"); 
}

void trimMiddle(char a[]){
    int pos1,pos2;
    for(int i = strlen(a) - 1; i >= 0 ; --i){
        if(a[i] != ' '){
            pos1 = i; 
            break; 
        }
    }   
    printf("The string after trim middle is: "); 
    for(int i = 0; i < strlen(a) ; ++i){
        if(a[i] != ' '){
            pos2 = i; 
            break; 
        }
        else{
            printf("%c",a[i]); 
        }
    }
    int check = 0;
    for(int i = pos2 ; i <= pos1 ; ++i){
        if(a[i] == ' '){
            if(!check){
                check = 1;
                printf("%c",a[i]); 
            } 
        }
        else{
            check = 0; 
            printf("%c",a[i]); 
        } 
    }  
    for(int i = pos1 + 1; i < strlen(a) ; ++i){
        printf("%c",a[i]); 
    }
    printf("\n");  
}

int main()
{
    char a[100]; 
    printf("Please input a string:"); 
    fgets(a,100,stdin); 
    a[strcspn(a,"\n")] = '\0'; 
    trimLeft(a); 
    trimRight(a); 
    trimMiddle(a); 
    return 0; 
}