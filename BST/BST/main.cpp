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

void preorder(node* root) //�������
{
	if (root == NULL)
	{
		return;
	}
	printf("%d\t", root->data);
	preorder(root->lchild);//�ݹ����������
	preorder(root->rchild);//�ݹ����������
}
 
void inorder(node* root)//�������
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	printf("%d\t", root->data);
	inorder(root->rchild);
}

void postorder(node* root)//�������
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t", root->data);
}

void search(node* root, int x)//���Ҷ��������Һ���
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

void insert(node*& root, int x)//�����½��
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
	cout << "�������:" << endl;
	preorder(p);
	cout << endl;
	cout << "�������:" << endl;
	inorder(p);
	cout << endl;
	cout << "�������:" << endl;
	postorder(p);
	cout << endl;
	cout << "��������5�Ľڵ�" << endl;
	search(p, 5);
}