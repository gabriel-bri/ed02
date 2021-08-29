#ifndef FILA_H
#define FILA_H

struct NodeF {
    int key;
    NodeF *next;
    NodeF(int x) {
        key = x;
        next = nullptr;
    }
};

class Fila {
private:
    NodeF* fst;
    NodeF* lst;
public:
    Fila(int* v, int tam);
    ~Fila();
    bool empty();
    void insert(int key);
    void remove();
    int getFst();
};

#endif