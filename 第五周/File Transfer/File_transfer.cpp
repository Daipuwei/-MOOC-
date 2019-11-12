#include <iostream>
#include <vector>

using namespace std;

#define Max_Node 10001

typedef struct
{
    int parent;
}Node;

int Find_Set(vector<Node> &set,int value)//Ѱ�ҵ�ǰvalue���ڵĲ��鼯�ĸ����
{
    while (set[value].parent>0)
    {
        value=set[value].parent;
    }
    return value;
}

void Union_Set(vector<Node> &set,int value1,int value2)//�ϲ��������Ĳ��鼯
{
    int root1=Find_Set(set, value1);
    int root2=Find_Set(set, value2);
    if (set[root1].parent<set[root2].parent)//��root1Ϊ���Ĳ��鼯�Ľ��������࣬�����鼯�������ٵĺϲ�����������Ĳ��鼯
    {
        set[root2].parent=root1;
        set[root1].parent--;
    }else
    {
        set[root1].parent=root2;
        set[root2].parent--;
    }
}

bool Check_Set(vector<Node> &set,int value1,int value2)//��ѯ������Ƿ���ͬһ�����鼯
{
    int root1=Find_Set(set, value1);
    int root2=Find_Set(set, value2);
    if (root1==root2)
    {
        return true;
    }else
    {
        return false;
    }
}

int Count_Set(vector<Node> &set)//��ѯ��ǰ���鼯�ĸ���
{
    int count=0;
    for (int i=1; i<=set.size(); ++i)
    {
        if (set[i].parent<0)//parentС��0��ý��Ϊһ�����鼯�ĸ�
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int N=0;
    cin>>N;
    vector<Node> Set(N+1);
    for (int i=1; i<=N; ++i)
    {
        Set[i].parent=-1;
    }
    char str;
    int value1=0,value2=0;
    while (1)
    {
        cin>>str;
        if (str=='S')
        {
            break;
        }else if(str=='I')
        {
            cin>>value1>>value2;
            Union_Set(Set, value1, value2);
        }else
        {
            cin>>value1>>value2;
            if (Check_Set(Set, value1, value2))
            {
                cout<<"yes\n";
            }else
            {
                cout<<"no\n";
            }
        }
    }
    
    int count=Count_Set(Set);
    if (count>1)
    {
        cout<<"There "<<"are "<<count<<" components.";
    }else
    {
        cout<<"The network is connected.";
    }
    return 0;
}
