#include <iostream>
#include <string.h>

#define X 100

bool bpm(bool Graph[X][X], int u, bool seen[], int match[])
{
    for (int v = 0; v < X; v++)
    {
        if (Graph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (match[v] < 0 || bpm(Graph, match[v], seen, match))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(bool Graph[X][X])
{
    int match[X];
    memset(match, -1, sizeof(match));
    int result = 0;
    for (int u = 0; u < X; u++)
    {
        bool seen[X];
        memset(seen, 0, sizeof(seen));
        if (bpm(Graph, u, seen, match))
            result++;
    }
    return result;
}
int main()
{
    bool Graph[X][X];
    for(int i=0; i<X; i++){
        for(int j=0; j<X;j++){
            std::cin >> Graph[i][j]; 
        }
    }
    std::cout << "Максимальное паросочетание: " << maxBPM(Graph);
    return 0;
}
