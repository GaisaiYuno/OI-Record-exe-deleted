#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#include<cmath>
#define MOD 1000000007
#define ll long long
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
inline int addv(int a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
	return a;
}
int n,m,X,Y;
const double pi=acos(-1.0);
namespace p{
	ll lim,cnt,r[5000010];
	struct comp{
		double x,y;
		comp(double xx=0,double yy=0){x=xx;y=yy;}
		inline comp operator +(const comp &b){return comp(x+b.x,y+b.y);}
		inline comp operator -(const comp &b){return comp(x-b.x,y-b.y);}
		inline comp operator *(const comp &b){return comp(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[5000010],B[5000010];
	inline void fft(comp *a,int type){
		int i,j,k,len,mid;comp x,y,w,wn;
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			len=mid<<1;
			wn=comp(cos(pi/mid),type*sin(pi/mid));
			for(j=0;j<lim;j+=len){
				w=comp(1,0);
				for(k=0;k<mid;k++,w=w*wn){
					x=a[j+k];y=w*a[j+k+mid];
					a[j+k]=x+y;
					a[j+k+mid]=x-y;
				}
			}
		}
		if(type==1) return;
		for(i=0;i<lim;i++) a[i].x=(int)((a[i].x/(double)lim)+0.2);
	}
	inline void mul(int *a,int n,int *b,int m){
		if(n<=20000||m<=20000){
			ll i,j;static int re[5000010];
			for(i=0;i<=n+m;i++) re[i]=0;
			for(i=0;i<=n;i++){
				for(j=0;j<=m;j++){
					re[i+j]=addv(re[i+j],1ll*a[i]*b[j]%MOD);
				}
			}
			for(i=0;i<=n+m;i++) a[i]=re[i];
			return;
		}
		ll i;
		lim=1;cnt=0;
		while(lim<=(n+m)) lim<<=1,cnt++;
		for(i=0;i<lim;i++){
			A[i]=comp(0,0);
			B[i]=comp(0,0);
			r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		}
		for(i=0;i<=n;i++) A[i].x=a[i];
		for(i=0;i<=m;i++) B[i].x=b[i];
		fft(A,1);fft(B,1);
		for(i=0;i<lim;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(i=0;i<=n+m;i++) a[i]=int((ll)A[i].x%MOD);
	}
}
namespace t{
	int first[2010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	int vis[2010],dep[2010],st[2010][11];
	vector<int>lis[2010];int cnt,maxn;
	int p[4000010],len;
	int pson[4000010],tmplen;
	void dfs(int u,int f,int w){
		int i,v;
		dep[u]=dep[f]+w;st[u][0]=f;
		vis[u]=1;lis[cnt].push_back(u);
		for(i=1;i<=10;i++) st[u][i]=st[st[u][i-1]][i-1];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u,a[i].w);
		}
	}
	inline int getlca(int l,int r){
		int i;
		if(dep[l]>dep[r]) swap(l,r);
		for(i=10;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
		if(l==r) return l;
		for(i=10;i>=0;i--){
			if(st[l][i]!=st[r][i]){
				l=st[l][i];
				r=st[r][i];
			}
		}
		return st[l][0];
	}
	inline int getdis(int l,int r){
		return dep[l]+dep[r]-2*dep[getlca(l,r)];
	}
	int fac=1;
	void solve(){
		int i,j,k,u,v,tmp,lim;
		p[0]=1;len=0;
		for(i=1;i<=n;i++){
			if(!vis[i]){
				cnt++;
				dfs(i,0,0);
				lim=lis[cnt].size();
				tmplen=0;
				for(j=0;j<lim;j++){
					for(k=j+1;k<lim;k++){
						u=lis[cnt][j];
						v=lis[cnt][k];
						tmp=getdis(u,v);
						pson[tmp]+=2;
						tmplen=max(tmplen,tmp);
					}
				}
				/*
				cout<<"***************************************get tree "<<i<<' '<<lim<<'\n';
				cout<<"curlen "<<tmplen<<'\n';
				for(j=0;j<=tmplen;j++) cout<<pson[j]<<' ';
				cout<<'\n';
				cout<<"prelen "<<len<<'\n';
				for(j=0;j<=len;j++) cout<<p[j]<<' ';
				cout<<'\n';
				*/
				p::mul(p,len,pson,tmplen);
				len=len+tmplen;
				memset(pson,0,sizeof(int)*(tmplen+2));
			}
		}
		int ans=0;
//		for(i=0;i<=len;i++) cout<<i<<' '<<p[i]<<'\n';
		for(i=max(0,Y-X*cnt);i<=len;i++){
			ans=addv(ans,1ll*p[i]*((1ll*i+1ll*X*cnt)%MOD)%MOD);
		}
		for(i=2;i<cnt;i++) fac=1ll*i*fac%MOD;
		cout<<1ll*ans*qpow(2,MOD-2)%MOD*(ll)fac%MOD<<'\n';
	}
}
int main(){
	freopen("mooriokart.in","r",stdin);
	freopen("mooriokart.out","w",stdout); 
	n=read();m=read();X=read();Y=read();
	t::init();int i,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		t::add(t1,t2,t3);
	}
	t::solve();
}
