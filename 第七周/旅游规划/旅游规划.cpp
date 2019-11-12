#include <iostream>
#include <cstring>
#include <stack>
#define INF  100000
using namespace std; 

/* ����Ҫ�� ��֤��̾��룬��������� ��ѡȡ�ܼ۸���͵�·��
   1. dijkstra�����·  һ���½ڵ�������ҵ����·���ļ���S�� �����������е��Ȩ��ʱ  ��Ҫ����һ�����  ���ǵ����벻��ʱ  ���¼۸�Ϊ��С��
   ����·�ļ۸� ��
*/

class Graph{
	private:
		int V;
		int E;
		int** dis;						//����֮��ľ���
		int** cost; 					//����֮���·�� 
		int* collected;					//�жϸõ��Ƿ��Ѿ�������· 
		int* dist;						//������s��ͼ��ÿ�����е���̾��� 
		int* cos;						//������s��ͼ��ÿ�����е����·�� 
	public:
		//���캯�� 
		Graph(int v,int e){
			this->V = v;
			this->E = e;
			this->dis = new int*[V];
			this->cost = new int*[V];
			this->collected = new int[V];
			this->dist = new int[V];
			this->cos = new int[V];
			for ( int i = 0 ; i < this->V ; i++){
				this->dis[i] = new int[this->V];
				this->cost[i] = new int[this->V];
				this->collected[i] = 0;
				for ( int j = 0 ; j < this->V ; j++){
					this->dis[i][j] = INF;
					this->cost[i][j] = INF;
				}
			}
			
			for ( int i = 0 ; i < this->E ; i++){
				int a,b,c,d;
				cin>>a>>b>>c>>d;
				this->dis[a][b] = this->dis[b][a] = c;
				this->cost[a][b] = this->cost[b][a] = d;
			}
		}
		
		//��ʼ����̾�������·�� 
		void Init(int s){
			for ( int i = 0 ; i < this->V ; i++){
				dist[i] = this->dis[i][s];
				this->cos[i] = this->cost[i][s];
			}
		}
		
		//sΪ�����㣬dΪĿ�ĵ㣬����Dijkstra����̾��������·�� 
		void Dijkstra(int s){	
			int v;
			this->Init(s);
			//�Ƚ�������뼯��
			dist[s] = 0;			//��ʼ״̬ v�ڵ����ڼ��� 
			this->collected[s] = 1;
			for ( int k = 0 ; k < this->V ; k++){//��ʼ��ѭ�� ÿ�����v��ĳ����������·�� ����v������
				int MIN = INF;					//��ǰ��֪��v0����Ľڵ�
				int v;
				for (int j = 0 ; j < V ; j++){
					if ( !this->collected[j] && this->dist[j] < MIN){
						MIN = dist[j];				//�ҵ����·���ڵ�
						v = j;
					}
				}
				this->collected[v] = 1;
				for ( int i = 0 ; i < this->V ; i++){			//���µ�ǰ�����·��
						if( !this->collected[i] && MIN + this->dis[v][i] < dist[i]){
							this->dist[i] = MIN + this->dis[v][i];
							this->cos[i] = this->cos[v] +this->cost[v][i]; 
						}else if(!this->collected[i] && MIN + this->dis[v][i] == dist[i]
							&& this->cos[i] > this->cos[v] + this->cost[v][i]){
								//·�����������ѡ��۸�ϱ��˵�һ��
								this->cos[i] = this->cos[v] + this->cost[v][i];
						}
				}	
			}  
		}
		
		void Print(int d){ 
			cout<<this->dist[d]<<" "<<this->cos[d]<<endl; 
		}
};

int main()
{
	int v,e,s,d;
	cin>>v>>e>>s>>d;
	Graph graph(v,e);
	graph.Dijkstra(s);
	graph.Print(d);
	
	return 0;
}
