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
    h = ceil(log2(n)+1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > maior)
            maior = v[i];
    }
    maior++;
    Tree arv(h, maior);
    arv.preencheArvore(v, n);
    arv.ordena();
    cin >> n;
    }
}