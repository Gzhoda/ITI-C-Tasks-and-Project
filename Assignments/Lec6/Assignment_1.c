#include<stdio.h>
#include<stdlib.h>

int Bubble(int *ptr,int size){
	int temp;
	int iteration=0;
	for (int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(ptr[j]>ptr[j+1]){
					temp=ptr[j];
					ptr[j]=ptr[j+1];
					ptr[j+1]=temp;
			}
			iteration++; //checks what is the total runs
			
			
			// if(arr[(sizeof(arr)/4)-j]>arr[(sizeof(arr)/4)-j-1]){
					// temp=arr[(sizeof(arr)/4)-j];
					// arr[(sizeof(arr)/4)-j]=arr[(sizeof(arr)/4)-j-1];
					// arr[(sizeof(arr)/4)-j-1]=temp;
			// }
		}
	}
	return iteration;

}

int main(){
	
	//BUBBLE
	
	int temp;
	int iteration=0;
	int size; 

	
	printf("enter the size of array \n");
	scanf("%d",&size);
	int *ptr=(int*)malloc(size);

	for(int i=0;i<size;i++){
		scanf("%d",&ptr[i]);
	}

	iteration = Bubble(ptr, size);


	printf("The max is %d\n",ptr[size-1]);
	printf("The min is %d\n",ptr[0]);
	printf("The total runs : %d\n",iteration);
	for(int i=0;i<size;i++){
		printf("%d\n",ptr[i]);
	}
	
}