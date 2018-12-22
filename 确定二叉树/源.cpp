#include<iostream>
#include<string>
#include<stack>
#include<vector>
#define N 100
using namespace std;
typedef struct Tree {
	char date;
	Tree *rightChild;
	Tree *leftChild;
}binaryTree;
binaryTree* creatBinaryTree(char*pre, char *in, int len) {
	if (len <= 0) return NULL;//����С�ڵ���0�ǵݹ����
	binaryTree* root = new binaryTree;
	if (root == NULL) return NULL;
	root->date = pre[0];//pre[0]д����ֵ
	int n = 0;//��ʾǰ���һ���������λ��
	while (in[n] != pre[0]) n++;//����pre[0]��in�е�λ��
	char*lin, *rin;
	lin = in;//������������������ֻ��ǰnλ
	rin = in + n + 1;//����������������
	root->leftChild = creatBinaryTree(pre + 1, lin, n);
	root->rightChild = creatBinaryTree(pre + n + 1, rin, len - n - 1);
	return root;
}
void postOrder(binaryTree*tree) {//�����������ݹ��㷨
	if (tree != NULL) {
		postOrder(tree->leftChild);
	    postOrder(tree->rightChild);
		cout << tree->date;
	}
}
void preOrder(binaryTree*tree,int a) {//���뷨���
	if (tree == NULL) return;
		a+=3;//���ƿո������
		preOrder(tree->rightChild, a);
		for (int i = 1; i <= a; i++)cout << " ";
	    cout << tree->date << endl;
		preOrder(tree->leftChild, a);
}
void inOrder(binaryTree*tree) {//�����������ݹ��㷨
	if (tree != NULL) {
		inOrder(tree->leftChild);
		cout << tree->date;
		inOrder(tree->rightChild);
	}
}
void print(binaryTree*tree) {//ǰ���������ǵݹ��㷨
	stack<binaryTree*>S;
	binaryTree*p = tree;
	S.push(NULL);
	while (p != NULL) {
		cout << p->date;
		if (p->rightChild != NULL) S.push(p->rightChild);//����������ջ
		if (p->leftChild != NULL)  S.push(p->leftChild); //�����������ջ
		p = S.top();//ȡջ��
		S.pop();//����ջ��
	}
}
int main() {
	binaryTree *tree;
	tree = NULL;
	char pre[N], in[N];
	string ch;
	int len = 0;
	loop:
	cout << "����ǰ����������";
	cin >> ch;
	int len1 = ch.length();//����pre����ĳ���
	for (; len < len1; len++) pre[len] = ch[len];//�������stringת��Ϊchar������
	cout << "����������������";
	cin >> ch;
	int len2 = ch.length();
	for (len = 0; len < len2; len++) in[len] = ch[len];
	if (len1 != len2) {//ǰ�������򳤶Ȳ�ͬ���ж�������ִ���
		cout << "�������" << endl;
		goto loop;
	}
	tree = creatBinaryTree(pre, in, len);
	cout << "������������" << endl;
	postOrder(tree);
	cout << endl;
	cout << "ǰ����������" << endl;
	print(tree);
	cout << endl;
	cout << "������������" << endl;
	inOrder(tree);
	cout << endl;
	cout << "���뷨�����" << endl;
	preOrder(tree,0);
	cout << endl;
	system("pause");
}