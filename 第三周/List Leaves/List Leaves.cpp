#include<iostream>
using namespace std;
#define  MaxNum 10//������������
#define ElementType int
#define Tree int
#define NUll -1//��ʾ�ýڵ�Ϊ��
struct TreeNode{//���ڵ�ı�ʾ
    ElementType index;//��¼�ýڵ���±�
    Tree left;//������
    Tree right;//������
}; 
int Num;//��¼�����ʵ�ʴ�С
TreeNode T1[MaxNum];//������¼�������
TreeNode T2[MaxNum];//�����źõ���
Tree BuildTree(struct TreeNode T[], int Num){
    char a;
    int i;
    int  check[MaxNum];//check����������Ǹ����������ڵ�
    for (i = 0; i < Num; i++){ check[i] = 0; }
    for (i = 0; i < Num; i++){
        T[i].index=i;
        cin >> a;//����������
        if (a != '-'){//����������ݽ����ж�
            T[i].left = a - '0';
            check[T[i].left] = 1;
        }//�ж�����������Ƿ���'-'������ǵĻ��͸�ֵΪ-1,����ת���õ���������T[i]����������������check�ϼ�¼
        else { T[i].left = NUll; }
        cin >> a;//����������
        if (a != '-'){
            T[i].right = a - '0';
            check[T[i].right] = 1;
        }
        else { T[i].right = NUll; }
    }
    for (i = 0; i < Num; i++){//�ҵ����ڵ�
        if (!check[i])
            return i;
}
int FindPos(int i){//�ҵ�������ʺ��±꣬�����ظ��±�
    for (int j = i; j < Num; j++){//��i��ʼ���ң�һֱ�ҵ�һ��Ϊ�յ���
        if (T2[j].index == NUll)
            return j;
    }
}
int Insert(int root){
    int count = 1;//��¼Ҷ�ӵĸ���
    int left, right;//��¼���ӵ��±꣬��¼�Һ��ӵ��±�
    int pos;//��¼Ҫ����λ�õ��±�
    for (int i = 0; i < MaxNum; i++){//��ʼ��T2
        T2[i].index = T2[i].left = T2[i].right = NUll;
    }
    T2[0] = T1[root];//������ڵ�
    for (int i = 1; i < Num; i++){
        left = T2[i - 1].left;
        right = T2[i - 1].right;
        if (left == NUll&&right == NUll){ count += 1; }
        if (left != NUll){//��������
            pos = FindPos(i);
            T2[pos] = T1[left];
        }
        if (right != NUll){//�����Һ���
            pos = FindPos(i);
            T2[pos] = T1[right];
        }
    }
    return count;//����Ҷ�ӵ���Ŀ
}
void output(int count){//���Ҷ��
    int i;
    for (i = 0; count!=1; i++){
        if (T2[i].left == NUll&&T2[i].right == NUll){
            cout << T2[i].index << " ";
            count--;
        }
    }
    for (; i < Num; i++){//Ϊ�˷�����Ŀ�����Ҫ��
        if (T2[i].left == NUll&&T2[i].right == NUll)
            cout << T2[i].index;
    }
}
int main(){
    int r1;
    int count;
    cin >> Num;
    r1=BuildTree(T1, Num);
    count=Insert(r1);
    output(count);
}
