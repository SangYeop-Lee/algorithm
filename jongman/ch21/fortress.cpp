#include <iostream>
#include <vector>

using namespace std;

int n;
int Answer = 0;

struct Circle {
    int x;
    int y;
    int r;
};

struct Node {
    Circle c;
    Node* parent;
    vector<Node*> children;
    int height;
};

bool compare(Circle a, Circle b) {
    return a.x==b.x && a.y==b.y && a.r == b.r;
};

int sqr(int a) {
    return a * a;
};

// a > b : 1
// b < a : -1
// a ? b : 0
int include(Circle a, Circle b) {
    Circle big = a.r > b.r ? a : b;
    Circle small  = a.r > b.r ? b : a;
    if (
      sqr(big.x-small.x) + sqr(big.y-small.y) < sqr(big.r-small.r)
    ) {
        return compare(big, a) ? 1 : -1;
    }
    return 0;
};

Node* createNode (Node* parent, Circle c){
    Node* ret = new Node();
    ret->parent = parent;
    ret->c = c;
    return ret;
};

void insert(Node* node, Circle c) {
    vector<Node*>& children = node->children;
    for (int i=0; i<children.size(); ++i) {
        int res = include(children[i]->c, c);
        if (res == 0) {
            continue;
        } else if (res == 1) {
            insert(children[i], c);
            return;
        } else { // res == -1
            Node* tmp = createNode(node, c);
            tmp->children.push_back(children[i]);
            children[i]->parent = tmp;
            children.push_back(tmp);
            children.erase(children.begin() + i);
            return;
        }
    }
    children.push_back(
        createNode(node, c)
    );
};

// void printNode (Node* n) {
//     cout <<
//         "coords: " << n->c.x << ", " << n->c.y << endl <<
//         "radius: " << n->c.r << endl <<
//         "height: " << n->height << endl;
// };

// void printTree (Node* root) {
//     printNode(root);
//     for (int i=0; i<root->children.size(); ++i)
//         printTree(root->children[i]);
//     return;
// };

// return height of node & save data at global variable Answer.
int count(Node* node) {
    if (node->children.empty()) {
        return node->height = 0;
    }
    vector<Node*>& children = node->children;
    vector<int> heights(1, 0);
    for (auto i = children.begin(); i < children.end(); ++i) {
        heights.push_back(count(*i) + 1);
    }

    sort(heights.begin(), heights.end(), greater<int>());
    Answer = max(Answer, heights[0]+heights[1]);

    return node->height = heights[0];
};

int freeTree(Node *root) {
    for (int i=0; i<root->children.size(); ++i) {
        freeTree(root->children[i]);
    }
    delete root;
};

int main(void) {
    int c;
    cin >> c;
    for (int i=0; i<c; ++i) {
        cin >> n;
        Node* root = new Node();
        Circle tmp;
        cin >> tmp.x >> tmp.y >> tmp.r;
        root->c = tmp;
        for (int i=0; i<n-1; ++i) {
            cin >> tmp.x >> tmp.y >> tmp.r;
            insert(root, tmp);
        }
        Answer = 0;
        count(root);
        cout << Answer << endl;
        // printTree(root);
        freeTree(root);
    }
}
// 2 3 5 5 15 5 5 10 5 5 5 8 21 15 20 15 15 10 13 12 5 12 12 3 19 19 2 30 24 5 32 10 7 32 9 4