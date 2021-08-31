#include "Fila.h"

//O(tam)
Fila::Fila(int* v, int tam) { // cria uma Fila com base em um vetor de inteiros e seu tamanho
    fst = lst = nullptr;
    for(int i = 0; i < tam; i++) {
        insert(*(v+i));
    }
}

//O(n)
Fila::~Fila() { // esvazia a Fila
    while(!empty()) {
        NodeF *lixo = fst;
        fst = fst->next;
        delete lixo;
    }
    lst = nullptr;
}

//O(1)
bool Fila::empty() { // testa se a Fila está vazia
    return fst == nullptr;
}

//O(1)
void Fila::insert(int key) { // insere um valor ao final da Fila
    NodeF *no = new NodeF(key);
    if(empty()) 
        fst = lst = no;
    else {
        lst->next = no;
        lst = no;
    }
}

//O(1)
void Fila::remove() { // remove o valor no ínicio da Fila
    if(empty())
        return;
    NodeF *no = fst;
    fst = fst->next;
    delete no;
    if(empty()) 
        lst = nullptr;
}

//O(1)
int Fila::getFst() { // acessa o valor no ínicio da Fila
    if(empty())
        return 0;
    return fst->key;
}
