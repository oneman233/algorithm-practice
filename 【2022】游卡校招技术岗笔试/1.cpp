class Solution {
public:
	map<char,int> mp;
	
	bool ok() {
		for(auto i:mp) {
			if(i.second>1) return 1;
		}
		return 0;
	}
	
    int numKLenSubstrRepeats(string s, int k) {
        int ans=0;
        for(int i=0;i<k;++i)
        	mp[s[i]]++;
        for(int i=k;i<s.length();++i) {
			if(ok()) ++ans;
			mp[s[i]]++;
			mp[s[i-k]]--;
		}
		if(ok()) ++ans;
        return ans;
    }
};
