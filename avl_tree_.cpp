#include<bits/stdc++.h>
using namespace std;
class Data
{
public:
  int ele;
  Data *left;
  Data *right;
  int height;

    Data (int ele)
  {
    this->ele = ele;
    left = right = nullptr;
    height = 1;

  }
};
class avl
{
    public:
    int height1 (Data * root)
  {
    if (root == nullptr)
      {
	return 0;
      }
    return root->height;
    }
    Data *rightrotation (Data * root)
   {
    Data *x = root->left;
    Data *y = x->right;

    x->right = root;
    root->left = y;
    x->height = 1 + max (height1 (x->left), height1 (x->right));
    root->height = 1 + max (height1 (root->left), height1 (root->right));
    return x;

    }
    Data *leftrotation (Data * root)
    {
    Data *x = root->right;
    Data *y = x->left;

    x->left = root;
    root->right = y;
    x->height = 1 + max (height1 (x->left), height1 (x->right));
    root->height = 1 + max (height1 (root->left), height1 (root->right));
    return x;

  }

    Data *createavl(Data * root, int ele)
   {
    if (root == nullptr)
      {
	   Data* data= new Data (ele);
	   return data;
      }
    else if (ele < root->ele)
      {
	root->left = createavl (root->left, ele);
      }
    else if(ele >root->ele)
      {
	root->right =createavl(root->right, ele);
      }
      else{
          return root;
      }
    root->height = 1 + max (height1 (root->left), height1 (root->right)); 
    int bst;
    if(root==nullptr){
        bst=0;
    }
    else{
        bst =height1 (root->left) - height1 (root->right);
    }
    
    if (bst > 1 && ele < root->left->ele)
      {
	return rightrotation (root);
      }
    if (bst > 1 && ele > root->left->ele)
      {
	root->left = leftrotation (root->left);
	return rightrotation (root);
      }
    if (bst < 0 && ele > root->right->ele)
      {
	return leftrotation (root);
      }
    if (bst < 0 && ele < root->right->ele)
      {
	root->right = rightrotation (root->right);
	return leftrotation (root);
      }

    return root;

   }
    void preorder (Data * root)
    {
    if (root == nullptr)
      {	return;
      }
    cout << root->ele << " ";
    preorder (root->left);
    preorder (root->right);
    }
    void inorder (Data * root)
    {
    if (root == nullptr)
      {
	return;
      }
    inorder (root->left);
    cout << root->ele << " ";
    inorder (root->right);
    }
    void postorder (Data * root)
    {
    if (root == nullptr)
      {
	return;
      }
    postorder (root->left);
    postorder (root->right);
    cout << root->ele << " ";
    }




};

int main ()
{
  Data *root = nullptr;
  avl a;
  int n;
 // cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
 cin>>arr[i];
  root = a.createavl(root, arr[i]);
// root = a.createavl (root, 3);
 // root =a.createavl(root, 0);
 // root =a. createavl(root, 1);
 //root= a.createavl(root,9);
 }
  a.preorder (root);
  return 0;
}
