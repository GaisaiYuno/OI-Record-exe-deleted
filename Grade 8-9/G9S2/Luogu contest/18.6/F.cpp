#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	srand(time(NULL));
	ll x=rand()%10000;
	cout<<x*x<<' '<<rand()%10000<<'\n';
}
