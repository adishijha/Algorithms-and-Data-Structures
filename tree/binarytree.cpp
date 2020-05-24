//Binary Tree
#include<iostream>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
struct node
{
  node *llink = NULL;
  node *rlink = NULL;
  int info;
};

node *
getnode (int val)//create a node
{
  node *temp = new node ();
  if (temp == NULL)
    {
      cout << "Out of Memory\n";
      return NULL;
    }
  temp->info = val;
  temp->llink = temp->rlink = NULL;
  return temp;
}


node *
insert (node * root, int val) 
{
  node *p;
  queue < node * >s1;
  if (root == NULL)
    {
      return getnode (val);
    }
  else
    {
      s1.push (root);
      while (!s1.empty ())
	{
	  p = s1.front ();
	  if (p->llink)
	    {
	      s1.push (p->llink);
	    }
	  else
	    {
	      p->llink = getnode (val);
	      break;
	    }
	  if (p->rlink)
	    {
	      s1.push (p->rlink);
	    }
	  else
	    {
	      p->rlink = getnode (val);
	      break;
	    }
	  s1.pop ();
	}
    }
  return root;
}

void
levelorder (node * root)
{
  node *z;
  queue < node * >s;
  s.push (root);
  while (!s.empty ())
    {
      z = s.front ();
      cout << z->info << " ";
      if (z->llink)
	{
	  s.push (z->llink);
	}
      if (z->rlink)
	{
	  s.push (z->rlink);
	}
      s.pop ();
    }
  cout << "\n";
}

void
inorder (node * root)
{
  if (root == NULL)
    return;
  inorder (root->llink);
  cout << root->info << " ";
  inorder (root->rlink);
}

void
preorder (node * root)
{
  if (root == NULL)
    return;
  cout << root->info << " ";
  preorder (root->llink);
  preorder (root->rlink);
}

void
postorder (node * root)
{
  if (root == NULL)
    return;
  postorder (root->llink);
  postorder (root->rlink);
  cout << root->info << " ";
}

void
spiral (node * root)
{
  node *p;
  if (root == NULL)
    return;
  stack < node * >q1;
  stack < node * >q2;
  q1.push (root);
  while (!q1.empty () || !q2.empty ())
    {
      while (!q1.empty ())
	{
	  p = q1.top ();
	  cout << p->info << " ";
	  if (p->rlink)
	    {
	      q2.push (p->rlink);
	    }
	  if (p->llink)
	    {
	      q2.push (p->llink);
	    }
	  q1.pop ();
	}
      while (!q2.empty ())
	{
	  p = q2.top ();
	  cout << p->info << " ";
	  if (p->llink)
	    {
	      q1.push (p->llink);
	    }
	  if (p->rlink)
	    {
	      q1.push (p->rlink);
	    }
	  q2.pop ();
	}
    }
}

void
zigzag (node * root)
{
  node *p;
  if (root == NULL)
    return;
  stack < node * >q1;
  stack < node * >q2;
  q1.push (root);
  while (!q1.empty () || !q2.empty ())
    {
      while (!q1.empty ())
	{
	  p = q1.top ();
	  cout << p->info << " ";
	  if (p->llink)
	    {
	      q2.push (p->llink);
	    }
	  if (p->rlink)
	    {
	      q2.push (p->rlink);
	    }
	  q1.pop ();
	}
      while (!q2.empty ())
	{
	  p = q2.top ();
	  cout << p->info << " ";
	  if (p->rlink)
	    {
	      q1.push (p->rlink);
	    }
	  if (p->llink)
	    {
	      q1.push (p->llink);
	    }
	  q2.pop ();
	}
    }
}

node *
del (node * root, int v) //find the node to be deleted and replace with the last node
{
  int flag = 0;
  node *p;
  node *t;
  node *tempnode = NULL;
  queue < node * >d;


  if (root == NULL)
    {
      cout << "Tree is empty\n";
      return root;
    }


  if (root->llink == NULL and root->rlink == NULL)
    {
      if (root->info == v)
	{
	  return NULL;
	}
      else
	{
	  cout << "Node not present\n";
	  return root;
	}
    }


  d.push (root);
  while (!d.empty ())
    {
      p = d.front ();
      if (p->info == v)
	{
	  flag = 1;
	  tempnode = p;
	}
      if (p->llink)
	{
	  d.push (p->llink);
	}
      if (p->rlink)
	{
	  d.push (p->rlink);
	}
      d.pop ();
    }

  if (flag == 0)
    {
      cout << "Node not present\n";
      return root;
    }
  int x = p->info;

  d.push (root);
  while (!d.empty ())
    {
      t = d.front ();
      if (t->llink)
	{
	  if (t->llink->info == x) //checking with value of last node and making it's parent node point to NULL
	    {
	      delete (t->llink);
	      t->llink = NULL;
	      break;
	    }
	  else
	    {
	      d.push (t->llink);
	    }
	}
      if (t->rlink)
	{
	  if (t->rlink->info == x)
	    {
	      delete (t->rlink);
	      t->rlink = NULL;
	      break;
	    }
	  else
	    {
	      d.push (t->rlink);
	    }
	}
      d.pop ();
    }
  tempnode->info = x;
  return root;
}


void
reverse (node * root) //reverse level order
{
  if (root == NULL)
    {
      cout << "tree is empty\n";
      return;
    }
  node *temp;
  queue < node * >q;
  stack < node * >s;
  q.push (root);
  while (!q.empty ())
    {
      temp = q.front ();
      q.pop ();
      s.push (temp);
      if (temp->rlink)
	{
	  q.push (temp->rlink);
	}
      if (temp->llink)
	{
	  q.push (temp->llink);
	}
    }
  while (!s.empty ())
    {
      temp = s.top ();
      cout << temp->info << " ";
      s.pop ();
    }
  cout << "\n";
}

bool
search (node * root, int val)
{
  if (root == NULL)
    {
      return false;
    }
  int x = root->info;
  if (x == val)
    {
      return true;
    }
  bool res = search (root->llink, val);
  if (res)
    return true;
  bool res2 = search (root->rlink, val);
  if (res2)
    return true;
}

void
mirror (node * root)
{
  if (root == NULL)
    {
      return;
    }
  node *temp;
  temp = root->llink;
  root->llink = root->rlink;
  root->rlink = temp;
  mirror (root->llink);
  mirror (root->rlink);
}

int
numbernodes (node * root) //full nodes
{
  if (root == NULL)
    {
      return 0;
    }
  int fn = 0;
  if (root->llink && root->rlink)
    {
      fn = fn + 1;
    }
  fn = fn + (numbernodes (root->llink) + numbernodes (root->rlink));
  return fn;
}

int
half (node * root) //half nodes
{
  if (root == NULL)
    {
      return 0;
    }
  int hn = 0;
  if ((root->llink == NULL && root->rlink)
      || (root->llink && root->rlink == NULL))
    {
      hn = hn + 1;
    }
  hn = hn + half (root->llink) + half (root->rlink);
  return hn;
}

int
leaf (node * root) //leaf nodes
{
  if (root == NULL)
    {
      return 0;
    }
  int ln = 0;
  if (root->llink == NULL && root->rlink == NULL)
    {
      ln = ln + 1;
    }
  ln = ln + (leaf (root->llink) + leaf (root->rlink));
  return ln;
}


int
recursiveheight (node * root)
{
  if (root == NULL)
    {
      return -1;
    }
  int lt = recursiveheight (root->llink);
  int rt = recursiveheight (root->rlink);
  if (lt > rt)
    {
      return (lt + 1);
    }
  else
    {
      return (rt + 1);
    }
}

int
recursivesize (node * root)
{
  if (root == NULL)
    {
      return 0;
    }
  int lt = recursivesize (root->llink);
  int rt = recursivesize (root->rlink);
  return (lt + rt + 1);
}

int
rsum (node * root) //sum of all nodes
{
  if (root == NULL)
    {
      return 0;
    }
  int lt = rsum (root->llink);
  int rt = rsum (root->rlink);
  return (lt + rt + root->info);
}

int
max (node * root)
{
  if (root == NULL)
    return 0;
  int res = root->info;
  int lt = max (root->llink);
  int rt = max (root->rlink);
  if (res < lt)
    {
      res = lt;
    }
  if (res < rt)
    {
      res = rt;
    }
  return res;
}

int
deep (node * root) //deepest node
{
  if (root == NULL)
    {
      return 0;
    }
  queue < node * >q;
  node *temp;
  q.push (root);
  while (!q.empty ())
    {
      temp = q.front ();
      q.pop ();
      if (temp->llink)
	{
	  q.push (temp->llink);
	}

      if (temp->rlink)
	{
	  q.push (temp->rlink);
	}
    }

  return temp->info;

}

int
maxsum (node * root) //max sum in any level
{
  if (root == NULL)
    {
      return 0;
    }
  int m = INT_MIN, cur = 0;
  queue < node * >q;
  node *temp;
  q.push (root);
  q.push (NULL);
  while (!q.empty ())
    {
      temp = q.front ();
      q.pop ();
      if (temp == NULL)
	{
	  if (cur > m)
	    {
	      m = cur;
	    }
	  cur = 0;
	  if (!q.empty ())
	    {
	      q.push (NULL);
	    }
	}
      else
	{
	  cur = cur + temp->info;
	  if (temp->llink)
	    {
	      q.push (temp->llink);
	    }

	  if (temp->rlink)
	    {
	      q.push (temp->rlink);
	    }
	}

    }

  return m;

}

int
main ()
{
  node *root = NULL;
  int ch;
  cout <<
    "1.Insertion\n2.Inorder traversal\n3.Spiral traversal\n4.Preorder traversal\n5.Post order traversal\n6.zig zag traversal\n7.Deletion\n8.Level order(bfs) traversal\n9.Reverse level order traversal\n10.Size of Binary Tree\n11.Height of tree\n12.Deepest Node\n13.Max sum in a level\n14.Number of full nodes\n15.Max Element\n16.Search an element\n17.Mirror of tree\n18.Sum of all elements\n19.Number of half nodes\n20.Number of leaf nodes\n21.Exit\n";
  while (1)
    {
      cout << "Enter your choice\n";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  int key;
	  cout << "Enter the node to be inserted\n";
	  cin >> key;
	  root = insert (root, key);
	  break;
	case 2:
	  inorder (root);
	  cout << "\n";
	  break;
	case 3:
	  spiral (root);
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
	  zigzag (root);
	  cout << "\n";
	  break;
	case 7:
	  int v;
	  cout << "Enter the node to be deleted\n";
	  cin >> v;
	  root = del (root, v);
	  break;
	case 8:
	  levelorder (root);
	  break;
	case 9:
	  reverse (root);
	  break;
	case 10:
	  int s;
	  s = recursivesize (root);
	  cout << "Size of binary tree " << s << endl;
	  break;
	case 11:
	  int t;
	  t = recursiveheight (root);
	  cout << "Height of tree is " << t << endl;
	  break;
	case 12:
	  cout << deep (root) << endl;
	  break;
	case 13:
	  cout << maxsum (root) << endl;
	  break;
	case 14:
	  cout << "Number of full nodes " << numbernodes (root) << endl;
	  break;
	case 15:
	  cout << "Max element " << max (root) << endl;
	  break;
	case 16:
	  int x;
	  cout << "Enter the element to be searched\n";
	  cin >> x;
	  if (search (root, x))
	    {
	      cout << "Element found\n";
	    }
	  else
	    {
	      cout << "Not found\n";
	    }
	  break;
	case 17:
	  cout << "Before:";
	  inorder (root);
	  mirror (root);
	  cout << "\nAfter:";
	  inorder (root);
	  cout << endl;
	  break;
	case 18:
	  int z;
	  z = rsum (root);
	  cout << "Sum of all elements " << z << endl;
	  break;
	case 19:
	  cout << "Number of half nodes " << half (root) << endl;
	  break;
	case 20:
	  cout << "Number of leaf nodes " << leaf (root) << endl;
	  break;
	default:
	  exit (0);
	}
    }
  return 0;
}

