#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

int n;
int m;
std::vector<int> *some;
std::vector<bool> used;
std::queue<int> q;
void bfs(int v) {
    if (used[v]) {
        return;
 }
   q.push(v);
   used[v] = true;
   while (!q.empty()) {
       v = q.front();
       q.pop();
       printf("%d ", (v + 1));
               for (int i = 0; i < some[v].size(); ++i) {
           int w = some[v][i];
                       if (used[w]) {
               continue;
           }
           q.push(w);
           used[w] = true;
    }
   }
}
void read() {
    scanf("%d %d", &n, &m);
    some = new std::vector<int>[n];
    for (int i = 0; i < m; ++i) {
        int v, w;
        scanf("%d %d", &v, &w);
        v--;
        w--;
        some[v].push_back(w);
    }
       used.resize(n, false);
}
void run() {
    read();
    for (int v = 0; v < n; ++v) {
        bfs(v);
    }
      for (int i = 0; i < n; ++i) {
        some[i].clear();
    }
    used.clear();
}
 
int main()
{
    std::ifstream in("input.txt");
    if (in.is_open())
    {
        int count = 0;
        int temp;
        while (!in.eof())
        {
            in >> temp;
            count++;
        }
        in.seekg(0, std::ios::beg);
        in.clear();
        int space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') {
                space++;
            }
            if (symbol == '\n') {
                break;
            }
        }
        in.seekg(0, std::ios::beg);
        in.clear();
        int n = count / (space + 1);
        int m = space + 1;
        double **g;
        g = new double*[n];
        for (int i = 0; i<n; i++)
        {
            g[i] = new double[m];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> g[i][j];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
               std::cout << g[i][j] << "\t";
            std::cout << "\n";
        }
        std::ofstream fout("output.txt");
        for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < m; j++)
        fout << g[i][j]<<"\t";
        fout << "\n";
        }
        fout.close();
        for (int i = 0; i<n; i++){
            delete[] g[i];
        }
        delete[] g;
        in.close();
    }
    return 0;
}
