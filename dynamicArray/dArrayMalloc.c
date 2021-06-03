// Malloc funtion in C allows to reserve an amount of bytes in computer memory (Heap) 
#include<stdio.h>
#include<stdlib.h>//standard library for malloc
int main(){
	

	printf("Enter the number of elements: ");
	int n;

	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	
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

Enter the number of elements: 5
Now enter the elements: 1 2 3 4 5
1	2	3	4	5

*/
