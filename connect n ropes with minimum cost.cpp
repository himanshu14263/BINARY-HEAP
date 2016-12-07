// PROBLEM :: CONNECT N ROPES WITH MINIMUM COST

#include<bits/stdc++.h>
using namespace std;

void minHeapify(int harr[],int size,int i)
{
	int l=2*i+1;
	int r=2*i+2;

	int smallest=i;
	if(l<size && harr[i]>harr[l])
		smallest=l;
	if(r<size && harr[smallest]>harr[r])
		smallest=r;

	if(smallest!=i)
	{
		swap(harr[smallest],harr[i]);
		minHeapify(harr,size,smallest);
	}
}
void insertHeap(int harr[],int x,int&size)
{
	size++;
	harr[size-1]=x;
	int i=size-1;

	while(i!=0 && (harr[(i-1)/2]>harr[i]))
	{
		swap(harr[(i-1)/2],harr[i]);
		i=(i-1)/2;
	}
}

int extractHeap(int harr[],int &size)
{
	if(size==0)
		return INT_MAX;
	if(size==1)
	{
		size--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[size-1];
	size--;

	minHeapify(harr,size,0);
	return root;
}

// the main logic is as follows:
// 1) make the min heap of the given array
// 2) extract the two minimum from the heap
// 3) let temp=min1+min2 and then and this temp to final result "cost"
// 4) now insert this temp to heap again.
// 5) keep doing this until the size of heap becomes 1.
// 6) finally return the cost.

int func(int arr[],int n)
{
	// making the array for heap
	int *harr=new int[n];

	//copying the given array to heap
	for(int i=0;i<n;i++)
		harr[i]=arr[i];

	// making min heap
	for(int i=(n/2-1);i>=0;i--)
	{
		minHeapify(harr,n,i);
	}


	int size=n;		// initializing the size, it keeps track of extract and this while loop.
	int cost=0;		// it will store the final answer.

	while(size!=1)
	{
		// find the two minimum element
		int min1=extractHeap(harr,size);
		int min2=extractHeap(harr,size);

		// add them to final answer.
		cost+=(min1+min2);

		// now again push their sum to heap
		insertHeap(harr,min1+min2,size);
	}

	return cost;
}
int main()
{
	int arr[]={3,2,6,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"the minimum cost is :: "<< func(arr,n);
}
