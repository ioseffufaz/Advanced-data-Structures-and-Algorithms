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

/*
Analysis Of Bubble Sort
 In Bubble Sort, n-1 comparisons will be done in the 1st pass, n-2 in 2nd pass, n-3 in 3rd pass and so on. So the total number of comparisons will be,
(n-1) + (n-2) + (n-3) + ..... + 3 + 2 + 1
Sum =          n(n-1)/2
Complexity:    O(n2)
 

*/
int main(void){
	int array[] = {1,2,7,5,9,3,15,11,17,12};
	bubble_sort(array,10);
	for(int i = 0; i< 10;i++){
		printf("%d ",array[i]);
	}



}
