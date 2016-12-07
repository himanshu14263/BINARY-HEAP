// PROBLEM :: HEAP SORT OF GIVEN ARRAY

#include<bits/stdc++.h>
using namespace std;

int parent(int i){return (i-1)/2;}
int left(int i){return (2*i+1);}
int right(int i){return (2*i+2);}


void heapify(int arr[],int n,int i)
{
	// finding left and right of current node
	int l=left(i);
	int r=right(i);

	// assuming the current parent has max value
	int max=i;

	// comparing parent data with left child and accordingly changing the max value
	if(l<n && arr[i]<arr[l])
		max=l;

	// comparing parent data with left child and accordingly changing the max value
	if(r<n && arr[max]<arr[r])
		max=r;

	// if the initial assumption isn't satisfied then swap and make the max one as parent
	if(max!=i)
	{
		swap(arr[max],arr[i]);

		// after making swap we need to maintain the property by heapifying it.
		heapify(arr,n,max);
	}
}


// we follow the following algorithm
// step 1: build max heap from the input data
// step 2: at this time the largest item is stored at the root of the heap.
// 		   replace this item with the last item of the heap followed by reducing
//		   the size of heap by 1. Finally heapify the root of the tree
// step 3: repeat the above steps until the heap size is greater than 1.

void heapSort(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
		heapify(arr,n,i);

	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
int main()
{
	int arr[5]={3,4,8,6,2};
	int n=5;
	heapSort(arr,n);

	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
}
