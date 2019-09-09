#include<bits/stdc++.h>
using namespace std;
int sizeofmaxheap;
struct trie 
{
    struct trie * child[26];
    int cnt;
};
struct heapnode
{
    char ch[20];
};
int strl(char *str)
{
	int cnt=0;
	while(str[cnt]!='\0')
	cnt++;
	return cnt;
}

struct trie* addnode()
{
struct trie * node = new trie;
for(int i=0;i<26;i++)
{
	node->child[i]=NULL;
}	
	node->cnt=0;
	return node;
}

void insert(struct trie* root,char *str)
{
	int len = strl(str);
	int index;
    struct trie* node = root;
	for(int i=0;i<len;i++)
	{
		index = str[i]-'a';
		if(!node->child[index])
		node->child[index]=addnode();
		node=node->child[index];
	}		
	node->cnt = node->cnt+1;
}

bool isLeafNode(struct trie* root) 
{ 
    return root->cnt != 0; 
} 

void makemaxheap(struct trie* root, char *str, int level,heapnode node)
{
	if (isLeafNode(root))  
    { 
     insertnode(node,str);
    } 
  
    int i; 
    for (i = 0; i < 26; i++)  
    { 
        if (root->child[i])  
        { 
            str[level] = i + 'a'; 
            display(root->child[i], str, level + 1); 
        } 
    } 
}
struct trie* getNode(struct trie* root,char *str)
{
	struct trie* node = root;
	int len = strl(str);
	int index;
	for(int i=0;i<len;i++)
	{
	    index = str[i]-'a';
		node=node->child[index];	
	}
	return node;
}
int main()
{
	char ch[20],str[20];
	int tc,n,m;
	cin>>tc;
	while(tc--)
	{
	cin>>n;
	struct trie * root = addnode();
	for(int i=0;i<n;i++)
	{
	cin>>ch;
	insert(root,ch);
	}
	cin>>m;
	struct trie * point; 
    for(int i=0;i<m;i++)
    {
    	sizeofmaxheap=0;
    	heapnode arr[25];
    	cin>>ch;
    	point = getNode(root,ch);
    	for(int i=0;i<20;i++)
    	str[i]='\0';
    	makemaxheap(point,str,0,arr);
	}
	//display(root,ch,0);
    }
return 0;
}
