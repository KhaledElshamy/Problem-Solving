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

// MARK -- find path for from root to the key 

bool findpath(struct node* node , vector<struct node* > &path , int key){

	if(node == NULL)return false;

	path.push_back(node);
	if(node->key == key)return true;

	if(findpath(node->left,path,key)|| findpath(node->right,path,key))return true;

	path.pop_back();
	return false;
}

// MARK -- find the largest node on the path that connects x & y 

int findLCA(struct node *node , int x ,int y,int maximum){
	int i,j;

	vector<struct node*> path1,path2;

	findpath(node,path1,x);
	findpath(node,path2,y);
	
	int ancestorNode , index ; 
	int minimumSize = min(path1.size() , path2.size());
	
	for(i= minimumSize - 1 ; i>=0 ; i--){
	    if(path1[i]->key == path2[i]->key){
	        ancestorNode = path1[i]->key;
	        index = i ;
	        break;
	    }
	}
	
	for(i= index ; i< minimumSize ; i++){
	    maximum = max(maximum , max(path1[i]->key , path2[i]->key));
	}
	
	if(i<path1.size()){
	     while(i<path1.size()){
	        maximum = max(maximum , path1[i]->key);
	        i++;
	    }
	}
	
	if(i<path2.size()){
	    while(i<path2.size()){
	        maximum = max(maximum , path2[i]->key);
	        i++;
	    }
	}
	
	return maximum ; 
}


// MARK -- insert nodes in tree 

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

	int LCA = findLCA(root,x,y,maximum); // lowest common ansector
	cout<<LCA<<endl;
	return 0;
}

