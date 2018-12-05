#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace  std;
#define local
const int maxn =1e5+5;
const int inf=0x3f3f3f3f;
//int map[maxn][maxn];
bool vis[maxn];
int d[maxn];
int d1[maxn];
int n,m;
struct node
{
    int v,dis;
    node(int a, int b){
        v=a;
        dis=b;
    }
    bool operator <(const node &a)const{
        return dis>a.dis;
    }
};
struct edge
{
    int f,t,v;
    edge(int from, int to,int value){
        f=from;
        t=to;
        v=value;
    }
    //    edge(){}
};
vector< edge > G[maxn];
vector< edge > G1[maxn];
priority_queue< node > que;
int dijkstra1(){
    memset(d,inf,sizeof d);
    memset(vis,0,sizeof vis);
    d[0]=0;
    que.push(node(0,0));
    while(!que.empty()){
        node tem=que.top();
        que.pop();
        if(vis[tem.v]){
            continue;
        }
        int u=tem.v;
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
            
            int to=G[u][i].t;
            int w=G[u][i].v;
            //        for(int i=0;i<n;i++){
            //        cout<<vis[i]<<endl;
            //    }
            //    cout<<u<<" "<<w<<" "<<to<<endl;
            if(d[to]>d[u]+w&&!vis[to]){
                d[to]=d[u]+w;
                que.push(node(to,d[to]));
            }
        }
    }
    return d[n-1];
}
int dijkstra2(){
    memset(d,inf,sizeof d);
    memset(vis,0,sizeof vis);
    d[0]=0;
    que.push(node(0,0));
    while(!que.empty()){
        node tem=que.top();
        que.pop();
        if(vis[tem.v]){
            continue;
        }
        int u=tem.v;
        vis[u]=1;
        for(int i=0;i<G1[u].size();i++){
            
            int to=G1[u][i].t;
            int w=G1[u][i].v;
            //        for(int i=0;i<n;i++){
            //        cout<<vis[i]<<endl;
            //    }
            //    cout<<u<<" "<<w<<" "<<to<<endl;
            if(d[to]>d[u]+w&&!vis[to]){
                d[to]=d[u]+w;
                que.push(node(to,d[to]));
            }
        }
    }
    return d[n-1];
}
int main()
{
#ifdef local
    freopen("in","r",stdin);
    freopen("out","wt+",stdout);
#endif
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int f,t,v;
        //memset(map,0,sizeof map);
        for(int i=0;i<=n;i++){
            G[i].clear();
            G1[i].clear();
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&f,&t,&v);
            //    cout<<f<<" "<<t<<" "<<v<<endl;
            //    map[f][t]=v;
            //edges.push(new edge(f,t,v));
            edge a(f-1,t-1,v);
            edge b(t-1,f-1,v);
            G[f-1].push_back(a);
            G1[t-1].push_back(b);
        }
        dijkstra1();
        for(int i=0;i<n;i++){
            d1[i]=d[i];
     //       cout<<d1[i]<<" ";
        }
        //cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<G[i].size();j++){
                int tem=G[i][j].f;
                G[i][j].f=G[i][j].t;
                G[i][j].t=tem;
            }
        }
        dijkstra2();
        int sum=0;
        for(int i=0;i<n;i++){
     //       cout<<d[i]<<" ";
            sum+=(d[i]+d1[i]);
        }
       // cout<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
