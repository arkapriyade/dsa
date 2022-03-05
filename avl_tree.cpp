
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
    int getbsf(Data * root){
        if(root==nullptr){
            return 0;
        }
        else{
            return height1 (root->left) - height1 (root->right);
        }
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
    int bst=getbsf(root);
    //ll rotation
    if (bst > 1 && ele < root->left->ele)
      {
	return rightrotation (root);
      }
      //lr rotation
    if (bst > 1 && ele > root->left->ele)
      {
	root->left = leftrotation (root->left);
	return rightrotation (root);
      }
       //rr rotation
    if (bst < -1&& ele > root->right->ele)
      {
	return leftrotation (root);
      }
       //rl rotation
    if (bst < -1 && ele < root->right->ele)
      {
	root->right = rightrotation (root->right);
	return leftrotation (root);
      }

    return root;

   }
    Data *inordersucc( Data * root){
        Data* curr=root;
        if(curr && curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }
    Data *deleteavl(Data * root, int ele){
    if(root==nullptr){
        cout<<"no element to delete";
         return root;
     }
    else if(ele<root->ele){
      root->left=deleteavl(root->left,ele);
     }
    else if(ele>root->ele){
    root->right =deleteavl(root->right, ele);
    }    ///if matches element
    else{
        /// no child
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        ///one child
        else if(root->left==nullptr){
            Data* curr=root->right;
            delete root;
            return curr;
        }
         else if(root->right==nullptr){
            Data* curr=root->left;
            delete root;
            return curr;
        }
        else{//two children
         Data* curr=inordersucc(root->right);
         root->ele=curr->ele;
         root->right=deleteavl(root->right, curr->ele);
        }
    } //r rotation
    //r rotation if bst of b is 0 or 1 then ll rotation and -1 lr rotation b is descendent of 
         //opposite side of deleted node 
        if(getbsf(root)>=2 && getbsf(root->left)>=0){
             return rightrotation(root);
         }
        if(getbsf(root)>=2 && getbsf(root->left)==-1){
            root->left=leftrotation(root->left);
            return rightrotation(root);
         }
         //l rotation if bst of b is 0 or -1 then rr rotation and -1 rl rotation b is descendent of 
         //opposite side of deleted node 
        if(getbsf(root)<-1 && getbsf(root->right)<=0){
            return leftrotation(root);
        }
        if(getbsf(root)<-1 && getbsf(root->right)==1){
         root->right=rightrotation(root->right);
         return leftrotation(root);
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
 // for(int i=0;i<n;i++){
 //cin>>arr[i];
  //root = a.createavl(root, arr[i]);
 root = a.createavl (root, 50);
 root =a.createavl(root, 40);
 root =a. createavl(root, 30);
 root= a.createavl(root,20);
 root=a.deleteavl(root,50);
 //root=a.deleteavl(root,9);
// root=a.deleteavl(root,3);
// root=a.deleteavl(root,0);
 //root=a.deleteavl(root,1);
 //}
 a.preorder (root);
  return 0;
}
