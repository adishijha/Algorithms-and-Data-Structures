#include<iostream>
using namespace std;
struct node
{
  node *left, *right;
  int key;
};
node *
newnode (int val)
{
  node *temp = new node ();
  if (temp == NULL)
    {
      cout << "out of memory\n";
      return NULL;
    }
  temp->left = NULL;
  temp->right = NULL;
  temp->key = val;
  return temp;
}


node *
insert (node * root, int val)
{
  if (root == NULL)
    {
      return newnode (val);
    }
  if (val <= root->key)
    {
      root->left = insert (root->left, val);
    }
  else if (root->key < val)
    {
      root->right = insert (root->right, val);
    }
  return root;
}


node *
deleten (node * root, int key)
{
  if (root == NULL)
    {
      cout << "There is no node to delete\n";
      return NULL;
    }
  else if (key < root->key)
    {
      root->left = deleten (root->left, key);
    }
  else if (key > root->key)
    {
      root->right = deleten (root->right, key);
    }
  else
    {
      if (root->left == NULL)
	{
	  node *temp = root->right;
	  delete root;
	  return temp;
	}
      else if (root->right == NULL)
	{
	  node *temp = root->left;
	  delete root;
	  return temp;
	}
      else
	{
	  node *succparent = root->right;
	  node *succ = root->right;
	  while (succ->left != NULL)
	    {
	      succparent = succ;
	      succ = succ->left;
	    }
	  succparent->left = succ->right;
	  root->key = succ->key;
	  delete succ;
	  return root;
	}
    }
}


void
inorder (node * root)
{
  if (root == NULL)
    return;

  inorder (root->left);
  printf ("%d ", root->key);
  inorder (root->right);
}

void
preorder (node * root)
{
  if (root == NULL)
    return;
  printf ("%d ", root->key);
  preorder (root->left);
  preorder (root->right);
}

void
postorder (node * root)
{
  if (root == NULL)
    return;
  postorder (root->left);
  postorder (root->right);
  printf ("%d ", root->key);
}

void
desc (node * root)
{
  if (root == NULL)
    return;
  desc (root->right);
  printf ("%d ", root->key);
  desc (root->left);
}

int
main ()
{
  node *root = NULL;
  int ch;
  cout <<
    "Enter your choice\n1.INSERTION\n2.DELETION\n3.IN ORDER\n4.PRE ORDER\n5.POST ORDER\n6.ASC\n7.DESC\n8.EXIT\n";
  while (1)
    {
      cin >> ch;
      switch (ch)
	{
	case 1:
	  int val;
	  cout << "Enter the value to be inserted\n";
	  cin >> val;
	  root = insert (root, val);
	  cout << "inserted\n";
	  break;
	case 2:
	  int v;
	  cout << "Enter the value to be deleted\n";
	  cin >> v;
	  root = deleten (root, v);
	  cout << "Deleted\n";
	  break;
	case 3:
	  inorder (root);
	  cout << "\n";
	  break;
	case 4:
	  preorder (root);
	  cout << "\n";
	  break;
	case 5:
	  postorder (root);
	  cout << "\n";
	  break;
	case 6:
	  inorder (root);
	  cout << "\n";
	  break;
	case 7:
	  desc (root);
	  cout << "\n";
	  break;
	case 8:
	  exit (0);
	}
    }
  return 0;
}

