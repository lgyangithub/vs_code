#include<stdio.h>
int removeElement(int* nums, int numsSize, int val){
	int *slow = nums, *fast = nums;
	int j = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (*fast != val)
		{
			*slow = *fast;
			slow++;
			j++;
		}
		fast++;
	}
	return j;
}
