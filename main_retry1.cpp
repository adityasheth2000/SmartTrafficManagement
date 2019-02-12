#include<bits/stdc++.h>
using namespace std;
#define gs 6
#define NUMBER_OF_ROBOTS 4
int path[gs][gs][NUMBER_OF_ROBOTS];
bool compare_position(pair<int,int> a,pair<int,int> b)
{
    return (a.first==b.first)&&(a.second==b.second);
}
void run_path(pair<int,int> ini[],pair<int,int> fin[],int i)
{
    
    pair<int,int> changed_pos;
    int flag=0;
    if(ini[i].first!=fin[i].first)
    {
        changed_pos.first=ini[i].first+(fin[i].first-ini[i].first)/abs(fin[i].first-ini[i].first);
        changed_pos.second=ini[i].second;
        flag=1;
    }
    for(int j=0;j<NUMBER_OF_ROBOTS;j++)
    {
        if(i==j)
        {
            continue;
        }
        if(ini[j]==changed_pos)
        {
            flag=0;            
        }
    }
    if(flag==0)
    {
        if(ini[i].second!=fin[i].second)
        {
            changed_pos.second=ini[i].second+(fin[i].second-ini[i].second)/abs(fin[i].second-ini[i].second);
            changed_pos.first=ini[i].first;
            flag=1;
        }    
        
        for(int j=0;j<NUMBER_OF_ROBOTS;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(ini[j]==changed_pos)
            {
                flag=0;            
            }
        }
        if(flag==0)
        {
            if(ini[i].first!=fin[i].first)
            {
                changed_pos.first=ini[i].first-(fin[i].first-ini[i].first)/abs(fin[i].first-ini[i].first);
                changed_pos.second=ini[i].second;
                flag=1;
            }
            for(int j=0;j<NUMBER_OF_ROBOTS;j++)
            {
                if(i==j)
                {
                     continue;
                }
                if(ini[j]==changed_pos)
                {
                    flag=0;            
                }
            }
            if(flag==0)
            {
                changed_pos.second=ini[i].second-(fin[i].second-ini[i].second)/abs(fin[i].second-ini[i].second);
                changed_pos.first=ini[i].first;
                flag=1;
            }
        }
    }

    ini[i]=changed_pos;
    path[changed_pos.first][changed_pos.second][i]=i+1;


}
int main()
{
    pair<int,int> fin[NUMBER_OF_ROBOTS];
    pair<int,int> ini[NUMBER_OF_ROBOTS];
    for(int i=0;i<NUMBER_OF_ROBOTS;i++)
    {
        cin>>ini[i].first>>ini[i].second>>fin[i].first>> fin[i].second;
    }
    
    for(int i=0;i<gs;i++)
    {
        for(int j=0;j<gs;j++)
        {
            for(int k=0;k<NUMBER_OF_ROBOTS;k++)
            {
                path[i][j][k]=0;
            }
        }
    }

    for(int i=0;i<NUMBER_OF_ROBOTS;i++)
    {
        path[ini[i].first][ini[i].second][i]=i+1;
    }

    while(1)
    {
        int flag=0;
        for(int i=0;i<NUMBER_OF_ROBOTS;i++)
        {
            if(compare_position(ini[i],fin[i])==false)
            {
                flag=1;
                run_path(ini,fin,i);
            }
        }
        if(flag==0)
        {
            break;
        }
        
        
    }

    for(int i=0;i<gs;i++)
    {
        for(int j=0;j<gs;j++)
        {
            printf("(");
            for(int k=0;k<NUMBER_OF_ROBOTS;k++)
            {
                printf("%d,",path[i][j][k]);
            }
            printf(") ");
        }
        cout<<endl;
    }



}