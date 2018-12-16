#include<iostream>
#include<vector>
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

int getMaxDepth(struct node *node){

	if(node == NULL)return 0;
	int leftMax = getMaxDepth(node->left);
	int rightMax = getMaxDepth(node->right);

	if(leftMax >= rightMax)return leftMax+1;
	else return rightMax+1;
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
    int t,n;
    cin>>t;
    struct node *root=NULL;
    while(t--){
    	node *root = NULL;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)cin>>a[i];
    	root = insert(root, a[0]);
    	for(int i=1;i<n;i++)insert(root,a[i]);
    	int depth = getMaxDepth(root);
    	cout<<depth<<endl;
    }
	return 0;
}

