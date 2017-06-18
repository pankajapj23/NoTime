#include<stdio.h>
#include<memory.h>

//This function returns the position to insert the new node in sorted array
int findPosition(int *arr, int low, int high, int key)
{
    if(key < arr[low])
		//If element to enter is less than first element then insert the element at first position
		return low;
	else if(key > arr[high])
		//If element to enter is greater than last element then insert the element after last element i.e high+1
		return high+1;
	
	else
	{
		int mid = (low+high)/2;
		if(key > arr[mid])
			return findPosition(arr, mid+1, high, key);
		else
			return findPosition(arr, low, mid-1, key);
	}
	
}

int main()
{
	int curSize=5;
	int arr[20];
	memset(arr,0,sizeof(arr)); //initialize array to 0
    
	//Enter the data in array
	for(int i=0,data=10; i<curSize; i++, data=data+10)
		arr[i]=data;

	//Capacity of array
	int size = sizeof(arr)/sizeof(arr[0]);
	
	//Display array
	printf("\nArray before insertion: ");
	for(int i=0; i<curSize; i++)
		printf(" %d ", arr[i]);

	int elementToInsert =15;

	//curSize-1 is passed as high index because array start index is 0
	int posToAdd = findPosition(arr,0,curSize-1,elementToInsert);
	
	int i=curSize-1;

	//Push the element to insert the new element to maintain the sorted array
	while(i>= posToAdd)
	{
	  arr[i+1] = arr[i];
	  i--;
	}
    //Insert the new element
	arr[posToAdd] = elementToInsert;

	//Display array
	printf("\nArray after insertion: ");
	for(int i=0; i<curSize+1; i++)
		printf(" %d ", arr[i]);

	printf("\n\n");
	return 0;
}
