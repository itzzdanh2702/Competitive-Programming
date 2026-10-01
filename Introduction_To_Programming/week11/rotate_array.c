#include<stdio.h> 

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b; 
    *b = tmp; 
}

void reverse_arr(int *n,int a[]){
    for(int i = 0 ; i < *n/2 ; ++i){
        swap(&a[i],&a[*n - 1 - i]); 
    }
}

void rotate_arr(int *n,int *k,int a[]){
    int rotate[*n];
     for(int i = 0 ; i < *n ; ++i){
        if(i < *n - *k)
            rotate[i] = a[i + *k]; 
        else
            rotate[i] = a[*k - (*n - i)]; 
    }
    for(int i = 0 ; i < *n ; ++i){
        printf("%d ",rotate[i]); 
    }
    printf("\n"); 
}

int main()
{
    printf("====================ROTATE ARRAY====================\n");
    int n,k; 
    printf("Input the length of the array: "); 
    scanf("%d",&n);
    printf("Input the offset of the array: ");
    scanf("%d",&k);
    int a[n],rotate[n];
    for(int i = 0 ; i < n ; ++i){
        printf("Input the a[%d] element of the array: ",i + 1); 
        scanf("%d",&a[i]); 
    }  
    printf("The array after rotate from left to right is : "); 
    rotate_arr(&n,&k,a); 
    reverse_arr(&n,a);
    printf("The array after rotate from right to left is : "); 
    rotate_arr(&n,&k,a); 
    return 0; 
}