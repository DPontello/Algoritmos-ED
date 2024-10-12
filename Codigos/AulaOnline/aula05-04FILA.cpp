#include <iostream>
using namespace std;

class Noh{
    friend class Fila;
    private: 
    int valor;
    Noh *proximo;

    public:
    Noh(int valor){
        this->valor = valor;
        proximo = NULL;
    }
};

class Fila{
    private:
    Noh *inicio;
    Noh *fim;
    int tamanho;
    
    public:
    Fila(){
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    ~Fila(){
        limpaFila();
    }

    void limpaFila(){
        while(tamanho > 0){
            dequeue();
        }
    }

    int getTamanho(){
        return tamanho;
    }

    bool vazia(){
        return (tamanho == 0);
    }

    void enqueue(int valor){
        Noh *novo = new Noh(valor);
        if (tamanho == 0){
            inicio = novo;
        } else {
            fim->proximo = novo;
        }
        fim = novo;
        tamanho++;
    }

    int dequeue(){
        int valor = inicio->valor;
        Noh *aux = inicio;
        inicio = inicio->proximo;
        delete aux;
        tamanho--;
        if (tamanho == 0){
            fim = NULL;
        }
        return valor;
    }

};

int main(){
    Fila f1;
    int num;
    cin >> num;
    
    while(num >= 0){
        f1.enqueue(num);
        cin >> num;
    }

    cout << "Tamanho: " <<  f1.getTamanho() << endl;

    cout << "elementos: ";

    while (not f1.vazia()){
        cout << f1.dequeue() << " ";
    }
    cout << endl;

    return 0;
    
}