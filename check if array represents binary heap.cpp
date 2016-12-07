// PROBLEM :: CHECK IF GIVEN ARRAY REPRESENT BINARY HEAP

#include<bits/stdc++.h>
using namespace std;

bool isHeap(int arr[],int n)
{
	bool flag=1;
	for(int i=(n/2-1);i>=0;i--)
	{
		int l=2*i+1;
		int r=2*i+2;

		if(l<n && arr[l]>arr[i])
			flag=0;
		if(r<n && arr[r]>arr[i])
			flag=0;
	}
	return flag;
}
int main()
{

		int arr[] = {90, 15, 10, 7, 12, 100, 7, 3};
	    int n = sizeof(arr) / sizeof(int);

	    isHeap(arr, n)? printf("Yes"): printf("No");


}
