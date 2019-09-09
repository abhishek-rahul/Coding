#include<bits/stdc++.h>
using namespace std;
int arr[100050];
int tree[250000];
int lazy[250000];
int maxi = 100005;
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=arr[start];
	}
	else
	{
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        tree[node] += (end - start + 1) * lazy[node];    
        if(start != end)
        {
            lazy[node*2] += lazy[node];                 
            lazy[node*2+1] += lazy[node];           
        }
        lazy[node] = 0;                                 
    }
    if(start > end || start > r || end < l)    
        return;
    if(start >= l && end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        
    updateRange(node*2 + 1, mid + 1, end, l, r, val);  
    tree[node] = tree[node*2] + tree[node*2+1];      
}
int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
        return 0;       
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];           
        if(start != end)
        {
            lazy[node*2] += lazy[node];         
            lazy[node*2+1] += lazy[node];   
        }
        lazy[node] = 0;                 
    }
    if(start >= l && end <= r)             
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);        
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 
    return (p1 + p2);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	build(1,1,n);
	char ch;
	int l,r;
	for(int i=1;i<=m;i++)
	{
		cin>>ch>>l>>r;
		if(ch == 'q')
		cout<<query(1,1,n,l,r)<<endl;
		else if(ch == 'u')
		update(1,1,n,l,r);         //A[l]= r
	}
	return 0;
}
