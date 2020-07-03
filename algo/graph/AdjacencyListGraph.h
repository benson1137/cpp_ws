#ifndef _ADJACENCY_LIST_GRAPH_H_
#define _ADJACENCY_LIST_GRAPH_H_

// 邻接表表示图

#include <iostream>

#ifndef MAX_SIZE
#define MAX_SIZE 20
#endif

class AdjListGraph;
class EdgeNode;
class VertexNode
{
    friend class AdjListGraph;

private:
    char data;
    EdgeNode *ptr;

public:
    VertexNode(char c = '#') : data(c), ptr(nullptr) {}
    ~VertexNode() {}
};

class EdgeNode
{
    friend class AdjListGraph;

private:
    int node;
    EdgeNode *ptr;

public:
    EdgeNode(int n) : node(n), ptr(nullptr) {}
    ~EdgeNode() {}
};

class AdjListGraph
{
private:
    VertexNode nodeList[MAX_SIZE];
    int vertexSize;
    // 从头部insert

public:
    AdjListGraph() : vertexSize(0) {}
    ~AdjListGraph() {}
    int size() const { return vertexSize; }
    void addVertex(char c)
    {
        nodeList[vertexSize].data = c;
        vertexSize++;
    }
    void addEdge(int from, int to)
    {
        if (from < 0 || from >= vertexSize || to < 0 || to >= vertexSize)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        // 从头部插入边节点
        EdgeNode *ed = new EdgeNode(to);
        ed->ptr = nodeList[from].ptr;
        nodeList[from].ptr = ed;
        vertexSize++;
    }
    void deleteEdge(int from, int to)
    {
        if (from < 0 || from >= vertexSize || to < 0 || to >= vertexSize)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        for (EdgeNode *it = nodeList[from].ptr; it->ptr != nullptr; it = it->ptr)
        {
            if (it->ptr->node == to)
            {
                EdgeNode *tmp = it->ptr;
                it->ptr = tmp->ptr;
                delete tmp;
            }
        }
        // 最后判断头节点
        if (nodeList[from].data == to)
        {
            EdgeNode *tmp = nodeList[from].ptr;
            nodeList[from].ptr = tmp->ptr;
            delete tmp;
        }
    }
    void deleteNode()
    {
    }
};

#endif