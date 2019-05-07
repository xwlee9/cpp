#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphNote
{
    int label;
    vector<GraphNote*> neighbors;
    GraphNote(int x): label(x) {};
};

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
//     {
//         vector<GraphNote*> graph;
//         vector<int> visit;
//         for (int i = 0; i < numCourses; ++i)  // 为每门课申请空间
//         {
//             graph.push_back(new GraphNote(i));
//             visit.push_back(-1);
//         }
//         for (int i = 0; i < prerequisites.size(); ++i)  // 把每门课创建连接
//         {
//             GraphNote* begin = graph[prerequisites[i][1]];
//             GraphNote* end = graph[prerequisites[i][0]];
//             begin -> neighbors.push_back(end);
//         }
//         for (int i = 0; i < graph.size(); ++i) 
//             if (visit[i] == -1 && !DFS_graph(graph[i], visit)) return false;
//         for (int i = 0; i < numCourses; ++i) delete graph[i];
//         return true;
//     } 
// private:
//     bool DFS_graph(GraphNote* node, vector<int>& visit)
//     {
//         visit[node->label] = 0;
//         for (int i = 0; i < node->neighbors.size(); ++i)
//         {
//             if(visit[node->neighbors[i]->label] == -1) // 如果没有遍历过
//             {
//                 if(DFS_graph(node->neighbors[i], visit) == 0) return false;
//             }
//             else if (visit[node->neighbors[i]->label] == 0) return false;
//         }
//         visit[node->label] = 1;  // 标记已经遍历完后的
//         return true;
//     }
// };


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
    {
        vector<GraphNote*> graph;
        vector<int> degree;

        for (int i = 0; i < numCourses; ++i)
        {
            graph.push_back(new GraphNote(i));
            degree.push_back(0);  // 这个定义有本门课程前需要多少门课程
        }
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            GraphNote* begin = graph[prerequisites[i][1]];
            GraphNote* end   = graph[prerequisites[i][0]];
            begin -> neighbors.push_back(end);
            degree[end->label] ++;
        }
        queue<GraphNote*> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if(degree[i] == 0)  q.push(graph[i]);
        }
        while (!q.empty())
        {
            GraphNote* node = q.front();
            q.pop();
            for (int i = 0; i < node->neighbors.size(); ++i)
            {
                degree[node->neighbors[i]->label] --;
                if (degree[node->neighbors[i]->label] == 0) q.push(node->neighbors[i]);
            }
        }
        for (int i = 0; i < numCourses; ++i)    delete graph[i];
        for (int i = 0; i < numCourses; ++i)
        {
            if (degree[i]) return false;
        }
        return true;    
    }
};