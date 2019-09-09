#include<iostream>

using namespace std;

void swap(int* a,int* b)
{
        int temp=*a;
        *a=*b;
        *b=temp;
}

void insert_max_heap(int max_heap[],int value , int size_of_max_heap)
{
	max_heap[size_of_max_heap]=value;
	int i = size_of_max_heap;
	int parent ;
	while(i!=0)
	{
		parent=(i-1)/2;
		if(max_heap[i]>max_heap[parent])
			swap(&max_heap[i],&max_heap[parent]);
		i=parent;
	}
}

void insert_min_heap(int min_heap[],int value, int size_of_min_heap)
{
	min_heap[size_of_min_heap]=value;
	int i = size_of_min_heap;
	int parent ;
	while(i!=0)
	{
		parent=(i-1)/2;
		if(min_heap[i]<min_heap[parent])
			swap(&min_heap[i],&min_heap[parent]);
		i=parent;
	}
}

void max_heapify(int max_heap[],int i,int size)
{
	    int largest=i;
        int left=2*i+1;
        int right=2*i+2;
		if(largest>=size)
                return;
        if(left<size && max_heap[left]>max_heap[largest])
                largest=left;
        if(right<size && max_heap[right]>max_heap[largest])
                largest=right;
        if(largest!=i){
                swap(&max_heap[i],&max_heap[largest]);
                max_heapify(max_heap,largest,size);
        }
}

int delete_max_heap(int max_heap[],int size_of_max_heap)
{
	int top = max_heap[0];
	max_heap[0]=max_heap[size_of_max_heap-1];
	max_heapify(max_heap,0,size_of_max_heap-1);
	return top;
}

void min_heapify(int min_heap[],int i,int size)
{
	    int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
		if(smallest>=size)
                return;
        if(left<size && min_heap[left]<min_heap[smallest])
                smallest=left;
        if(right<size && min_heap[right]<min_heap[smallest])
                smallest=right;
        if(smallest!=i){
                swap(&min_heap[i],&min_heap[smallest]);
                min_heapify(min_heap,smallest,size);
        }
}
int delete_min_heap(int min_heap[],int size_of_min_heap)
{
	int top = min_heap[0];
	min_heap[0]=min_heap[size_of_min_heap-1];
	min_heapify(min_heap,0,size_of_min_heap-1);
	return top;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int min_heap[100005],max_heap[100005];
		int size_of_min_heap=0,size_of_max_heap=0;
		float median=100005;
		int num,value;
		scanf("%d",&num);
		for(int i=1;i<=num;i++)
		{
			scanf("%d",&value);
			if(value <= median)
			{
				if(size_of_max_heap<=size_of_min_heap)
				{
					insert_max_heap(max_heap,value,size_of_max_heap);
					size_of_max_heap++;
				}
				else
				{
					int top=delete_max_heap(max_heap,size_of_max_heap);
					size_of_max_heap--;
					insert_min_heap(min_heap,top,size_of_min_heap);
					size_of_min_heap++;
					insert_max_heap(max_heap,value,size_of_max_heap);
					size_of_max_heap++;
				}
			}
			else if(value>median)
			{
			if(size_of_min_heap<=size_of_max_heap)
				{
					insert_min_heap(min_heap,value,size_of_min_heap);
					size_of_min_heap++;
				}	
			else
				{
					int top=delete_min_heap(min_heap,size_of_min_heap);
					size_of_min_heap--;
					insert_max_heap(max_heap,top,size_of_max_heap);
					size_of_max_heap++;
					insert_min_heap(min_heap,value,size_of_min_heap);
					size_of_min_heap++;
				}
			}
			if(size_of_min_heap==size_of_max_heap)
			{
				float a,b;
				a=min_heap[0];
				b=max_heap[0];
				median=(a+b)/2.0;
			}
			else if(size_of_min_heap>size_of_max_heap)
				median=min_heap[0];
			else
				median=max_heap[0];
			printf("%0.1f\n",median);
		}



	}
	return 0;
}