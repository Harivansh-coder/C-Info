/* Realloc funtion in C allows to resize the memory,
   already allocated by malloc or calloc funtion.
*/ 
#include<stdio.h>
#include<stdlib.h>//standard library for calloc fun
int main(){


        printf("Enter the number of elements: ");
        int n,*arr;
	
	//Calloc implemented
        scanf("%d",&n);
        arr = (int *)calloc(n,sizeof(int));

	printf("Now enter the elements: ");

        for (int i = 0; i < n;i++){
                scanf("%d",arr+i);  
        }
	printf("Old array: ");
        for (int i = 0; i < n; i++ ){
                printf("%d\t",*(arr+i));        

        }

	printf("\n");
	
	//Realloc implemented
	printf("Enter the new size: ");
	scanf("%d",&n);
	
	
	arr = (int *)realloc(arr,n);
	
        printf("\nNow enter the elements: ");

        for (int i = 0; i < n;i++){
                scanf("%d",arr+i);  
        }
	printf("New array: ");
        for (int i = 0; i < n; i++ ){
                printf("%d\t",*(arr+i));        

        }

	free(arr);
	return 0;
}

/*
#Output:

Enter the number of elements: 5
Now enter the elements: 1 2 3 4 5
Old array: 1	2	3	4	5	
Enter the new size: 3
Now enter the elements: 1 2 3
New array: 1	2	3

*/
