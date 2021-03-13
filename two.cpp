#include<bits/stdc++.h>
using namespace std;


struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}


int sum(Node* root,int &f)							//check if given tree is sumtree or not
    {		
        if(root==NULL)
        return 0;
        
        if(root->right==NULL && root->left==NULL)
        return root->data;
        
        if(f==0)
        return 0;
        
        int a=sum(root->left,f);
        int b=sum(root->right,f);
        
        int x=root->data;
        
        if(a+b!=x)
        f=0;
        
        return a+b+x;
    }
    
    bool isSumTree(Node* root)
    {
         int f=1;
         sum(root,f);
         return f;
    }


int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

    cout<<isSumTree(root);
}	