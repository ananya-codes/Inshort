#include <bits/stdc++.h> 
using namespace std;

int getMaxIndex(int amount[],int n)
{
    int ind=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]>amount[ind])
        {
            ind=i;
        }
    }
    return ind;
}
int getMinIndex(int amount[],int n)
{
    int ind=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]<amount[ind])
        {
            ind=i;
        }
    }
    return ind;
}
void MinimumCashFlow(int amount[],int n,vector<vector<int>>&ans)
{
    int MaxDebt=getMinIndex(amount,n);
    int MaxCredit=getMaxIndex(amount,n);

    if(amount[MaxDebt]==0 && amount[MaxCredit]==0)
    {
        return ;
    }

    int mini= min((-1)*amount[MaxDebt],amount[MaxCredit]);
    amount[MaxCredit]-=mini;
    amount[MaxDebt]+=mini;

    ans[MaxDebt][MaxCredit]=mini;

    MinimumCashFlow(amount,n,ans);
}

vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n)
{
  //int c = n;
  
    int* amount = new int[n];
  for (int i = 0; i < n; i++)
  {
      amount[i] = 0;
  }
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            amount[i]+=(transaction[j][i]-transaction[i][j]);
        }
    }
    MinimumCashFlow(amount,n,ans);
    return ans;
}
int main()
{
  int  n;
  cout<<"Enter the no of people involved"<<endl;
  cin>>n;
  cout<<"Enter the transactions for each of the following"<<endl;
  vector<vector<int>>transaction(n,vector<int>(n,0));

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        {
          if(j!=i){
            cout<<"Person "<< i+1<<" to "<<"Person "<<j+1<<endl;
            int x;
            cin>>x;
            transaction[i][j] = x;
            }
        }
    }
  vector<vector<int>> finalTran = minCashFlow(transaction,n);
  cout<<"Optimal Transactions are: "<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      {
        if(finalTran[i][j]>0)
        {
          cout<<"Person "<<i+1<<" gives Person "<<j+1<<" "<<finalTran[i][j]<<endl;
        }
      }
  }
  return 0;
}