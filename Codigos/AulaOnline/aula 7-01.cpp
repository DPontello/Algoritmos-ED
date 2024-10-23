#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


typedef int dado;

class MaxHeap{
    private:
    dado *heap;
    int capacidade;
    int tamanho;
    int pai(int i);
    int esquerdo(int i);
    int direito(int i);
    void arruma(); // heapify() metade até a raiz
    void corrigeDescendo(int i);
    void corrigeSubindo(int i);

    public:
    MaxHeap(int capacidade);
    MaxHeap(dado vet[], int tam);
    ~MaxHeap();	
    void imprime();
    dado espiaRaiz();
    dado retiraRaiz();
    void insere(dado d);
};

MaxHeap::MaxHeap(int capacidade){
    this->capacidade = capacidade;
    heap = new dado(capacidade);
    tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[], int tam){
    capacidade = tam;
    
    heap = new dado[capacidade];
    
    memcpy(heap, vet, tam * sizeof(dado));
    /*for(int i = 0; i < tam; i++){
        heap[i] = vet[i];
    }*/

    tamanho = tam;
    arruma();
}

MaxHeap::~MaxHeap(){
    delete[] heap;
}

void MaxHeap::arruma(){
    for(int i =(tamanho/2-1); i >= 0; i--){
        corrigeDescendo(i);
    }
}

int MaxHeap::pai(int i){
    return (i-1)/2;
}

int MaxHeap::esquerdo(int i){
    return 2*i+1;
}

int MaxHeap::direito(int i){
    return 2*i+2;
}


void MaxHeap::corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if((esq < tamanho) and (heap[esq] > heap[maior])){
        maior = esq;
    }

    if((dir < tamanho) and (heap[dir] > heap[maior])){
        maior = dir;
    }

    if(maior != i){
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

dado MaxHeap::retiraRaiz() {
    if (tamanho ==0){
        cerr << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    swap(heap[0], heap[tamanho-1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
    }

dado MaxHeap::espiaRaiz() {
    return heap[0];
}

void MaxHeap::insere(dado d){
    if(tamanho == capacidade){
        cerr << "Heap cheio" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

void MaxHeap::corrigeSubindo(int i){
    int p  = pai(i);
    if(heap[i] == heap[p]){
        swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}



int main(){
    int tam = 13;
    dado vet[] = {50, 2, 90,20, 230, 43, 8, 34, 66, 100, 110, 3, 13};

    MaxHeap *h = new MaxHeap(vet, tam);

    for(int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " ";
    }
    cout << endl;

    for (int i = 0; i < tam; i++){
        h->insere(vet[i]);
    }

    for(int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " ";
    }
    cout << endl;

    delete h;
    
    return 0;
}