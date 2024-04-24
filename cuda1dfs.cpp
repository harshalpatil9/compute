//%%writefile breadthfirst.cu
#include 
#include 
#include 
#include 

using namespace std;

int main() {
    int num_vertices, num_edges, source;
    cout << "Enter number of vertices, edges, and source node: ";
    cin >> num_vertices >> num_edges >> source;

    // Input validation
    if (source < 1 || source > num_vertices) {
        cout << "Invalid source node!" << endl;
        return 1;
    }

    vector> adj_list(num_vertices + 1);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        // Input validation for edges
        if (u < 1 || u > num_vertices || v < 1 || v > num_vertices) {
            cout << "Invalid edge: " << u << " " << v << endl;
            return 1;
        }
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    queue q;
    vector visited(num_vertices + 1, false);
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex << " ";

        // Sequential loop for neighbors
        for (int i = 0; i < adj_list[curr_vertex].size(); i++) {
            int neighbour = adj_list[curr_vertex][i];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
    return 0;
}
//Writing breadthfirst.cu

//!nvcc breadthfirst.cu -o breadthfirst
//!./breadthfirst
%%writefile depthfirst.cu
#include 
#include 
using namespace std;
const int MAXN = 1e5;
vector adj[MAXN+5]; // adjacency list
bool visited[MAXN+5]; // mark visited nodes

void dfs(int node) {
    visited[node] = true;
    cout << node << " "; // Print the visited node here
    for (int i = 0; i < adj[node].size(); i++) {
        int next_node = adj[node][i];
        if (!visited[next_node]) {
            dfs(next_node);
        }
    }
}

int main() {
    cout << "Please enter nodes and edges: ";
    int n, m; // number of nodes and edges
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; // edge between u and v
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start_node; // start node of DFS
    cout << "Enter the start node for DFS: ";
    cin >> start_node;
    dfs(start_node);
    cout << endl; // Print a newline after DFS traversal
    return 0;
}
     
//Overwriting depthfirst.cu

//!nvcc depthfirst.cu -o depthfirst
//!./depthfirst
     
