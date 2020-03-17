#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int array[],int size){
	bool b = true;
	while(b){
		 b= false;
		 int i;
		 for(i = 0; i<size-1;i++){
			if(array[i]>array[i+1]){
				int temp = array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
				
			}
			b = true;
		 }
		 size--;
	}
}

int main(void){
	int array[] = {1,2,7,5,9,3,15,11,17,12};
	bubble_sort(array,10);
	for(int i = 0; i< 10;i++){
		printf("%d ",array[i]);
	}



}
