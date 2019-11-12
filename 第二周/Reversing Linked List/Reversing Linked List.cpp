#include <iostream>  
#include <vector>  
#include <iomanip>  
using namespace std;  
  
#define Max_Node_Num 100002  
  
typedef struct node  
{  
    int data;  
    int next;  
}Node;  
  
int Reverse(int head,int K,int N,vector<Node>& vec)//��������ת����ĺ��ĺ���  
{  
    int num=N/K;//��Ҫ��ת�Ĵ�СΪK��������ĸ���  
    int New_Begin=0;//��ת������µĿ�ʼ���ĵ�ַ  
    int flag=0;//�����K�������ת��洢�µĿ�ʼ��ַ�ı�־  
    while (num--)  
    {  
        int cnt=1,tmp;  
        int New=vec[head].next;//headΪ��һ��������ת������һ�����  
        int Record=New;  
        int Old=vec[New].next;  
        while (cnt<K)//������ת���������е�ÿ�����  
        {  
            tmp=vec[Old].next;  
            vec[Old].next=New;  
            New=Old;  
            Old=tmp;  
            cnt++;  
        }  
        vec[vec[head].next].next=Old;//������һ���ѱ��鵱ǰ���һ����㣨��תǰΪ�����һ����㣩ָ����һ���һ�����  
        vec[head].next=New;//��һ����ת����������һ�����ָ������ת��ĵ�һ�����  
        head=Record;//������ת������һ�������Ϊ��һ������δ��תʱ��ͷ���  
        if (flag==0)//��¼����������µĿ�ʼ��ַ����Ϊ��һ��������ת��ĵ�һ�����ĵ�ַ��  
        {  
            flag=1;  
            New_Begin=New;  
        }  
    }  
    return New_Begin;  
}  
  
int main(int argc, const char * argv[])  
{  
    //Input  
    vector<Node> List(Max_Node_Num);  
    int begin=0,N=0,K=0;  
    cin>>begin>>N>>K;  
    int front,value,rear;  
    for (int i=0; i<N; ++i)  
    {  
        cin>>front>>value>>rear;  
        List[front].data=value;  
        List[front].next=rear;  
    }  
     
      
    //Process  
    int Real_N=0;  
    int Begin_temp=begin;  
    while (Begin_temp!=-1)  
    {  
        Begin_temp=List[Begin_temp].next;  
        Real_N++;//Real_N��������Ľ����������֮�е���Ч���ĸ���  
    }  
      
    List[100001].next=begin;  
    int head=100001;  
    int new_begin=Reverse(head, K,Real_N, List);  
      
    //Output  
    while (new_begin!=-1)  
    {  
        if (List[new_begin].next==-1)//�����1�����0���ֿ�����  
        {  
            cout<<setfill('0')<<setw(5)<<new_begin<<' '<<List[new_begin].data<<' '<<List[new_begin].next;  
            //setfill������setw�����涨�Ĵ�Сδ��ʱ��䡮0��  
        }else  
        {  
            cout<<setfill('0')<<setw(5)<<new_begin<<' '<<List[new_begin].data<<' '<<setfill('0')<<setw(5)<<List[new_begin].next;  
        }  
        new_begin=List[new_begin].next;  
        cout<<endl;  
    }  
      
    return 0;  
}  

