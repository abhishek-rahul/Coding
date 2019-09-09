#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int visited[100][100];
int horizontal[100][100];
int vertical[100][100];
int maxi = 1000000;
struct node
{
	int x;
	int y;
};
void init()
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
		//	visited[i][j]=0;
			arr[i][j]=maxi;
			horizontal[0][0]=0;
			vertical[0][0]=0;
		}
	}
}
void bfs(int n,int m)// x==i y==j
{
int tempx,tempy;
queue<node> q;
node temp,key;
temp.x=0;
temp.y=0;
q.push(temp);
arr[0][0]=1;
while(!q.empty())
{
	temp = q.front();
	q.pop();
    	
	//case1  " > "
	tempx = temp.x;
	tempy = temp.y+1;
	if(tempx>=0 && tempx<n && tempy>=0 && tempy<m)
	{
		if(vertical[tempx][tempy]==1)
		{
			if(arr[temp.x][temp.y]+1<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y]+1;
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
		else if(vertical[tempx][tempy]==0)
		{
			if(arr[temp.x][temp.y]<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y];
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
	}
	
	//case2  " < "
	tempx = temp.x;
	tempy = temp.y-1;
	if(tempx>=0 && tempx<n && tempy>=0 && tempy<m)
	{
		if(vertical[temp.x][temp.y]==1)
		{
			if(arr[temp.x][temp.y]+1<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y]+1;
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
		else if(vertical[temp.x][temp.y]==0)
		{
			if(arr[temp.x][temp.y]<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y];
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
	}
	
	//case3  " down "
	tempx = temp.x+1;
	tempy = temp.y;
	if(tempx>=0 && tempx<n && tempy>=0 && tempy<m)
	{
		if(horizontal[tempx][tempy]==1)
		{
			if(arr[temp.x][temp.y]+1<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y]+1;
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
		else if(horizontal[tempx][tempy]==0)
		{
			if(arr[temp.x][temp.y]<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y];
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
	}
	
	//case4  " ^ "
	tempx = temp.x-1;
	tempy = temp.y;
	if(tempx>=0 && tempx<n && tempy>=0 && tempy<m)
	{
		if(horizontal[temp.x][temp.y]==1)
		{
			if(arr[temp.x][temp.y]+1<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y]+1;
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
		else if(horizontal[temp.x][temp.y]==0)
		{
			if(arr[temp.x][temp.y]<arr[tempx][tempy])
			{
				arr[tempx][tempy]=arr[temp.x][temp.y];
				key.x = tempx;
				key.y = tempy;
				q.push(key);
			}
		}
	}
}	
}
int main()
{
	int n,m;
	int tc;
	cin>>tc;
	while(tc--)
	{
    init();
    cin>>n>>m;
    int num,x1,y1,x2,y2;//type 1 for horizontal and 0 for vertical  x=i y=j
    cin>>num;
    for(int i=0;i<num;i++)
    {
    cin>>x1>>y1>>x2>>y2;
	if(y1==y2)//case of horizontal
	{
		for(int j=min(x1,x2);j<max(x1,x2);j++)
		horizontal[y1][j]=1;
	}
	else //case of vertical
	{
		for(int j=min(y1,y2);j<max(y1,y2);j++)
		vertical[j][x1]=1;
	}
	
	}
	bfs(n,m);
	cout<<"horizontal array is "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		cout<<horizontal[i][j]<<" ";
	    }
		cout<<endl;
	}
    cout<<"vertical array is "<<endl;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		cout<<vertical[i][j]<<" ";
	    }
		cout<<endl;
	}
	cout<<"resultant array is "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		cout<<arr[i][j]<<" ";
	    }
		cout<<endl;
	}
	}
	return 0;
}
/*
5
6 6
4
2 2 5 2
5 2 5 4
5 4 2 4
2 4 2 2

1
6 6 
12
1 1 3 1
3 1 3 3
3 3 4 3
3 3 3 4
4 3 5 3
4 3 4 4
4 4 3 4
5 3 5 5
5 5 3 5
3 5 3 4
3 5 1 5
1 5 1 1
*/

