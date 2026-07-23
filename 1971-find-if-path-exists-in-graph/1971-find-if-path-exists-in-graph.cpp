// class Solution {
// public:

//     // DFS Function
//     bool dfs(int node, int destination,
//              vector<vector<int>>& graph,
//              vector<bool>& visited)
//     {
//         // If current node is destination, path found
//         if (node == destination)
//             return true;

//         // Mark current node as visited
//         visited[node] = true;

//         // Visit all neighbours of current node
//         for (int neighbour : graph[node])
//         {
//             // Visit only if neighbour is not visited
//             if (!visited[neighbour])
//             {
//                 // Continue DFS from neighbour
//                 if (dfs(neighbour, destination, graph, visited))
//                     return true;    // Destination found
//             }
//         }

//         // Destination not found from this path
//         return false;
//     }

//     bool validPath(int n,
//                    vector<vector<int>>& edges,
//                    int source,
//                    int destination)
//     {
//         // Create adjacency list
//         vector<vector<int>> graph(n);

//         /*
//         Example:
//         edges = {{0,1},{1,2}}

//         After building graph:

//         0 -> [1]
//         1 -> [0,2]
//         2 -> [1]
//         */

//         // Build graph
//         for (auto edge : edges)
//         {
//             int u = edge[0];
//             int v = edge[1];

//             graph[u].push_back(v);   // u -> v
//             graph[v].push_back(u);   // v -> u (Undirected Graph)
//         }

//         // Initially every node is unvisited
//         vector<bool> visited(n, false);

//         /*
//         Dry Run

//         source = 0
//         destination = 2

//         visited = [F F F]

//         dfs(0)
//         visited = [T F F]

//              ↓

//         dfs(1)
//         visited = [T T F]

//              ↓

//         dfs(2)

//         node == destination

//         return true

//              ↑
//         dfs(1)

//              ↑
//         dfs(0)

//              ↑
//         Answer = true
//         */

//         // Start DFS from source node
//         return dfs(source, destination, graph, visited);
//     }
// };

class Solution {
public:
    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination)
    {
        // Create adjacency list
        vector<vector<int>> graph(n);

        // Build graph
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u); // Undirected graph
        }

        // Queue for BFS
        queue<int> q;

        // Initially every node is unvisited
        vector<bool> visited(n, false);

        // Start from source
        q.push(source);
        visited[source] = true;

        /*
        Dry Run

        Graph

        0 -- 1 -- 2

        Queue

        [0]

        visited

        T F F
        */

        while (!q.empty())
        {
            // Take front node
            int node = q.front();
            q.pop();

            // Destination found
            if (node == destination)
                return true;

            // Visit all neighbours
            for (int neighbour : graph[node])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }

            /*
            Queue Flow

            pop 0

            push 1

            Queue = [1]

            pop 1

            push 2

            Queue = [2]

            pop 2

            destination found
            */
        }

        // Destination not found
        return false;
    }
};