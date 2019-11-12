#include <iostream>
#include <vector>
using namespace std;

typedef struct node Node;

struct node{
	int left;
	int right;
};

//��ʼ������������ 
void Init_Tree(vector<Node> &Tree,int N)
{
	for ( int i = 1 ; i <= N ; i++){
		Tree[i].left = -1;
		Tree[i].right = -1;
	}
}

//�������� 
void Build_Tree(vector<Node> &Tree,int N)
{
	int value;
	int flag = 0;
	int root = 0;
	int pre = 0;
	while(N--){
		cin>>value;
		if ( flag == 0){
			root = value;
			pre = root;
			flag = 1;
		}else{
			while(1){
				//��ǰ����ֵ�ȷ��ʵ���һ�����pre��pre���Ϊ����㣩����pre���Һ���  
				if (value > pre && Tree[pre].right != -1){
					pre = Tree[pre].right;
				}
				//��ǰ����ֵ�ȷ��ʵ���һ�����pre��pre���Ϊ����㣩����pre���Һ���  
				if (value > pre && Tree[pre].right == -1){
					Tree[pre].right = value;
					pre = root;//��һ����������Ҳ�Ӹ���㿪ʼ�Ƚ�  
					break;
				}
				//��ǰ����ֵ�ȷ��ʵ���һ�����pre��pre���Ϊ����㣩С����pre������ 
				if (value<pre && Tree[pre].left != -1) 
                {  
                    pre=Tree[pre].left;  
                }  
                //��ǰ����ֵ�ȷ��ʵ���һ�����pre��pre���Ϊ����㣩С����pre������
                if (value<pre && Tree[pre].left == -1)  
                {  
                    Tree[pre].left=value;  
                    pre=root;//��һ����������Ҳ�Ӹ���㿪ʼ�Ƚ�  
                    break;  
                }  
			}
		}
	} 
}

//�Ƚ����ö����������Ƿ���ͬ�ĺ��� 
bool Compare_Tree(vector<Node> &Tree1,vector<Node> &Tree2 ,int N)
{
	bool flag = true;
	for ( int i = 1 ; i <= N ; i++){
		if (!(Tree1[i].left == Tree2[i].left && Tree1[i].right == Tree2[i].right)){
			flag = false;
			break;
		} 
	}
	return flag;
 } 

int main()
{
	int N,L;
	int flag = 0;
	while(1){
		cin>>N;
		if ( N == 0){
			break;
		}
		cin>>L;
		vector<vector<Node>> Tree(L,vector<Node>(11));
		vector<Node> tree(11); 
		Init_Tree(tree,N);
		for ( int i = 0 ; i < L ; i++){
			Init_Tree(Tree[i],N);
		}
		Build_Tree(tree,N);
		for ( int i = 0 ; i < L ; i++){
			Build_Tree(Tree[i],N);
			if (Compare_Tree(tree,Tree[i],N)){
				if ( flag == 0){
					flag = 1;
					cout<<"Yes";
				}else{
					cout<<"\n"<<"Yes";
				}
			}else{
				if ( flag == 0){
					flag = 1;
					cout<<"No";
				}else{
					cout<<"\n"<<"No"; 
				}
			}
		}
	}
	
	return 0;
}

