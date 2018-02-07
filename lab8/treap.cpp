// treap.cpp: Treap Map

#include "map.h"
#include <algorithm>
#include <climits>
#include <random>
using namespace std;

// Prototypes - helper functions ------------------------------------------------------------------

Node *insert_t(Node *node, const std::string &key, const std::string &value);
extern void dump_r(Node *node, std::ostream &os, DumpFlag flag);
Node *search_t(Node *node, const std::string &key);
Node *RotateRight(Node *node);
Node *RotateLeft(Node *node);
int getMinTreeHeight_t(Node *node);
int getMaxTreeHeight_t(Node *node);
void preOrderTraversal_t(Node *node);


// Methods ---------------------------------------------------------------------

void TreapMap::insert(const std::string &key, const std::string &value) {
    root = insert_t(root, key, value);
}

const Entry TreapMap::search(const std::string &key) {
    auto result = search_t(root, key);
    return (result == nullptr ? NONE : result->entry);
}

int TreapMap::getMaxTreeHeight(){
    int max = getMaxTreeHeight_t(root);
    return max;
}

int TreapMap::getMinTreeHeight(){
    int min = getMinTreeHeight_t(root);
    return min;
}

void TreapMap::preOrderTraversal(){
    preOrderTraversal_t(root);
    cout << endl;
}

/// Internal functions -------------------------------------------------------------

int get_random(){
    static std::random_device rd;
    static std::default_random_engine g(rd());
    static std::uniform_int_distribution<> d(1,INT_MAX);
    return d(g);
}



Node *insert_t(Node *node, const std::string &key, const std::string &value) {
    if (node == nullptr){
        return new Node{Entry(key, value), get_random(), nullptr, nullptr};
    }
    if (node->entry.first == key){
        node->entry.second = value;
        return node;
    }
    if (node->entry.first > key){
        node->left = insert_t(node->left, key, value);
        if (node->left->priority > node->priority){
            node = RotateRight(node);
        }
    }else{
        node->right = insert_t(node->right, key, value);
        if (node->right->priority > node->priority){
            node = RotateLeft(node);
        }
    }
    return node;
}


Node *search_t(Node *node, const std::string &key) {
    //TODO
    if (node == nullptr){
        return nullptr;
    }
    if (node->entry.first == key){
        return node;
    }
    if (node->entry.first > key){
        return search_t(node->left, key);
    } else {
        return search_t(node->right, key);
    }
}

void TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

int getMinTreeHeight_t(Node *node){
    if (node == nullptr){
        return 0;
    }else{
        int lDepth = getMinTreeHeight_t(node->left);
        int rDepth = getMinTreeHeight_t(node->right);
        if (lDepth < rDepth){
            return (lDepth+1);
        }else{
            return (rDepth+1);
        }
    }
    return 0;
}

int getMaxTreeHeight_t(Node *node){
    if (node == nullptr){
        return 0;
    }else{
        int lDepth = getMaxTreeHeight_t(node->left);
        int rDepth = getMaxTreeHeight_t(node->right);
        if (lDepth > rDepth){
            return (lDepth+1);
        }else{
            return (rDepth+1);
        }
    }
    return 0;
}


void preOrderTraversal_t(Node *node){
    if (node == nullptr){
        return;
    }
    cout << node->entry.first << " ";
    preOrderTraversal_t(node->left);
    preOrderTraversal_t(node->right);
}

Node *RotateRight(Node *node){
    Node *n1 = node->left;
    Node *n2 = n1->right;
    n1->right = node;
    node->left = n2;
    return n1;
}

Node *RotateLeft(Node *node){
    Node *n1 = node->right;
    Node *n2 = n1->left;
    n1->left = node;
    node->right = n2;
    return n1;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
