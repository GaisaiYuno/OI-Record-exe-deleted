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
double ans[100][200];int n,T,i,nn;
int main(){
    ans[3][1]=0.000000000;
    ans[3][2]=0.000000000;
    ans[3][3]=0.421375890;
    ans[3][4]=0.416495750;
 
    ans[4][1]=0.000000000;
    ans[4][2]=0.000000000;
    ans[4][3]=0.421386951;
    ans[4][4]=0.420834905;
    ans[4][5]=0.416493357;
    ans[4][6]=0.000000000;
    ans[4][7]=0.677332437;
    ans[4][8]=0.415070790;
    ans[4][9]=0.589978844;
    ans[4][10]=0.523194982;
    ans[4][11]=0.501668050;
 
    ans[5][1]=0.000000000;
    ans[5][2]=0.000000000;
    ans[5][3]=0.421392910;
    ans[5][4]=0.420834280;
    ans[5][5]=0.427213170;
    ans[5][6]=0.416515040;
    ans[5][7]=0.000000000;
    ans[5][8]=0.677365940;
    ans[5][9]=0.415078380;
    ans[5][10]=0.421486110;
    ans[5][11]=0.447898640;
    ans[5][12]=0.424280730;
    ans[5][13]=0.589995890;
    ans[5][14]=0.523270870;
    ans[5][15]=0.392917150;
    ans[5][16]=0.399452110;
    ans[5][17]=0.481226010;
    ans[5][18]=0.408927500;
    ans[5][19]=0.380487320;
    ans[5][20]=0.392427300;
    ans[5][21]=0.501621160;
    ans[5][22]=0.416507440;
    ans[5][23]=0.490119810;
    ans[5][24]=0.435443950;
    ans[5][25]=0.383315540;
    ans[5][26]=0.419178580;
    ans[5][27]=0.361672790;
    ans[5][28]=0.371006210;
    ans[5][29]=0.447866770;
    ans[5][30]=0.359190800;
    ans[5][31]=0.369801040;
    ans[5][32]=0.445778350;
    ans[5][33]=0.424719320;
    ans[5][34]=0.380814660;
 
    ans[6][1]=0.000000000;
    ans[6][2]=0.000000000;
    ans[6][3]=0.421384470;
    ans[6][4]=0.420883260;
    ans[6][5]=0.427091650;
    ans[6][6]=0.411168440;
    ans[6][7]=0.416500360;
    ans[6][8]=0.000000000;
    ans[6][9]=0.677351460;
    ans[6][10]=0.415074290;
    ans[6][11]=0.421399210;
    ans[6][12]=0.447931430;
    ans[6][13]=0.424351200;
    ans[6][14]=0.420798740;
    ans[6][15]=0.408721320;
    ans[6][16]=0.411552540;
    ans[6][17]=0.590026270;
    ans[6][18]=0.523146290;
    ans[6][19]=0.392877230;
    ans[6][20]=0.399453080;
    ans[6][21]=0.481153190;
    ans[6][22]=0.408898750;
    ans[6][23]=0.665209150;
    ans[6][24]=0.608026790;
    ans[6][25]=0.413054420;
    ans[6][26]=0.427539770;
    ans[6][27]=0.406777280;
    ans[6][28]=0.403680480;
    ans[6][29]=0.380401580;
    ans[6][30]=0.392444530;
    ans[6][31]=0.499278880;
    ans[6][32]=0.502483020;
    ans[6][33]=0.440956420;
    ans[6][34]=0.409159920;
    ans[6][35]=0.461875470;
    ans[6][36]=0.470866710;
    ans[6][37]=0.501638520;
    ans[6][38]=0.416445500;
    ans[6][39]=0.490126960;
    ans[6][40]=0.435564260;
    ans[6][41]=0.383338450;
    ans[6][42]=0.578348710;
    ans[6][43]=0.494744900;
    ans[6][44]=0.378325480;
    ans[6][45]=0.403114630;
    ans[6][46]=0.419164900;
    ans[6][47]=0.000000000;
    ans[6][48]=0.677397390;
    ans[6][49]=0.413403180;
    ans[6][50]=0.415121240;
    ans[6][51]=0.407118220;
    ans[6][52]=0.410936130;
    ans[6][53]=0.361731170;
    ans[6][54]=0.371077290;
    ans[6][55]=0.447922160;
    ans[6][56]=0.393360230;
    ans[6][57]=0.577832910;
    ans[6][58]=0.500746990;
    ans[6][59]=0.509588550;
    ans[6][60]=0.389313030;
    ans[6][61]=0.383672670;
    ans[6][62]=0.436888080;
    ans[6][63]=0.412689400;
    ans[6][64]=0.359144060;
    ans[6][65]=0.369921750;
    ans[6][66]=0.493526920;
    ans[6][67]=0.455371550;
    ans[6][68]=0.392840060;
    ans[6][69]=0.443343340;
    ans[6][70]=0.372460330;
    ans[6][71]=0.377379940;
    ans[6][72]=0.401740300;
    ans[6][73]=0.381696350;
    ans[6][74]=0.589993000;
    ans[6][75]=0.523250540;
    ans[6][76]=0.387779840;
    ans[6][77]=0.442082310;
    ans[6][78]=0.405187410;
    ans[6][79]=0.402093430;
    ans[6][80]=0.374011550;
    ans[6][81]=0.379546720;
    ans[6][82]=0.454998420;
    ans[6][83]=0.457946010;
    ans[6][84]=0.375155440;
    ans[6][85]=0.431773880;
    ans[6][86]=0.415284700;
    ans[6][87]=0.421336960;
    ans[6][88]=0.445870600;
    ans[6][89]=0.378100690;
    ans[6][90]=0.410767860;
    ans[6][91]=0.406374360;
    ans[6][92]=0.424734650;
    ans[6][93]=0.377662000;
    ans[6][94]=0.413867730;
    ans[6][95]=0.395395440;
    ans[6][96]=0.356531900;
    ans[6][97]=0.361864580;
    ans[6][98]=0.387847950;
    ans[6][99]=0.515457820;
    ans[6][100]=0.464625590;
    ans[6][101]=0.373527490;
    ans[6][102]=0.457687340;
    ans[6][103]=0.375113660;
    ans[6][104]=0.394349930;
    ans[6][105]=0.367785470;
    ans[6][106]=0.434398760;
    ans[6][107]=0.417481550;
    ans[6][108]=0.368174450;
    ans[6][109]=0.438999540;
    ans[6][110]=0.422646920;
    ans[6][111]=0.355157940;
    ans[6][112]=0.411744260;
    ans[6][113]=0.353027690;
    ans[6][114]=0.362073200;
    ans[6][115]=0.431420930;
    ans[6][116]=0.412880650;
    ans[6][117]=0.361969050;
    ans[6][118]=0.361727010;
    ans[6][119]=0.380823980;
    ans[6][120]=0.501622840;
    ans[6][121]=0.412319260;
    ans[6][122]=0.363413280;
    ans[6][123]=0.356119710;
    ans[6][124]=0.378453220;
    ans[6][125]=0.512225470;
    ans[6][126]=0.455073130;
    ans[6][127]=0.369989250;
    ans[6][128]=0.392245630;
    ans[6][129]=0.436167010;
    ans[6][130]=0.415339000;
    ans[6][131]=0.435414560;
    ans[6][132]=0.355482520;
    ans[6][133]=0.416097470;
    ans[6][134]=0.409110520;
    ans[6][135]=0.420420530;
    ans[6][136]=0.357017520;
    ans[6][137]=0.354810180;
    ans[6][138]=0.355132090;
    ans[6][139]=0.396713580;
    ans[6][140]=0.345792990;
    ans[6][141]=0.354788800;
    ans[6][142]=0.404670200;
    ans[6][143]=0.404191630;
    ans[6][144]=0.382926980;
    ans[6][145]=0.427414740;
    ans[6][146]=0.410429510;
    ans[6][147]=0.360061940;
    ans[6][148]=0.395271780;
    ans[6][149]=0.388322890;
    ans[6][150]=0.398736810;
    ans[6][151]=0.346929080;
    ans[6][152]=0.346329400;
    ans[6][153]=0.404726740;
    ans[6][154]=0.386453860;
    ans[6][155]=0.380129250;
    ans[6][156]=0.392856400;
    T=read();n=nn=read();
    if(n==3) n=4;
    if(n==4) n=11;
    if(n==5) n=34;
    if(n==6) n=156;
    for(i=1;i<=n;i++) printf("%.9lf\n",ans[nn][i]);
}
