vector<vector<int>>g;
vector<vector<int>>trG;
vector<int> ans;
vector<int> used;
vector<int> temp;
int n;

void dfs1(int node){
	used[node]=1;
	for(int i=0;i<g[node].size();++i){
		if(used[g[node][i]]!=1){
			dfs1(g[node][i]);
		}
	}
	ans.push_back(node);
}

void dfs2(int node){
	used[node]=1;
	for(int i=0;i<trG[node].size();++i){
		if(used[i]!=1){
			dfs2(trG[node][i]);
		}
	}
	ans.push_back(i);
	
}
void main(){
	used.assign(n,0);
	for(int i=0;i<n;i++){
		if(used[i]!=1){
			dfs1(i);
		}
	}
	used.assign(n,0);
	for(int i=ans.size()-1;i>=0;--i){
		if(used[ans[i]]!=1){
			dfs2(ans[i]);
		}
		for(int j=0;j<temp;++j){
			cout<<temp[i]<<" ";
		}
		temp.clear();
	}
}