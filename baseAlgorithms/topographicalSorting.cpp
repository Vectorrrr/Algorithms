vector<vector<int>>g;
vector<int> used;
vector<int> ans;
void dfs(int node){
	used[node]=1;
	for(int i=0;i<g[node].size();++i){
		if(used[g[node][i]]!=1){
			dfs(g[node][i]);
		}
	}
	ans.push_back(node);
} 
void print(){
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";		
	}
}

void main(){
	for(int i=0;i<g.size();++i){
		if(!used[i]){
			dfs(i);
		}
	}
	print();
}