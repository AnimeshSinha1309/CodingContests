#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

class DirectedGraph {
   public:
    struct Node {
        vector<Node*> out_edges, in_edges;
        int index = -1;
        int __topo_indegree = 0, __topo_index = -1;
    };
    vector<Node> graph;
    DirectedGraph(int n) {
        graph = vector<Node>(n);
        for (int i = 0; i < this->graph.size(); i++) {
            this->graph[i].index = i;
        }
    }
    void add_edge(int u, int v) {
        assert(u < graph.size() && v < graph.size());
        graph[u].out_edges.push_back(&graph[v]);
        graph[v].in_edges.push_back(&graph[u]);
    }
    vector<ll> toposort() {
        // Marking in-degree and index, preparing the queue
        queue<ll> process;
        for (int i = 0; i < this->graph.size(); i++) {
            this->graph[i].__topo_indegree = this->graph[i].in_edges.size();
        }
        for (auto node : this->graph)
            if (node.__topo_indegree == 0)
                process.push(node.index);
        // Processing the queue and preparing toposorted index list
        vector<long long> toposort;
        while (!process.empty()) {
            ll node = process.front();
            process.pop();
            toposort.push_back(node);
            for (auto neighbor : this->graph[node].out_edges) {
                neighbor->__topo_indegree--;
                if (neighbor->__topo_indegree == 0)
                    process.push(neighbor->index);
            }
        }
        // Marking the topo order and returning
        for (int i = 0; i < this->graph.size(); i++)
            this->graph[toposort[i]].__topo_index = i;
        return toposort;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DirectedGraph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u - 1, v - 1);
    }
    auto toposort = g.toposort();
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++) {
        for (DirectedGraph::Node* prev : g.graph[toposort[i]].in_edges) {
            dp[i] = max(dp[i], dp[prev->__topo_index] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}