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
	if (len <= 0) return NULL;//长度小于等于0是递归结束
	binaryTree* root = new binaryTree;
	if (root == NULL) return NULL;
	root->date = pre[0];//pre[0]写入结点值
	int n = 0;//表示前序第一个在中序的位置
	while (in[n] != pre[0]) n++;//计算pre[0]在in中的位置
	char*lin, *rin;
	lin = in;//左子树中序遍历结果，只用前n位
	rin = in + n + 1;//右子树中序遍历结果
	root->leftChild = creatBinaryTree(pre + 1, lin, n);
	root->rightChild = creatBinaryTree(pre + n + 1, rin, len - n - 1);
	return root;
}
void postOrder(binaryTree*tree) {//后序遍历输出递归算法
	if (tree != NULL) {
		postOrder(tree->leftChild);
	    postOrder(tree->rightChild);
		cout << tree->date;
	}
}
void preOrder(binaryTree*tree,int a) {//凹入法输出
	if (tree == NULL) return;
		a+=3;//控制空格的数量
		preOrder(tree->rightChild, a);
		for (int i = 1; i <= a; i++)cout << " ";
	    cout << tree->date << endl;
		preOrder(tree->leftChild, a);
}
void inOrder(binaryTree*tree) {//中序遍历输出递归算法
	if (tree != NULL) {
		inOrder(tree->leftChild);
		cout << tree->date;
		inOrder(tree->rightChild);
	}
}
void print(binaryTree*tree) {//前序遍历输出非递归算法
	stack<binaryTree*>S;
	binaryTree*p = tree;
	S.push(NULL);
	while (p != NULL) {
		cout << p->date;
		if (p->rightChild != NULL) S.push(p->rightChild);//右子树先入栈
		if (p->leftChild != NULL)  S.push(p->leftChild); //左子树随后入栈
		p = S.top();//取栈顶
		S.pop();//弹出栈顶
	}
}
int main() {
	binaryTree *tree;
	tree = NULL;
	char pre[N], in[N];
	string ch;
	int len = 0;
	loop:
	cout << "输入前序遍历结果：";
	cin >> ch;
	int len1 = ch.length();//计算pre输入的长度
	for (; len < len1; len++) pre[len] = ch[len];//把输入的string转换为char型数组
	cout << "输入中序遍历结果：";
	cin >> ch;
	int len2 = ch.length();
	for (len = 0; len < len2; len++) in[len] = ch[len];
	if (len1 != len2) {//前序与中序长度不同，判断输入出现错误
		cout << "输入错误" << endl;
		goto loop;
	}
	tree = creatBinaryTree(pre, in, len);
	cout << "后序遍历结果：" << endl;
	postOrder(tree);
	cout << endl;
	cout << "前序遍历结果：" << endl;
	print(tree);
	cout << endl;
	cout << "中序遍历结果：" << endl;
	inOrder(tree);
	cout << endl;
	cout << "凹入法输出：" << endl;
	preOrder(tree,0);
	cout << endl;
	system("pause");
}