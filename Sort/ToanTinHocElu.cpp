#include<iostream>
#include<vector>
#define NODE 5
using namespace std;
/*int graph[NODE][NODE] = {{0, 1, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {0, 0, 0, 1, 0}};*/ //No Euler circuit, but euler path is present
int graph[NODE][NODE] = { {0, 1, 1, 1, 1},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {1, 0, 0, 1, 0} }; //uncomment to check Euler Circuit as well as path
/*int graph[NODE][NODE] = {{0, 1, 1, 1, 0},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 0, 0},
   {1, 1, 0, 0, 1},
   {0, 0, 0, 1, 0}};*/ //Uncomment to check Non Eulerian Graph
void traverse(int u, bool visited[]) {
    visited[u] = true; //mark v as visited
    for (int v = 0; v < NODE; v++) {
        if (graph[u][v]) {
            if (!visited[v]) traverse(v, visited);
        }
    }
}
bool isConnected() {
    bool* vis = new bool[NODE];
    //for all vertex u as start point, check whether all nodes are visible or not
    for (int u = 0; u < NODE; u++) {
        for (int i = 0; i < NODE; i++)
            vis[i] = false; //initialize as no node is visited
        traverse(u, vis);
        for (int i = 0; i < NODE; i++) {
            if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}
int hasEulerianCircuit() {
    if (isConnected() == false) //when graph is not connected
        return 0;
    vector<int> degree(NODE, 0);
    int oddDegree = 0;
    for (int i = 0; i < NODE; i++) {
        for (int j = 0; j < NODE; j++) {
            if (graph[i][j])
                degree[i]++; //increase degree, when connected edge found
        }
        if (degree[i] % 2 != 0) //when degree of vertices are odd
            oddDegree++; //count odd degree vertices
    }
    if (oddDegree == 0) { //when oddDegree is 0, it is Euler circuit
        return 1;
    }
    return 0;
}
int main() {
    if (hasEulerianCircuit()) {
        cout << "The graph has Eulerian Circuit." << endl;
    }
    else {
        cout << "The graph has No Eulerian Circuit." << endl;
    }
}