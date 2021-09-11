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
#define V vector
using namespace std;
typedef priority_queue<int> mxq_i;
typedef priority_queue<int,V<int>,greater<int> > mnq_i;
typedef priority_queue<P<int,int> > mxq_p;
typedef priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > mnq_p;
int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int maxn=1000005;
const int inf=0x3f3f3f3f3f3f3f3f;

int _,n;
V<string> mp[15];
map<int,string> res;

void ask(V<int> v) {
	cout<<"MIX"<<endl,cout.flush();
	cout<<v.size()<<endl,cout.flush();
	for(auto i:v)
		cout<<i<<endl,cout.flush();
}

void read(int sum,int id) {
	string s;
	while(sum--)
		cin>>s,mp[id].pub(s);
}

void cal() {
	re(i,1,n) {
		map<string,int> cnt;
		int flg=0;
		re(j,0,9)
			if(i&(1<<j)) {
				++flg;
				for(auto k:mp[j])
					cnt[k]++;
			}
			else
				for(auto k:mp[j])
					cnt[k]--;
		for(auto j:cnt)
			if(j.S==flg) {
				res[i]=j.F;
				break;
			}
	}
}

void ans() {
	cout<<"ANSWER"<<endl,cout.flush();
	re(i,1,n)
		cout<<res[i]<<endl,cout.flush();
}

void gao() {
	cin>>n;
	re(i,0,9) mp[i].clear();
	res.clear();
	re(i,0,9) {
		V<int> v;
		re(j,1,n)
			if(j&(1<<i))
				v.pub(j);
		if(v.size()!=0)
			ask(v),
			read(v.size(),i);
	}
	cal();
	ans();
	int useless;cin>>useless;
	assert(useless==1);
}

void gao2() {
	cin>>n;
	re(i,1,n) {
		cout<<"MIX"<<endl,cout.flush();
		cout<<1<<endl,cout.flush();
		cout<<i<<endl,cout.flush();
		string s;
		cin>>s;
		res[i]=s;
	}
	cout<<"ANSWER"<<endl,cout.flush();
	re(i,1,n) cout<<res[i]<<endl,cout.flush();
	int useless;cin>>useless;
	assert(useless==1);
}

signed main() {
    FAST
	cin>>_;
	while(_--)
		gao();
//		gao2();
    return 0;
}
