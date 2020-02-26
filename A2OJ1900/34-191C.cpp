#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree {
public:
    struct Node {
        Node* parent = nullptr;
        vector<Node*> adjacent;
    };
    vector<Node> graph;
    Node* root;

    void setRoot(Node* root) {
        for (auto child : root->adjacent) {
            if (child->parent != nullptr) continue;
            child->parent = root;
            setRoot(child);
        }
    }
    explicit Tree(unsigned long size) {
        graph = vector<Node>(size);
        root = &graph[0];
    }
    void addEdge(unsigned long x, unsigned long y) {
        graph[x].adjacent.push_back(&graph[y]);
        graph[y].adjacent.push_back(&graph[y]);
    }
};

int main() {

}