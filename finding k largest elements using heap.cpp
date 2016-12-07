// PROBLEM :: FINDING K LARGEST/SMALLEST NUMBER OF THE ARRAY

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

int extractMax(int arr[],int &n)
{
	if(n==0)
		return INT_MIN;
	if(n==1)
	{
		n--;
		return arr[0];
	}

	int root=arr[0];
	arr[0]=arr[n-1];
	n--;

	heapify(arr,n,0);
	return root;
}
void kmax(int arr[],int n,int k)
{
	// forming the max heap
	for(int i=n-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}

	// calling extract max k times
	int size=n;		// passing the size by reference
	for(int i=0;i<k;i++)
	{
		int ans=extractMax(arr,size);
		if(ans==INT_MIN)
		{
			cout<<"heap is empty\n";
		}
		else
			cout<<ans<<"\n";
	}
}
int main()
{
	int arr[5]={3,4,8,6,2};
	int n=5;
	kmax(arr,n,10);
}
