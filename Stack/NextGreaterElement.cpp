#include <stdio.h>

void nextGreaterElement(int *head, int size){
	int *cur = head; 
	int next, i=0, j=1;
	while(i<size)
	{
		if(j==size)
		{
			printf(" NGE of %d -> -1 \n", cur[i]); 
			i++; j=i+1;
		}
		else 
		{
			next = cur[j];
			if(next > cur[i]){ 
				printf(" NGE of %d -> %d \n", cur[i], next);
				i++; j=i+1;
			}
			else if(next <= cur[i]) j++;
		}
	}
}

int main()
{
	int a[] = {13,14,14,16,17};
	int size = sizeof(a)/sizeof(a[0]);
	
	nextGreaterElement(a, size);
	
	printf("\n");
	return 0;
}