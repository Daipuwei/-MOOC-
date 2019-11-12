#include <iostream>
using namespace std;

struct Node{
	int tag;   //�ڼ��ν�ջ 
	int num;
};

/*���������Ӧ��ջ˳�����������Ӧ��ջ˳��  
  ������������������ͬ���ǽڵ��ջ��Ҫ��������ջ��tag���ڶ�����ջ��ǣ������Ҷ��ӱ�������ٳ�ջ;  
  ����ʵ���ϣ�ÿ�����������popʱ�����ջ���Ǳ�ǹ��Ľڵ㣨tag=2����ѭ�����������û�б�ǹ���tag=1��������ǣ���������ѹջ��  
  ջ��tag=2�Ľڵ��Ӧ����������ѵ����Ľڵ㣻ѭ�������������ĵ�һ��tag=1�Ľڵ�Ŷ�Ӧ���������ǰpop�Ľڵ�  
*/

int main()
{
	int N;
	cin>>N;
	struct Node stack[30];
	int flag = 0;
	int size = 0;				//ջԪ�ش�С��ָ��ջ������һ��λ��  
	for ( int i = 0 ; i < 2*N ; i++){
		string str;
		cin>>str;
		if(str[1] == 'u'){
			cin>>stack[size].num;	//��ջ  
			stack[size].tag = 1;	//��ǵ�һ����ջ  
			size++;
		}else{
			//ѭ������ջ��tag=2�Ľڵ� 
			while(size > 0 && stack[size-1].tag == 2){
				if( flag){
					cout<<" ";
				}
				flag = 1;
				cout<<stack[--size].num;
			}
			//�����������Ӧ��Ҫ�����Ľڵ㵯����ѹջ������Ǽ���  
			if ( size>0){
				stack[size-1].tag = 2;
			}

		} 
	}
	while(size){
		if ( flag ){
			cout<<" ";
		}
		flag = 1;
		cout<<stack[--size].num;
	}
	
	return 0;
}
