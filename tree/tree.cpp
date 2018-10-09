#include<iostream>
#include<stack>
using namespace std;
struct bst
{
  int val;
  struct bst*left;
  struct bst*right;

};
struct bst* root=NULL;
struct bst* check=NULL;

void create()
{
  int num;
  cout<<"Enter number\n";
  cin>>num;
  while(num>=0)
  {
    struct bst* new_node;
    new_node =new bst;
    new_node->val=num;
    new_node->right=NULL;
    new_node->left=NULL;

    if(root==NULL)
    {
      root=new_node;
    }
    else
    {

      struct bst* check;
      check=root;
      while(1)
      {

        if(check->val<num)
        {
          if(check->right==NULL)
          {
            check->right=new_node;
            cout<<"parent node is\n"<<check->val<<endl;
            break;
          }
          else
          {
            check=check->right;
          }
        }
        else
        {
          if(check->left==NULL)
          {
            check->left=new_node;
            cout<<"parent node is\n"<<check->val<<endl;
            break;
          }
          else
          {
            check=check->left;
          }
        }
      }
    }
    cout<<"enter number\n";
    cin>>num;
  }
}
void printPreorder(struct bst* node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void inord(struct bst* node)
{
  struct bst* ptr;
  stack<bst*> st;
  ptr=root;
  do
  {
    if(ptr)
      {
        st.push(ptr);
        ptr=ptr->left;
      }
    else
    {
      ptr=st.top();
      st.pop();
      cout<<ptr->val<<" ";
      ptr=ptr->right;
    }
  } while(!st.empty()||ptr!=NULL);

}
void preo(struct  bst* node)
{
  stack<bst*> st;
  struct bst * pt;
  st.push(root);
  int c=0;
  while(!st.empty())
  {
    pt=st.top();
    st.pop();
    cout<<pt->val<<" ";
    if(pt->right!=NULL)
        st.push(pt->right);
    if(pt->left!=NULL)
        st.push(pt->left);
    if(pt->left == NULL && pt->right == NULL)
      c++;
  }
  cout<<"\nNo of leaf nodes are : "<<c;
}
void postorder(struct bst* node)
{
  if(node == NULL)
      return;
  postorder(node->left);
  postorder(node->right);
  cout<<node->val<<" ";
}
void inorder(struct bst* node)
{
  if(node == NULL)
    return;
  inorder(node->left);
  cout<<node->val<<" ";
  inorder(node->right);
}

void del_singlechild(bst* par,bst* ptr)
{
  if(par->val>ptr->val)
  {
    if(ptr->left!= NULL)
      par->left = ptr->left;
    else
      par->left = ptr->right;
  }
  else
  {
    if(ptr->left!= NULL)
      par->right = ptr->left;
    else
      par->right = ptr->right;
  }
}
void del_leafnode(bst* par,bst* ptr)
  {
    if(par->val > ptr-> val)
      {
        par->left = NULL;
      }
    else
      {
        par->right = NULL;
      }
    delete ptr;
  }
  int del_twochild(bst* test)
  {
    bst* save=NULL;
    int x;
    while(test->left!=NULL)
    {
      save=test;
      test = test->left;
    }
    x=test->val;
    if(test->left == NULL && test->right == NULL)
        del_leafnode(save,test);
    else
      del_singlechild(save,test);

    return x;

  }
void del(struct bst* node,int n)
{
 struct bst* ptr;
 struct bst* save = NULL;
ptr=root;
int num=n;
while(1)
{
  if(ptr->val==num)
  {
    if(ptr->left == NULL && ptr->right == NULL)
      {
        del_leafnode(save,ptr);
        break;
      }
      else if(ptr->right!=NULL && ptr->left!= NULL)
        {
          int value = del_twochild(ptr->right);
          ptr->val = value;
        }
    else if(ptr->left != NULL || ptr->right !=NULL)
      {
        del_singlechild(save,ptr);
        break;
      }
  }


  else if(ptr->val<num && ptr->right!=NULL)
  {
    save=ptr;
    ptr=ptr->right;
  }
  else if(ptr->val>num && ptr->left!=NULL)
  {
    save=ptr;
    ptr=ptr->left;
  }
  else
  {
    cout<<"Element does not exist in tree \n";
    break;
  }
}

}

void search()
{
  int num;
  cout<<"Enter the element to be searched\n";
  cin>>num;
  struct bst* save=NULL;
  check=root;
  while(1)
  {
    if(check->val==num)
    {
      cout<<"Number found!\n";
      if(save==NULL)
      cout<<"Element is at root node\n";
      else
      cout<<"Parent node is: "<<save->val;
      break;
    }
    else if(check->val<num && check->right!=NULL)
    {
      save=check;
      check=check->right;
    }
    else if(check->val>num && check->left!=NULL)
    {
      save=check;
      check=check->left;
    }
    else
    {
      cout<<"Element does not exist in tree \n";
      break;
    }
  }
}

void min()
{
  check=root;
  while(check->left!=NULL)
    check=check->left;
  cout<<"Minimum element is "<<check->val<<endl;
}
void max()
{
  check=root;
  while(check->right!=NULL)
  {
    check=check->right;

  }
  cout<<"Maximum element is: "<<check->val<<endl;
}

int main()
{
  create();
  while(1)
  {
    int h;
    cout<<"Do tyou want to search element?\n1. Yes\n2.No";
    cin>>h;
    if(h==1)
    {
      search();
    }
    else
    break;
  }
  min();
  max();
  cout<<"Which order do youn want to display? \n 1. Postorder\n 2. Preorder\n 3. Inorder\n";
  int m;
  cin>>m;
  if(m==1)
  postorder(root);
  else if(m==2)
  printPreorder(root);
  else
  inorder(root);

  cout<<"Pre Order Stack Qithout REcursion is:-\n";
  preo(root);
  cout<<"\n Inorder Without REcursion:-\n";
  inord(root);
  cout<<"\nEnter root element to be deletd\n";
  int e;
  cin>>e;
  del(root,e);
  preo(root);
  return 0;
}
