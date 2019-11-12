#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int data;
	int left;
	int right;
};

//�������������ظ��ڵ� 
int BuildTree(vector<struct Node> &Tree,int N){
	int root = -1;
	char left,right;
	vector<int> check(N,0);
	
	for ( int i = 0 ; i < N ; i++){
		cin>>left>>right;
		Tree[i].data = i;
		//�ж��������Ƿ�Ϊ�գ���Ϊ�����ckeck������Ӧλ��1,������-1 
		if ( left != '-'){
			Tree[i].left = (int)(left-'0');
			check[Tree[i].left] = 1;
		}else{
			Tree[i].left = -1;
		}
		//�ж��������Ƿ�Ϊ�գ���Ϊ�����ckeck������Ӧλ��1,������-1 
		if ( right != '-'){
			Tree[i].right = (int)(right-'0');
			check[Tree[i].right] = 1;
		}else{
			Tree[i].right = -1;
		}
	}
	
	//Ѱ�Ҹ��ڵ������ 
	for ( int i = 0 ; i < N ; i++){
		if ( check[i] == 0){
			root = i;
			break;
		}
	}
	return root;
} 

//Ѱ��Ҷ�ӽڵ㺯��
vector<int> Find_Leaves(vector<struct Node> &Tree,int root)
{
	vector<int> leaves;
	queue<struct Node> que;
	struct Node treenode;
	if ( root == -1){
		return {};
	}else{
		que.push(Tree[root]);
		while(!que.empty()){
			treenode = que.front();
			que.pop();
			if ( treenode.left == -1 && treenode.right == -1){
				leaves.push_back(treenode.data);
			}
			if ( treenode.left != -1){
				que.push(Tree[treenode.left]);
			}
			if ( treenode.right != -1){
				que.push(Tree[treenode.right]);
			}
		}
 	}
 	return leaves;
}

void Print(vector<int> & leaves)
{
	cout<<leaves[0];
	for ( int i = 1 ; i < leaves.size() ; i++){
		cout<<" "<<leaves[i];
	}
}

int main()
{
	int N;//���ڵ�ĸ��� 
	cin>>N;
	vector<struct Node> Tree(N); //�洢���������� 
	
	//��ɽ������̣����ظ��ڵ�����
	int root = BuildTree(Tree,N);
	
	//Ѱ��Ҷ�ӽ������ 
	vector<int> leaves = Find_Leaves(Tree,root);
	
	//��ӡ����Ҷ�ӽ�� 
	Print(leaves);
	
	return 0;
}
