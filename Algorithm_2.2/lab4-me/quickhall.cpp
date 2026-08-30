#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<ll,ll> iPair;
vector<iPair>hull;

ll findSide(iPair p1,iPair p2,iPair p)
{
    ll val=(p.second-p1.second)*(p2.first-p1.first)-(p2.second-p1.second)*(p.first-p1.first);

    if(val>0) return 1;
    if(val<0) return -1;
    return 0;
}

ll lineDist(iPair p1,iPair p2,iPair p)
{
    ll dist = abs((p.second-p1.second)*(p2.first-p1.first)-(p2.second-p1.second)*(p.first-p1.first));
    return dist;
}

void quickHull(vector<iPair>&points,ll n,iPair p1,iPair p2,ll side)
{
    ll idx=-1;
    ll mxDist=0;

    for(ll i=0;i<n;i++)
    {
        ll temp=lineDist(p1,p2,points[i]);

        if(findSide(p1,p2,points[i])==side && temp>mxDist)
        {
            idx=i;
            mxDist=temp;
        }
    }

    if(idx==-1)
    {
        hull.push_back(p1);
        hull.push_back(p2);
        return;
    }


    quickHull(points,n,points[idx],p1,-findSide(points[idx],p1,p2));
    quickHull(points,n,points[idx],p2,-findSide(points[idx],p2,p1));
}

int main()
{
    vector<iPair>points=
    {
        {0,3},
        {2,2},
        {1,1},
        {2,1},
        {3,0},
        {0,0},
        {3,3}
    };

    ll n=points.size();

    ll minX=0;
    ll maxX=0;

    for(ll i=1;i<n;i++)
    {
        if(points[i].first<points[minX].first)
            minX=i;

        if(points[i].first>points[maxX].first)
            maxX=i;
    }

    quickHull(points,n,points[minX],points[maxX],1);
    quickHull(points,n,points[minX],points[maxX],-1);

    sort(hull.begin(),hull.end());
    hull.erase(unique(hull.begin(),hull.end()),hull.end());

    cout<<"Convex Hull:\n";

    for(auto p:hull)
        cout<<"("<<p.first<<","<<p.second<<")\n";
}