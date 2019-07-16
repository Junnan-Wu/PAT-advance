//1012 The Best Rank
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

#define INF 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

struct node
{
    string ID;
    int score;
};


bool compare(node a,node b)
{
    return a.score>b.score;
}

int main()
{
    int n,m;
    string temp;
    cin>>n>>m;
    vector<node> A,C,M,E;
    map<string,int> orderA,orderC,orderM,orderE;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        node tep;
        tep.ID=temp;
        cin>>tep.score;C.push_back(tep);
        cin>>tep.score;M.push_back(tep);
        cin>>tep.score;E.push_back(tep);
        tep.score=(C[i].score+M[i].score+E[i].score)/3;A.push_back(tep);
    }

    sort(A.begin(),A.end(),compare);
    int rank=0,before=-1;
    for(auto p=A.begin();p!=A.end();p++)
    {
        if(p->score!=before)
        {
            rank=int(p-A.begin()+1);
            before=p->score;
        }
        orderA[p->ID]=rank;
    }

    sort(C.begin(),C.end(),compare);
    rank=0;before=-1;
    for(auto p=C.begin();p!=C.end();p++)
    {
        if(p->score!=before)
        {
            rank=int(p-C.begin()+1);
            before=p->score;
        }
        orderC[p->ID]=rank;
    }

    sort(M.begin(),M.end(),compare);
    rank=0;before=-1;
    for(auto p=M.begin();p!=M.end();p++)
    {
        if(p->score!=before)
        {
            rank=int(p-M.begin()+1);
            before=p->score;
        }
        orderM[p->ID]=rank;
    }

    sort(E.begin(),E.end(),compare);
    rank=0;before=-1;
    for(auto p=E.begin();p!=E.end();p++)
    {
        if(p->score!=before)
        {
            rank=int(p-E.begin()+1);
            before=p->score;
        }
        orderE[p->ID]=rank;

    }
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        int bestrank=INF;
        int rA,rC,rM,rE;
        rA=orderA[temp];rC=orderC[temp];rM=orderM[temp];rE=orderE[temp];
        bestrank=min(rA,bestrank);
        bestrank=min(rC,bestrank);
        bestrank=min(rM,bestrank);
        bestrank=min(rE,bestrank);
        if(bestrank==0)
            cout<<"N/A"<<endl;
        else
        {
            if(bestrank==rA)
                cout<<bestrank<<" A"<<endl;
            else if(bestrank==rC)
                cout<<bestrank<<" C"<<endl;
            else if(bestrank==rM)
                cout<<bestrank<<" M"<<endl;
            else
                cout<<bestrank<<" E"<<endl;
        }
    }
    return 0;
}
