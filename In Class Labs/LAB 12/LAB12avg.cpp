#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INT_MAX


struct Vertex {
    int index;
    int DISTANCE;

    Vertex(int i, int d) : index(i), DISTANCE(d) {}
};


struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.DISTANCE > v2.DISTANCE;
    }
};


void (std::vector<std::vector<int>>& GRAPH, int source) {
    int V = GRAPH.size(); 
    std::vector<int> DISTANCEs(V, INF); 
    std::vector<bool> visited(V, false); 

    DISTANCEs[source] = 0; 


    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();


        if (visited[u])
            continue;

        visited[u] = true;


        for (int v = 0; v < V; v++) {
   
            if (!visited[v] && GRAPH[u][v] != INF &&
                DISTANCEs[u] + GRAPH[u][v] < DISTANCEs[v]) {
                DISTANCEs[v] = DISTANCEs[u] + GRAPH[u][v];
                pq.push(Vertex(v, DISTANCEs[v]));
            }
        }
    }


    int total=0;
    std::cout << "Shortest time from the Source:\n";
    
    for (int v = 0; v < V; v++) {
        total+=DISTANCEs[v];
        std::cout << "City " << v << ": " << DISTANCEs[v] << "\n";
    }
    float average= total/5.0;
    std::cout<< "Average  "<<average<< "\n";
    
}

int main() {

    std::vector<std::vector<int>> GRAPH = {
        {0, 10,INF, INF,15,5},
        {10, 0,10, 30, INF, INF},
        {INF,10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };

    int source;
    std::cout << "Enter the source city: ";
    std::cin >> source;

    (GRAPH, source);

    return 0;
}