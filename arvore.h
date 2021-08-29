#ifndef ARVORE_H
#define ARVORE_H
#include "Fila.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
private:
    Node *root;
    int maior;
    int menor;
    void criaNos(Node* no, int h);
    void limpaArvore(Node* no);
    int _preencheArvore(Node* no, Fila* folhas);
    int _ordena(Node* no);
public:
    Tree(int h, int m);
    ~Tree();
    void preencheArvore(int *folhas, int tam);
    void ordena();
};

#endif