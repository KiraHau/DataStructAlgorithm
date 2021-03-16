#include <iostream>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};

node* newNode(int v)
{
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

void preorder(node* root) //先序遍历
{
	if (root == NULL)
	{
		return;
	}
	printf("%d\t", root->data);
	preorder(root->lchild);//递归访问左子树
	preorder(root->rchild);//递归访问右子树
}
 
void inorder(node* root)//中序遍历
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	printf("%d\t", root->data);
	inorder(root->rchild);
}

void postorder(node* root)//后序遍历
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t", root->data);
}

void search(node* root, int x)//查找二叉树查找函数
{
	if (root == NULL)
	{
		printf("search failed\n");
		return;
	}
	if (x == root->data)
	{
		printf("%d\n", root->data);
	}
	else if (x < root->data)
	{
		search(root->lchild, x);
	}
	else search(root->rchild, x);
}

void insert(node*& root, int x)//插入新结点
{
	if (root == NULL)
	{
		root = newNode(x);
		return;
	}
	if (x == root->data)
	{
		return;
	}
	else if (x < root->data)
	{
		insert(root->lchild, x);
	}
	else insert(root->rchild, x);
}

node* Create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}
	return root;
};

void main()
{
	int a[10] = { 5,0,2,7,4,3,8,9,6,1 };
	node* p = Create(a, 10);
	cout << "先序遍历:" << endl;
	preorder(p);
	cout << endl;
	cout << "中序遍历:" << endl;
	inorder(p);
	cout << endl;
	cout << "后序遍历:" << endl;
	postorder(p);
	cout << endl;
	cout << "查找数字5的节点" << endl;
	search(p, 5);
}