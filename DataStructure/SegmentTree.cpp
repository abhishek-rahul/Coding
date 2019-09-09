#include<bits/stdc++.h>
using namespace std;
int arr[100050];
int tree[250000];
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
void update(int node,int start,int end,int idx,int val)
{
	if(start==end)
	{
		arr[idx]=val;
		tree[node]=val;
	}
	else
	{
		int mid = (start+end)/2;
		if(start <= idx && idx <= mid)
		update(2*node,start,mid,idx,val);
		else
		update(2*node+1,mid+1,end,idx,val);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}
int query(int node,int start,int end,int l,int r)
{
	if(start>r || end<l)
	return maxi;
	if(start>=l && end<=r)
	return tree[node];
	int mid = (start+end)/2;
	int p1 = query(2*node,start,mid,l,r);
	int p2 = query(2*node+1,mid+1,end,l,r);
	return min(p1,p2);
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
