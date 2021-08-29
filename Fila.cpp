#include "Fila.h"
Fila::Fila(int* v, int tam) {
    fst = lst = nullptr;
    for(int i = 0; i < tam; i++) {
        insert(*(v+i));
    }
}
Fila::~Fila() {
    while(!empty()) {
        NodeF *lixo = fst;
        fst = fst->next;
        delete lixo;
    }
    lst = nullptr;
}
bool Fila::empty() {
    return fst == nullptr;
}
void Fila::insert(int key) {
    NodeF *no = new NodeF(key);
    if(empty()) 
        fst = lst = no;
    else {
        lst->next = no;
        lst = no;
    }
}
void Fila::remove() {
    if(empty())
        return;
    NodeF *no = fst;
    fst = fst->next;
    delete no;
    if(empty()) 
        lst = nullptr;
}
int Fila::getFst() {
    if(empty())
        return 0;
    return fst->key;
}