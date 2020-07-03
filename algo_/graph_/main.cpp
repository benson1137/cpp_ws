#include <iostream>
// #include "AdjacencyListGraph.h"
#include "queue.h"

// 邻接矩阵表示图
#define MAX_SIZE 20
class AdjMatrixGraph
{
    friend void DFS(AdjMatrixGraph G, int i);
    friend void BFSTraverse(AdjMatrixGraph G);

private:
    int vertexSize;
    char vertex[MAX_SIZE];
    float edge[MAX_SIZE][MAX_SIZE];

public:
    AdjMatrixGraph() : vertexSize(0)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
                edge[i][j] = 0;
        }
    }
    ~AdjMatrixGraph() {}
    int size() const { return vertexSize; }
    void addVertex(char dt)
    {
        if (vertexSize == MAX_SIZE)
        {
            std::cout << "Full" << std::endl;
            return;
        }
        vertex[vertexSize] = dt;
        vertexSize++;
    }
    void addEdge(int from, int to, float weight = 1)
    {
        if (from < 0 || from >= vertexSize || to < 0 || to >= vertexSize)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        edge[from][to] = weight;
        // 无向图
        edge[to][from] = weight;
    }
    void deleteEdge(int from, int to)
    {
        if (from < 0 || from >= vertexSize || to < 0 || to >= vertexSize)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        edge[from][to] = 0;
        // 无向图
        edge[to][from] = 0;
    }
    void deleteVertex(int num)
    {
        if (num < 0 || num >= vertexSize)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        for (int i = 0; i < vertexSize; i++)
        {
            if (edge[num][i])
                edge[num][i] = 0;
            else if (edge[i][num])
                edge[i][num] = 0;
            else
                ;
        }
        vertexSize--;
    }
};

bool visited[MAX_SIZE];
void DFS(AdjMatrixGraph G, int i)
{
    visited[i] = true;
    std::cout << G.vertex[i] << " ";
    for (int j = 0; j < G.size(); j++)
    {
        if (G.edge[i][j] && !visited[j])
            DFS(G, j);
    }
}

void DFSTraverse(AdjMatrixGraph G)
{
    // 先初始化辅助列表
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
    }
    // 如果是连通图，只执行一次就够
    // 使用for循环的目的是解决非连通图的问题
    for (int i = 0; i < G.size(); i++)
    {
        if (!visited[i])
            DFS(G, i);
    }
}

struct Vertex
{
    int i;
    char c;
    Vertex(int i = 0, char c = ' ') : i(i), c(c) {}
    // Vertex(Vertex &v) : i(v.i), c(v.c) {}
    ~Vertex() {}
};

void BFSTraverse(AdjMatrixGraph G)
{
    Queue<Vertex> srh_que;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < G.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            std::cout << G.vertex[i] << " ";
            srh_que.enqueue(Vertex(i, G.vertex[i]));
            while (!srh_que.empty())
            {
                Vertex *getHead = new Vertex;
                srh_que.dequeue(getHead);
                i = getHead->i;
                delete getHead;
                for (int j = 0; j < G.size(); j++)
                {
                    if (G.edge[i][j] && !visited[j])
                    {
                        visited[j] = true;
                        std::cout << G.vertex[j] << " ";
                        srh_que.enqueue(Vertex(j, G.vertex[j]));
                    }
                }
            }
        }
    }
}

using namespace std;

int main(int argc, char const *argv[])
{
    AdjMatrixGraph graph;
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addVertex('F');
    graph.addVertex('G');
    graph.addVertex('H');
    graph.addVertex('I');
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 5, 11);
    graph.addEdge(1, 2, 18);
    graph.addEdge(1, 6, 12);
    graph.addEdge(1, 8, 16);
    graph.addEdge(2, 3, 22);
    graph.addEdge(2, 8, 8);
    graph.addEdge(3, 4, 20);
    graph.addEdge(3, 6, 24);
    graph.addEdge(3, 7, 16);
    graph.addEdge(3, 8, 21);
    graph.addEdge(4, 5, 26);
    graph.addEdge(4, 7, 7);
    graph.addEdge(5, 6, 17);
    graph.addEdge(6, 7, 19);

    DFSTraverse(graph);
    cout << endl;
    BFSTraverse(graph);
    return 0;
}
