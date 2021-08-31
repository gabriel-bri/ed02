#include "arvore.h"
#include <cmath>
#include <iostream>

/*Árvore cheia, pra cada nó, cria mais 2 nós de acordo com a altura h, nó raiz é inicializado fora
da função. Executa 2^(h)-2, h = ceil(log2(n))+1, considerando ceil(log2(n)) = log2(n):
executa 2*2^(log2(n))-2 = 2n-2: O(n), tal que n é o número de elementos do vetor de entrada*/
void Tree::criaNos(Node* no, int h) { // Cria os nós de acordo com a altura da árvore
    if(h > 0) {                       // considerando uma árvore cheia.
        no->left = new Node(0);
        no->right = new Node(0);
        criaNos(no->left, h-1);
        criaNos(no->right, h-1);
    } else
        no = nullptr;
}

/*Percorre todos os nós da árvore e, recursivamente, deleta eles: O(k), tal que k é o número de nós
da árvore. Ou executa 2^(h)-1, h = ceil(log2(n))+1, considerando ceil(log2(n)) = log2(n):
executa 2*2^(log2(n))-2 = 2n-2: O(n), tal que n é o número de elementos do vetor de entrada*/
void Tree::limpaArvore(Node* no) { // deleta todos os nós da árvore
    if(no != nullptr) {
        limpaArvore(no->left);
        limpaArvore(no->right);
        delete no;
    }
}

/*Percorre toda a árvore, atribuindo valor a cada nó: O(k), tal que k é o número de nós da árvore
ou 2^(h)-1, h = ceil(log2(n))+1, considerando ceil(log2(n)) = log2(n):
2*2^(log2(n))-1, 2n-1: O(n), tal que n é o número de elementos do vetor de entrada*/
int Tree::_preencheArvore(Node* no, Fila* folhas) { //Preenche as folhas da árvore, da esquerda pra direita
    if(no->left == nullptr) {                       //retirando os valores da estrutura Fila até ela estar vazia,
        if(!folhas->empty()) {                      //daí passa a atribuir o valor da variável "maior" as folhas restantes
            no->key = folhas->getFst();             //e, recursivamente, os nós pai com o menor entre seus dois filhos
            folhas->remove();
        } else
            no->key = maior;
        return no->key;
    }
    no->key = _preencheArvore(no->left, folhas) < _preencheArvore(no->right, folhas) ? no->left->key : no->right->key;
    return no->key;
}

/*Percorre todo a árvore até as folhas: O(k), tal que k é o número de nós da árvore
ou 2^(h)-1, h = ceil(log2(n))+1, considerando ceil(log2(n)) = log2(n):
2*2^(log2(n))-1, 2n-1: O(n), tal que n é o número de elementos do vetor de entrada*/    
int Tree::_ordena(Node* no) { // Altera o valor da menor folha para o maior e
    if(no->left == nullptr) { // de baixo para cima, atribui o valor do menor filho ao pai
        if(no->key == menor)  // (com exceção das folhas)
            no->key = maior;
        return no->key;
    }
    no->key = _ordena(no->left) < _ordena(no->right) ? no->left->key : no->right->key;
    return no->key;
}

// Inicializa 2 variáveis e faz a chamada de uma função: O(1)
Tree::Tree(int h, int m) {
    maior = m;              // inicializa a variável maior com o maior valor do vetor de entrada +1
    root = new Node(0);     // inicializa o root
    criaNos(root, h-1);     // cria a quantidade correta de nós para o vetor de entrada
}

//Chamada de função: O(1)
Tree::~Tree() { // limpa a árvore
    limpaArvore(root);
}

//Criação e inicialização de variáveis, e chamada de uma função: O(1)
void Tree::preencheArvore(int* vet, int tam) { // recebe um vetor de inteiros e seu tamanho
    Fila* folhas = new Fila(vet, tam);         // cria uma fila com os números no vetor
    menor = _preencheArvore(root, folhas);     // atribui à variável "menor" o valor de root ao final
}                                              // da chamada da função _preencheArvore

/*Função ligada ao tamanha do vetor usado para criar a árvore. Cada vez que executar o "menor" vai
/receber um dos números presentes no vetor, com o primeiro número do vetor já inicializado, executa
n-1 vezes, +1 quando o "maior" fica no root, ou seja: O(n)*/
void Tree::ordena() {               // printa os números da árvore em ordem decrescente,
    while(menor != maior) {         // menos o "maior", consequentemente, o vetor de entrada
        std::cout << menor << " ";
        menor = _ordena(root);
    }
    std::cout << std::endl;
}
