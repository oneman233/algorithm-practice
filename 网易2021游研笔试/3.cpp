#include <bits/stdc++.h>
#define int long long
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define nmsl cout<<"NMSL\n"
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'
#define P pair
#define mkp make_pair
#define V vector
using namespace std;
typedef priority_queue<int> mxq_i;
typedef priority_queue<int,V<int>,greater<int> > mnq_i;
typedef priority_queue<P<int,int> > mxq_p;
typedef priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > mnq_p;
int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int maxn=1e6+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int _;
string s;
set<string> st;

bool gao1() {
	int cnt=0;
	if(st.count("1W")) ++cnt;
	if(st.count("4W")) ++cnt;
	if(st.count("7W")) ++cnt;
	if(st.count("2B")) ++cnt;
	if(st.count("5B")) ++cnt;
	if(st.count("8B")) ++cnt;
	if(st.count("3T")) ++cnt;
	if(st.count("6T")) ++cnt;
	if(st.count("9T")) ++cnt;
	return cnt>=7;
}

bool gao2() {
	int cnt=0;
	if(st.count("1W")) ++cnt;
	if(st.count("4W")) ++cnt;
	if(st.count("7W")) ++cnt;
	if(st.count("2T")) ++cnt;
	if(st.count("5T")) ++cnt;
	if(st.count("8T")) ++cnt;
	if(st.count("3B")) ++cnt;
	if(st.count("6B")) ++cnt;
	if(st.count("9B")) ++cnt;
	return cnt>=7;
}

bool gao3() {
	int cnt=0;
	if(st.count("1T")) ++cnt;
	if(st.count("4T")) ++cnt;
	if(st.count("7T")) ++cnt;
	if(st.count("2W")) ++cnt;
	if(st.count("5W")) ++cnt;
	if(st.count("8W")) ++cnt;
	if(st.count("3B")) ++cnt;
	if(st.count("6B")) ++cnt;
	if(st.count("9B")) ++cnt;
	return cnt>=7;
}

bool gao4() {
	int cnt=0;
	if(st.count("1T")) ++cnt;
	if(st.count("4T")) ++cnt;
	if(st.count("7T")) ++cnt;
	if(st.count("2B")) ++cnt;
	if(st.count("5B")) ++cnt;
	if(st.count("8B")) ++cnt;
	if(st.count("3W")) ++cnt;
	if(st.count("6W")) ++cnt;
	if(st.count("9W")) ++cnt;
	return cnt>=7;
}

bool gao5() {
	int cnt=0;
	if(st.count("1B")) ++cnt;
	if(st.count("4B")) ++cnt;
	if(st.count("7B")) ++cnt;
	if(st.count("2T")) ++cnt;
	if(st.count("5T")) ++cnt;
	if(st.count("8T")) ++cnt;
	if(st.count("3W")) ++cnt;
	if(st.count("6W")) ++cnt;
	if(st.count("9W")) ++cnt;
	return cnt>=7;
}

bool gao6() {
	int cnt=0;
	if(st.count("1B")) ++cnt;
	if(st.count("4B")) ++cnt;
	if(st.count("7B")) ++cnt;
	if(st.count("2W")) ++cnt;
	if(st.count("5W")) ++cnt;
	if(st.count("8W")) ++cnt;
	if(st.count("3T")) ++cnt;
	if(st.count("6T")) ++cnt;
	if(st.count("9T")) ++cnt;
	return cnt>=7;
}

bool can() {
	if(gao1()) return 1;
	if(gao2()) return 1;
	if(gao3()) return 1;
	if(gao4()) return 1;
	if(gao5()) return 1;
	if(gao6()) return 1;
	return 0;
}

signed main() {
    FAST
	cin>>_;while(_--) {
		st.clear();
		re(i,1,7) cin>>s,st.insert(s);
		if(can()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}
