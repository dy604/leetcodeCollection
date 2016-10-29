
//题目133，Clone Graph 无向图的复制

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        unordered_map<int, UndirectedGraphNode*> umap;
        return clone(node, umap);
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*> &umap) {
        if (!node) return node;
        if (umap.count(node->label)) return umap[node->label];
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        umap[node->label] = newNode;
        for (int i=0; i<node->neighbors.size(); ++i) {
            (newNode->neighbors).push_back(clone(node->neighbors[i], umap));
        }
        return newNode;
    }
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == nullptr) return nullptr;
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copied;
        queue<const UndirectedGraphNode*> q;
        q.push(node);
        copied[node] = new UndirectedGraphNode(node->label);
        while (!q.empty()) {
            const UndirectedGraphNode* cur = q.front();
            q.pop();
            for (auto nbr : cur->neighbors) {
                if (copied.find(nbr) != copied.end()) {
                    copied[cur]-->neighbors.push_back(copied[nbr]);
                } else {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(nbr->label);
                    copied[nbr] = newNode;
                    copied[cur]->neighbors.push_back(newNode);
                    q.push(nbr);
                }
            }
        }
        return copied[node];
    }
};
