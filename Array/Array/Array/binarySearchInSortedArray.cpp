#include<stdio.h>
#include<memory.h>

//Binary search
int binarySearch(int *arr, int low, int high, int key)
{
    int mid = (low+high)/2;
	
	if(high<low) return -1;

	if(key == arr[mid])
		return mid;
	else if(key > arr[mid])
		return binarySearch(arr, mid+1, high, key);
	else
		return binarySearch(arr, low, mid-1, key);
}

int main()
{
	int arr[20];
	memset(arr,0,sizeof(arr)); //initialize array to 0
    
	//Enter the data in array
	for(int i=0,data=10; i<10; i++, data=data+10)
		arr[i]=data;

	//Capacity of array
	int size = sizeof(arr)/sizeof(arr[0]);
	
	//Display array
	for(int i=0; i<20; i++)
		printf(" %d ", arr[i]);

	int key =20;
	int pos = binarySearch(arr,0,size,key);
	(pos == -1)?
		printf("\n\nElement not present in array!!!"):
	    printf("\n\nElement %d is found at %dth position", key, pos+1);


	printf("\n\n");
	return 0;
}
