#include <iostream>
#include<algorithm>
using namespace std;

struct node
{
	int v, height;//height记录子树高度从而保证平衡因子绝对值小于1
	node* lchild, * rchild;
};

node* newNode(int v)//新建节点
{
	node* Node = new node;
	Node->v = v;
	Node->height = 1;//树节点初始化时高度设为1
	Node->lchild = Node->rchild = NULL;
	return Node;
}

int getHeight(node* root) {
	if (root == NULL) return 0;//空树高度为0
	return root->height;
}

int getBalanceFactor(node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;//通过递归算法逐层计算AVL树的高度
}

void search(node* root, int x)//AVL树查找函数
{
	if (root == NULL)
	{
		printf("search failed\n");
		return;
	}
	if (x == root->v)
	{
		printf("%d\n", root->v);
	}
	else if (x < root->v)
	{
		search(root->lchild, x);
	}
	else search(root->rchild, x);
}

void L(node*& root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;

}

void R(node*& root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node*& root, int v)
{
	if (root == NULL)
	{
		root = newNode(v);
		return;
	}
	if (v < root->v)
	{
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2)
		{
			if (getBalanceFactor(root->lchild) == 1)
			{
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1)
			{
				L(root->lchild);
				R(root);
			}
		}
		else
		{
			if (getBalanceFactor(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == -1)
			{
				L(root);
			}
		}
	}
}

node* Create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}
	return root;
}