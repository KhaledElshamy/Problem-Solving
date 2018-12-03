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

void inorder(struct node*root)
    {
        if(root)
        {
            inorder(root->left);
            cout<<root->key<<" ";
            inorder(root->right);
        }
    }

void preorder(struct node *root)
    {
        if(root!= NULL)
        {
            cout<<root->key<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

void postorder(struct node*root)
    {
        if(root)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->key<<" ";
        }
    }

/*struct node * find(struct node *rootnode, int key){

    if(rootnode!=NULL){

        if(rootnode->key == key)
            return rootnode;
        else if(rootnode->key > key)
            return find(rootnode->left, key);
        else
            return find(rootnode->right, key);

    }
    else
        return NULL;
}

int maxDepth(struct node* node){

	if(node == NULL)return 0;
	else {
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);

		if(leftDepth>rightDepth)return(1+leftDepth);
		else return (1+rightDepth);
	}
}*/

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
    int n,N;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
    	for(int j=0;j<3;j++){
    		cin>>N;
    		if(N!=-1)a.push_back(N);
    	}
    }

    struct node *root=NULL;
	root = insert(root, a[0]);
	for(int i=1;i<(int)a.size();i++)insert(root,a[i]);

	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);

;	return 0;
}

