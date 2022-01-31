#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

std::vector < std::vector<int> > mainGR, inverGR;
std::vector<char> used;
std::vector<int> order, comp;
 
void dfs_1 (int v) {
	used[v] = true;
	for (size_t i=0; i<mainGR[v].size(); ++i)
		if (!used[ mainGR[v][i] ]){
			dfs_1 (mainGR[v][i]);
        }
	order.push_back (v);
}
 
void dfs_2 (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<inverGR[v].size(); ++i)
		if (!used[ inverGR[v][i] ])
			dfs_2 (inverGR[v][i]);
}
 
int main() {
	int n;
    std::cin >> n;
	for (int i = 0;i < 0;i++) {
		int a, b;
		mainGR[a].push_back (b);
		inverGR[b].push_back (a);
	}
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs_1(i);
	used.assign (n, false);
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs_2(v);
            std::cout << comp[i];
			comp.clear();
		}
	}
    return 0;
}
