// Calloc funtion in C allows to reserve an amount of bytes in computer memory.
#include<stdio.h>
#include<stdlib.h>//standard library for calloc fun
int main(){


        printf("Enter the number of elements: ");
        int n;

        scanf("%d",&n);
        int *arr = (int *)calloc(n,sizeof(int));

        printf("Now enter the elements: ");

        for (int i = 0; i < n;i++){
                scanf("%d",arr+i);  
        }

        for (int i = 0; i < n; i++ ){
                printf("%d\t",*(arr+i));        

        }
	
	free(arr);
	return 0;
}

/*

#Output:

Enter the number of elements: 7
Now enter the elements: 123 321 78 12 45 85 90
123	321	78	12	45	85	90

*/
