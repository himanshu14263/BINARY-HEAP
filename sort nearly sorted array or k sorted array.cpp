// PROBLEM :: SOLVING ALMOST SORTED ARRAY OR K SORTED ARRAY

#include<bits/stdc++.h>
using namespace std;



int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int parent(int i){return (i-1)/2;}


void heapify(int harr[],int size,int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;

	if(l<size && harr[i]>harr[l])
		smallest=l;
	if(r<size && harr[smallest]>harr[r])
		smallest=r;

	if(smallest!=i)
	{
		swap(harr[smallest],harr[i]);
		heapify(harr,size,smallest);
	}
}

// use to replace top most element of heap and the first element of remaining array
// if the replacement causes any changes in property of heap then we call heapify
int replace(int harr[],int x,int k)
{
	int root=harr[0];
	harr[0]=x;
	if(x>root)
		heapify(harr,k,0);
	return root;
}


// use to extract the minimum element of heap(i.e. root)
// it requires extra variable size ie the size of the heap and as we extract the elements the size decreases.

int extractMin(int harr[],int &size)
{
	if(size<=0)
	{
		return INT_MAX;
	}
	if(size==1)
	{
		size--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[size-1];
	size--;

	heapify(harr,size,0);
	return root;
}
void ksort(int arr[],int n,int k)
{
	// step 1 :: make a min-heap
	int harr[k+1];

	for(int i=0;i<=k;i++)
		harr[i]=arr[i];

	for(int i=n-1;i>=0;i--)
	{
		heapify(arr,k,i);
	}

	int size=k+1;	// THIS ONE CAUSED BLUNDER.
					// NOTE :: THERE ARE K+1 NODES IN HEAP.
	for(int ti=0,i=k+1;ti<n;i++,ti++)
	{
		if(i<n)
			arr[ti]=replace(harr,arr[i],k);
		else
			arr[ti]=extractMin(harr,size);
	}

	// step 2 :: now use replace or extract min and transfer the data into the ans array

}
int main()
{
	int arr[]={2,6,3,12,56,8};
	int n=6;
	int k=3;
	ksort(arr,n,k);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
