#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
const double pi=acos(-1.0),loge=log(exp(1));
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	ll n,k;
	while(~scanf("%lld%lld",&n,&k)){
		const double logk=log(k);
		ll ans=(ll)(log(2.0*pi*n)/logk*0.5+log(n)/logk*n-loge/logk*n)+1ll;
		printf("%lld\n",ans);
	}
}
