#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node
{
	int key;
	node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


bool findpath(struct node* node , vector<struct node* > &path , int key){

	if(node == NULL)return false;

	path.push_back(node);
	if(node->key == key)return true;

	if(findpath(node->left,path,key)|| findpath(node->right,path,key))return true;

	path.pop_back();
	return false;
}

int findLCA(struct node *node , int x ,int y,int maximum){
	int i,j;

	vector<struct node*> path1,path2;

	findpath(node,path1,x);
	findpath(node,path2,y);

	for(i=0 ; i<(int)path1.size()&&i<(int)path2.size();i++)
		if(path1[i]->key!=path2[i]->key){
			for(j=i;j<(int)path1.size()&&j<(int)path2.size();j++) maximum =max(maximum,max(path1[j]->key,path2[j]->key));
			break;
		}

	if(j<(int)path1.size()){
		while(j<path1.size()){
			maximum = max(maximum,path1[i]->key);
			j++;
		}
	}
	if(j<(int)path2.size()){
		while(j<path2.size()){
			maximum = max(maximum,path2[i]->key);
			j++;
		}
	}
	maximum = max(maximum,path1[i-1]->key);
	return maximum;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key <= node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
    int n,x,y,maximum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>x>>y;

    struct node *root=NULL;
	root = insert(root, a[0]);
	for(int i=1;i<n;i++)insert(root,a[i]);

	int LCA = findLCA(root,x,y,maximum); // lowest common ancestor
	cout<<LCA<<endl;
	return 0;
}
