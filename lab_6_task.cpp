//Unlimited coins
#include <bits/stdc++.h>
using namespace std;
#define INF 1e4;
int MAX_C = 1e3;
int  MAX_W = 1e3;

int W;

vector<int>coin;
int n; // number of coins.
int table[100][10000]; // initialized to -1
int F(int position, int current_sum){

	if(current_sum==W) return 0;
	if(position==n || current_sum>W) return INF;

	//check if already calculated
	if(table[position][current_sum]!=-1) 
		return table[position][current_sum];

	//Recursive case
	int take_coin = 1 + F(position, current_sum+coin[position]);

	int dont_take = F(position+1, current_sum);

	return table[position][current_sum] = min(take_coin, dont_take);
}
int func1(int ind, int amount){
    if(amount==0)
        return 1;
    if(ind<0)
        return 0;
    if(table[ind][amount]!=-1)
        return table[ind][amount];
    
    int ways = 0;
    for(int coin_amount = 0; coin_amount<=amount; coin_amount+=coin[ind]){
        ways += func1(ind-1 , amount-coin_amount);
    }
    return table[ind][amount] = ways;
}

int main(){
    for(int i=0;i<100; i++){
        for(int j=0;j<10000; j++){
            table[i][j] = -1;
        }
    }
    cout<<"Enter number of coins: "; cin>>n;
    cout<<"Enter coins: ";
    int x;
    for(int i=0; i<n;i++){
        cin>>x;
        coin.push_back(x);
    }
    cout<<"Enter W: "; cin>>W;
    cout<<func1(n-1,W); //Number of ways
    //cout<<F(0,0);     //Number of coins needed(minimum)
}
/*
5
2 5 9 13 15
22
*/