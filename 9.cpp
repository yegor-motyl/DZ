#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1000 

int n;
std::vector<int> g[MAX];
bool used[MAX];
vector<int> comp;
 
void dfs (int v){
	used[v]=true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
}
 
void findComps(){
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
			std::cout << comp.size();
		}
}

int main(){
    int v,e;
    std::cin >> v >> e;
    for (int i=0; i<e; i+=2){
        int temp1,temp2;
        std::cin >> temp1 >> temp2 << '\n';
        g[i]=temp1;
        g[i+1]=temp2;
    }
    findComps();
    return 0;
}