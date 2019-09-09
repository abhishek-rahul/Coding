#include <iostream>

using namespace std;
struct trie 
{
    struct trie * child[26];
    bool isEnd;
};
int lengt(char *str)
{
    int i=0;
    while(str[i]!='\0')
    i++;
    return i;
}

void addnode()
{
    struct trie* node = new trie;
    for(int i=0;i<26;i++)
    {
        node->child[i]=NULL;//if compiler will not take null then 
                            //define above #define null 0
    }
    node->isEnd = false;
    return node;
}

void insertnode(struct trie* root,char *str)
{
    struct trie* node  = root;
    int len = lengt(str);
    int index;
    for(int i=0;i<len;i++)
    {
        index = str[i]-'a';
        if(!node->child[index])
        node->child[index]=addnode();
        node=node->child[index];
    }
    node->isEnd =true;
}

bool search(struct trie* root,char *str)
{
    struct trie* node = root;
    int len = lengt(str);
    int index;
    for(int i=0;i<len;i++)
    {
        index = str[i]-'a';
        if(!node->child[index])
        return false;
        node=node->child[index];
    }
    if(node->isEnd)
    return true;
    return false;
}

bool isempty(struct trie* node)
{
    for(int i=0;i<26;i++)
    if(node->child[i])
    return false;
    return true;
}
struct trie* remov(struct trie* root,char * str,int depth,int len)
{
    if(!root)
    return NULL;
    
    if(depth == len)
    {
        if(root->isEnd)
        root->isEnd = false;
        
        if(isempty(root))
        {
            delete(root);
            root=NULL;
        }
        return root;
    }
    
    int index = str[depth]-'a';
    root->child[index]=remov(root->child[index],str,depth+1,len);
    
    if(isempty(root) && root->isEnd==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}

bool isLeafNode(struct trie* root) 
{ 
    return root->isEnd != false; 
} 
  
void display(struct trie* root, char *str, int level) 
{ 
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        cout << str << endl; 
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

int main()
{
   int tc;
   cin>>tc;
   while(tc--)
   {
       char str[20];
       int num;
       cin>>num;
       struct trie* root = addnode();
       for(int i=0;i<num;i++)
       {
           for(int j=0;j<20;j++)
           str[j]='\0';
           scanf("%s",&str);
           insertnode(root,str);
       }
        for(int j=0;j<20;j++)
           str[j]='\0';
        scanf("%s",&str);
        if(search(root,str))
        cout<<"word found"<<endl;
        else
        cout<<"word not found"<<endl;
        for(int j=0;j<20;j++)
           str[j]='\0';
        scanf("%s",&str);
        int len = lengt(str);
        root = remov(root,str,0,len);
   }
   
   return 0;
}
