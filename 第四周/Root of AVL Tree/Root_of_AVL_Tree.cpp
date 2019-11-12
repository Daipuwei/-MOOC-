#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct AVLNode* AVLTree ;

struct AVLNode{
	int val;
	AVLTree left;
	AVLTree right;
	int height; 
}; 

//��������ȵĺ��� 
int getHeight(AVLTree t) 
{  
    if (t)  
        return max(getHeight(t->left) , getHeight(t->right)) + 1;  
    else  
        return 0;  
}  

//���� 
AVLTree SingleLeftRotation(AVLTree a) 
{   
    AVLTree b = a->left;  
    a->left = b->right;  
    b->right = a;  
    a->height = max(getHeight(a->left),getHeight(a->right))+1;  
    b->height = max(getHeight(b->left), a->height)+1;  
    return b;  
}  

//���� 
AVLTree SingleRightRotation(AVLTree t) 
{  
    AVLTree b = t->right;  
    t->right = b->left;  
    b->left = t;  
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;  
    b->height = max(getHeight(b->right),t->height) + 1;  
    return b;  
}  

//������ 
AVLTree DoubleLeftRightRotation(AVLTree t) 
{  
    t->left = SingleRightRotation(t->left);  
    return SingleLeftRotation(t);  
}  

//������ 
AVLTree DoubleRightLeftRotation(AVLTree t) 
{  
    t->right = SingleLeftRotation(t->right);  
    return SingleRightRotation(t);  
}  

//���뺯�� 
AVLTree AVL_Insertion(int x, AVLTree t)
{
	/* ����X��AVL�� �����ص������AVL�� */  
    if (!t) {  
        t = (AVLTree)malloc(sizeof(struct AVLNode));  
        t->val = x;  
        t->height = 0;  
        t->left = t->right = NULL;  
    }  
    else if (x < t->val) {  
        t->left = AVL_Insertion(x, t->left);  
        if (getHeight(t->left) - getHeight(t->right) == 2) {  
            /*��Ҫ����*/  
            if (x < t->left->val) {  
                t = SingleLeftRotation(t);/* ���� */  
            }  
            else {  
                t = DoubleLeftRightRotation(t); /* ����˫�� */  
            }  
        }  
    }  
    else if ( x> t->val) {  
        t->right = AVL_Insertion(x, t->right);  
        if (getHeight(t->right) - getHeight(t->left) == 2) {  
            /*��Ҫ����*/  
            if (x > t->right->val) {  
                t = SingleRightRotation(t);/* ���� */  
            }  
            else {  
                t = DoubleRightLeftRotation(t); /* ����˫�� */  
            }  
        }  
    }  
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;  
    return t;  
 } 

//�ݹ�������� 
void preOrder(AVLTree avl) 
{  
    if (avl) {  
        cout << avl->val << " ";  
        preOrder(avl->left);  
        preOrder(avl->right);  
     }  
}  

int main()
{
	int N;
	cin>>N;
	AVLTree avl = NULL;
	for ( int i = 0 ; i < N ; i++){
		int t;
		cin>>t;
		avl = AVL_Insertion(t,avl);
	}
	
	cout<<avl->val; 
	return 0;
 } 
