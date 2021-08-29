#include "arvore.h"
#include <cmath>
#include <iostream>
void Tree::criaNos(Node* no, int h) {
    if(h > 0) {
        no->left = new Node(0);
        no->right = new Node(0);
        criaNos(no->left, h-1);
        criaNos(no->right, h-1);
    } else
        no = nullptr;
}
    
void Tree::limpaArvore(Node* no) {
    if(no != nullptr) {
        limpaArvore(no->left);
        limpaArvore(no->right);
        delete no;
    }
}
    
int Tree::_preencheArvore(Node* no, Fila* folhas) {
    if(no->left == nullptr) {
        if(!folhas->empty()) {
            no->key = folhas->getFst();
            folhas->remove();
        } else
            no->key = maior;
        return no->key;
    }
    no->key = _preencheArvore(no->left, folhas) < _preencheArvore(no->right, folhas) ? no->left->key : no->right->key;
    return no->key;
}
    
int Tree::_ordena(Node* no) {
    if(no->left == nullptr) {
        if(no->key == menor)
            no->key = maior;
        return no->key;
    }
    no->key = _ordena(no->left) < _ordena(no->right) ? no->left->key : no->right->key;
    return no->key;
}

Tree::Tree(int h, int m) {
    maior = m;
    root = new Node(0);
    criaNos(root, h-1);
}
    
Tree::~Tree() {
    limpaArvore(root);
}

void Tree::preencheArvore(int* vet, int tam) {
    Fila* folhas = new Fila(vet, tam);
    menor = _preencheArvore(root, folhas);
}

void Tree::ordena() {
    while(menor != maior) {
        std::cout << menor << " ";
        menor = _ordena(root);
    }
    std::cout << std::endl;
}