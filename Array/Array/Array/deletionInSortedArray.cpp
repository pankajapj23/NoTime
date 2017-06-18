#include <stdio.h>
#include <memory.h>

int searchElementToDelete(int *A, int low, int high, int key)
{
		if(high<low)
			return -1;
		int mid = (low+high)/2;
		if(key == A[mid])
			return mid;
		else if(key < A[mid])
			return searchElementToDelete(A,low,mid-1,key);
		else
		    return searchElementToDelete(A,mid+1,high,key);
}

int main()
{
	int curSize=10;
	int A[10];
	memset(A,0,sizeof(A));
	   
	for (int i=0, data=10; i<curSize;i++,data=data+10)
		A[i] = data;

	//Display array
	printf("\nArray before deletion: ");
	for(int i=0; i<curSize; i++)
		printf(" %d ", A[i]);

	int elementToDelete =50;
	int pos = searchElementToDelete(A,0,curSize-1,elementToDelete);

	if (pos == -1)
		printf("\nElement %d is not present in Array\n", elementToDelete);
	else
	{
      //Delete the element from array by shifting the array
		while(pos<curSize)
		{
			A[pos] = A[pos+1];
			pos++;
		}
		A[pos-1]=0; //fill the empty place with 0
	}
	//Display array
	printf("\nArray after deletion: ");
	for(int i=0; i<curSize; i++)
		printf(" %d ", A[i]);

	printf("\n\n");
	return 0;
}
