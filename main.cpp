#include <iostream>
#include <cmath>
#include "arvore.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n != 0) {
    int h, maior = INT_MIN;
    int v[n];
    h = ceil(log2(n))+1;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > maior)
            maior = v[i];
    }
    maior++;
    // Construtor (O(1)) chama a função criaNos(O(n)) => 1*n = n = O(n)
    Tree arv(h, maior);
    // preencheArvore (O(1)) cria uma Fila O(n) e chama a função _preencheArvore (O(n)) => 1*(n+n) = 2n = O(n)
    arv.preencheArvore(v, n);
    // ordena (O(n)) chama a função _ordena (O(n)) dentro do while => n*n = n² = O(n²)
    arv.ordena();
    cin >> n;
    // Destrutor (O(1)) chamna a função limpaArvore(O(n)) => 1*n = n = O(n)
    }
}
