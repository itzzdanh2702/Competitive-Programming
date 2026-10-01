#include<stdio.h> 

#define ui unsigned int

ui reverse(ui *k){
    ui ans = 0;  
    while(*k > 0){
        ans *= 10; 
        ans += *k % 10; 
        *k /= 10; 
    }
    return ans; 
}

int main()
{
    printf("====================REVERSE INT====================\n");
    ui a; 
    printf("Vui long nhap vao so a: "); 
    scanf("%u",&a);  
    ui tmp = a; 
    printf("So dao nguoc cua so %u la: %u",tmp,reverse(&a));
    return 0; 
}