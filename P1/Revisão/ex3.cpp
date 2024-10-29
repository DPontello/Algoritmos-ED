/*
Você tem uma estrutura Heap com dados de operações e, cada operação tem sua prioridade. Os dados são organizados em uma MaxHeap de acordo com a prioridade. Implemente um método que altere a prioridade de um dado elemento e reorganize a estrutura de modo que os dados com a nova prioridade fiquem corretos.
*/


#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct dado{
	char operacao;
	int prioridade;
	};

class MaxHeap {
private:
    dado* heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i); 
    void arruma(); // heapify()
    void corrigeDescendo(int i); 
    void corrigeSubindo(int i);
public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    void alteraPrioridade(dado d, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap) {
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}
MaxHeap::~MaxHeap() {
    delete[] heap;    
}
void MaxHeap::arruma() {
    for (int i=(tamanho/2-1); i>=0; i--) {
        corrigeDescendo(i);
    }
}
int MaxHeap::pai(int i) {
    return (i-1)/2;
}
    
int MaxHeap::esquerdo(int i) {
    return 2*i+1;
}
    
int MaxHeap::direito(int i) {
    return 2*i+2;
}
    
void MaxHeap::corrigeDescendo(int i) {
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;
    
    if ((esq < tamanho) and (heap[esq].prioridade > heap[maior].prioridade)) {
        maior = esq;
    } 
    
    if ((dir < tamanho) and (heap[dir].prioridade > heap[maior].prioridade)) {
        maior = dir;
    }
    
    if (maior!=i) {
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}
void MaxHeap::corrigeSubindo(int i) {
    int p = pai(i);
    if (heap[i].prioridade > heap[p].prioridade) {
        swap(heap[i],heap[p]);
        corrigeSubindo(p);
    }
}
        
void MaxHeap::imprime() {
    for (int i=0; i<tamanho; i++) {
        cout << heap[i].operacao << " " << heap[i].prioridade<<endl;
    }
    cout << endl;
}
dado MaxHeap::retiraRaiz() {
    if (tamanho == 0){
        cerr << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    swap(heap[0], heap[tamanho-1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}
void MaxHeap::insere(dado d){
    if (tamanho == capacidade) {
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

void MaxHeap::alteraPrioridade(dado d, int novaPrioridade){
    for(int i = 0; i < tamanho; i++){
        if(heap[i].operacao == d.operacao && heap[i].prioridade == d.prioridade){
            heap[i].prioridade = novaPrioridade;
            corrigeDescendo(i);
            corrigeSubindo(i);
            break;
        }  
    }
}
int main () {
    int capacidade, opcao;
    cin>> capacidade;
        
    MaxHeap *h = new MaxHeap(capacidade);
    
    dado entrada,saida;
    int novaPrioridade;
    cin >> opcao;
    while (opcao != 0){
	if (opcao == 1){
	    cin>>entrada.operacao>>entrada.prioridade;
	    h->insere(entrada);
	} else if (opcao == 2){
		saida = h->retiraRaiz();
		cout<<saida.operacao<<" "<<saida.prioridade<<endl;
	} else if (opcao == 3){//APENAS PARA EFEITO DE DEPURAÇÃO
		h->imprime();    
	} else if (opcao == 4){
        cin>>entrada.operacao>>entrada.prioridade>>novaPrioridade;
        h->alteraPrioridade(entrada,novaPrioridade);
	}
	cin >> opcao;
	}
    
    delete h;
    
    return 0;
}