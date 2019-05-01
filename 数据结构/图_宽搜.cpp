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

void DFS_graph(GraphNote *node, int visit[])
{
    queue <GraphNote*> q;
    q.push(node);
    visit[node->label] = 1;
    while (!q.empty())
    {
        GraphNote* temp = q.front();
        q.pop();
        cout << temp->label;    
        for (int i = 0; i < temp -> neighbors.size(); ++i)
            if(visit[temp->neighbors[i]->label] == 0 ) 
            {
                q.push(temp->neighbors[i]);
                visit[temp->neighbors[i]->label] = 1;
            }
                

    }
}

int main()
{
    const int MAX_N = 5;
    GraphNote* Graph[MAX_N];
    for (int i = 0; i < MAX_N; ++i) Graph[i] = new GraphNote(i);
    Graph[0] -> neighbors.push_back(Graph[2]);
    Graph[0] -> neighbors.push_back(Graph[4]);
    Graph[1] -> neighbors.push_back(Graph[0]);
    Graph[1] -> neighbors.push_back(Graph[2]);
    Graph[2] -> neighbors.push_back(Graph[3]);
    Graph[3] -> neighbors.push_back(Graph[4]);
    Graph[4] -> neighbors.push_back(Graph[3]);
    int visit[MAX_N] = {0};
    for (int i = 0; i < MAX_N; ++i)
    {
        if(visit[i] == 0)
        {
            cout << "from the label[" << Graph[i] -> label << "]: ";
            DFS_graph(Graph[i],visit);
            cout << endl;
        }  
    }
    for (int i = 0; i < MAX_N; ++i) delete Graph[i];
    return 0;
}