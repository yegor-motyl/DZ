#include <iostream>
#include <queue>
#include <vector>

int MAXSIZE = 100;

int main()
{
    int size;
    int start, end;
    std::cin >> size;
    std::vector<int> from(size, -1);
    std::vector<int> used(size, 0);
    std::vector<int> way(size);
    int MATRIX[MAXSIZE][MAXSIZE];
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            std::cin >> MATRIX[i][j];
        }
    }
    std::cin >> start >> end;
    --start; --end;
    std::queue<int> que;
    que.push(start);
    way[start] = 0;
    used[start] = 1;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        for (int i = 0; i < size; ++i)
        {
            if (MATRIX[temp][i] && !used[i])
            {
                way[i] = way[temp] + 1;
                from[i] = temp;
                que.push(i);
                used[i] = true;
            }
        }
        
    }
    if (used[end])
        std::cout << "Кратчайший путь = " << way[end];
    else
        std::cout << "Кратчайшего пути не существует";
    return 0;
}
