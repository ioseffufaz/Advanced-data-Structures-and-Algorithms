#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool binarySearch(int array[], int size, int number){
	int first,last,middle;
	first = 0;	
	last = size - 1;
	middle = (first + last)/2;
	while(first <= last ){
		if(array[middle] < number) first = middle + 1;
		else if(array[middle]==number) return true;
		else last = middle - 1;
		middle=(first+last)/2;
	}
	return false;
}
int main(void){
	int array[] = {1,2,5,7,9,19,56,73,100};
	printf("%d",binarySearch(array,9,19));
	// Output:              1 (true)
	// Time Complexity :    log(n)
	// Best Case:           O(1)
	// Worst Case:          O(log(n))
	return 0;


}
