#include <iostream>
#include <vector>
#include <stack>

int start;
std::vector <std::vector<int>> edges;
std::vector <int> mark;

void DFS()
{
    stack<int> gr;
    gr.push(start);
    while (!gr.empty())
    {
        int v = gr.top();
        gr.pop();
        for (int i = 0; i < edges[v].size(); ++i)
        {
            if (mark[edges[v][i]] == 0)
            {
                gr.push(edges[v][i]);
                mark[edges[v][i]] = 1;
            }
        }
    }
}