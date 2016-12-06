#include<bits/stdc++.h>
using namespace std;
class minHeap
{
	int *harr;
	int capacity;
	int hSize;

public:

	minHeap(int);

	int parent(int n){return (n-1)/2;}
	int lchild(int n){return 2*n+1;}
	int rchild(int n){return 2*n+2;}

	void insert(int k);

	int extractMin();

	void decrease(int i,int val);

	void deleteval(int val);

	void heapify(int);

	int getMin(){return harr[0];}

	void disp()
	{
		for(int i=0;i<hSize;i++)
			cout<<harr[i]<<" ";
	}
};

void minHeap::heapify(int i)
{
	int l=lchild(i);
	int r=rchild(i);
	int smallest=i;

	if(l<hSize && (harr[parent(i)]>harr[l]))
		smallest=l;
	if(r<hSize && (harr[smallest]>harr[r]))
		smallest=r;

	if(smallest!=i)
	{
		swap(harr[i],harr[smallest]);
		heapify(smallest);
	}
}

minHeap::minHeap(int cap)
{
	harr=new int [cap];
	capacity=cap;
	hSize=0;
}

void minHeap::insert(int k)
{
	if(hSize>=capacity)
	{
		cout<<"overflow\n";
		return;
	}

	hSize++;
	int i=hSize-1;
	harr[i]=k;

	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(harr[parent(i)],harr[i]);
		i=parent(i);
	}
}

void minHeap::decrease(int i,int val)
{
	harr[i]=val;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(harr[parent(i)],harr[i]);
		i=parent(i);
	}
}


int minHeap::extractMin()
{
	if(hSize<=0)
	{
		return INT_MAX;
	}
	if(hSize==1)
	{
		hSize--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[hSize-1];
	hSize--;

	heapify(0);

	return root;

}

void minHeap::deleteval(int i)
{
	decrease(i,INT_MIN);
	extractMin();
}
int main()
{
	// creating the heap using constructor
	minHeap h(5);

	// inserting value into the heap
	h.insert(3);
	h.insert(2);
	h.insert(1);
	h.insert(4);
	h.insert(5);

	cout<<"insertion :: \n";
	h.disp();cout<<"\n\n";

	cout<<"extract minimum :: \n";
	cout<<h.extractMin()<<" :: \n";
	h.disp();cout<<"\n\n";

	cout<<"decreasing value of 4 to 1 :: \n";
	h.decrease(3,1);
	h.disp();cout<<"\n\n";

	cout<<"deleting 5 :: \n";
	h.deleteval(2);
	h.disp();cout<<"\n\n";

	cout<<"getting minimum :: \n";
	cout<<h.getMin();
}
