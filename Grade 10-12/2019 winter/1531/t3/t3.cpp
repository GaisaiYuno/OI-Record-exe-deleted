#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int mat[4][4][5][5]={
{
{
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
},
{
{1,24,7,4,25},
{9,16,21,10,15},
{19,5,13,18,6},
{2,23,8,3,22},
{12,17,20,11,14}
},
{
{1,11,20,4,12},
{22,16,8,23,15},
{19,5,13,18,6},
{2,10,21,3,9},
{25,17,7,24,14}
},
{
{1,15,7,4,14},
{9,23,18,10,24},
{20,5,13,21,6},
{2,16,8,3,17},
{12,22,19,11,25}
}
},
{
{
{25,4,7,24,1},
{15,10,21,16,9},
{6,18,13,5,19},
{22,3,8,23,2},
{14,11,20,17,12}
},
{
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
},
{
{12,4,19,11,1},
{24,16,8,23,17},
{6,21,13,5,20},
{9,3,18,10,2},
{25,15,7,22,14}
},
{
{12,4,20,11,1},
{15,23,8,16,22},
{6,18,13,5,19},
{9,3,21,10,2},
{14,24,7,17,25}
}
},
{
{
{25,15,6,22,14},
{4,10,18,3,11},
{7,21,13,8,20},
{24,16,5,23,17},
{1,9,19,2,12}
},
{
{12,24,6,9,25},
{4,16,21,3,15},
{19,8,13,18,7},
{11,23,5,10,22},
{1,17,20,2,14}
},
{
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
},
{
{12,15,6,9,14},
{4,23,18,3,24},
{20,8,13,21,7},
{11,16,5,10,17},
{1,22,19,2,25}
}
},
{
{
{25,11,19,22,12},
{17,3,8,16,2},
{6,21,13,5,20},
{24,10,18,23,9},
{14,4,7,15,1}
},
{
{14,24,7,17,25},
{9,3,21,10,2},
{6,18,13,5,19},
{15,23,8,16,22},
{12,4,20,11,1}
},
{
{14,11,20,17,12},
{22,3,8,23,2},
{6,18,13,5,19},
{15,10,21,16,9},
{25,4,7,24,1}
},
{
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
}
}
};
/*
odd number of fives(15,25)
even number of fives(10,20)
(1,1)-(1,5) for going right
(1,1)-(5,5) for the right-to-down corner
(1,5)-(5,5) for the rightmost line
(1,5)-(5,1) for the down-to-left corner
(5,5)-(1,1) for the left-to-up corner
(5,1)-(1,1) for uping
(1,5)-(5,5) for downing
*/
int ans[1010][1010];
inline void fill(int x,int y,int p,int q,int cur){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			ans[(x-1)*5+i][(y-1)*5+j]=mat[p][q][i][j]+25*cur;
		}
	}
}
int main(){
	int n=read(),i,j,x,y,tx,ty,k,kk,cur,tmp;
	if(n==5){
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				cout<<mat[0][1][i][j]<<' ';
			}
			cout<<'\n';
		}
		return 0;
	}
	if(n==10){
		return 0;
	}
	if(n&1){
		//odd ones, ending left-down corner
		n/=5;
		x=1;y=1;cur=0;
		for(k=1;k<n;k++){//phase one
			fill(x,y,0,1,cur);
			y++;cur++;
		}
		fill(x,y,0,3,cur);
		x++;cur++;
		for(k=2;k<n;k++){
			fill(x,y,1,3,cur);
			x++;cur++;
		}
		fill(x,y,1,2,cur);
		y--;cur++;
		for(kk=n/2;kk>0;kk--){
			fill(x,y,3,0,cur);
			x--;cur++;
			for(k=2;k<n-1;k++){
				fill(x,y,2,0,cur);
				x--;cur++;
			}
			fill(x,y,2,0,cur);
			y--;cur++;
			for(k=2;k<n;k++){
				fill(x,y,1,3,cur);
				x++;cur++;
			}
			fill(x,y,1,2,cur);
			y--;cur++;
		}
		for(i=0;i<n*5;i++){
			for(j=0;j<n*5;j++){
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
	}
}
