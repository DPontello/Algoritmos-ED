/*
1 - Você precisa desenvolver um sistema para controlar os atendimentos em uma delicatessen. Os clientes são divididos em regulares e prioritários e, sempre que houver um cliente prioritário, ele deve ser imediatamente atendido. Caso um atendimento esteja em andamento, esse deve ser concluído e, em seguida, o cliente prioritário deve ser atendido. Faça a implementação da estrutura de dados fila encadeada com as operações enfileira (insere um item na fila), desenfileira (remove um item da fila) e vazia (verifica se a fila está vazia). As operações devem garantir a integridade da estrutura seguindo as característica da mesma: novos elementos são inseridos no final da fila, elementos são removidos apenas do início da fila e o acesso a um elemento só pode ser realizado com a remoção do mesmo.

Além da estrutura, implemente, na função principal, um sistema que simule as operações de entrar na fila e de atendimento.
*/

#include <iostream>
using namespace std;

class Noh {
    friend class Fila;
    private:
    int mDado;
    Noh* proximo;
    
    public:
    Noh(int mDado) {
        this->mDado = mDado;
        this->proximo = NULL;
    }
};

class Fila {
    private:
    Noh* inicio;
    Noh* fim;
    int tamanho;
    
    public:
    Fila(){
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    ~Fila(){	
        limpaPilha();
    }

    void enqueue(int mDado){
        Noh* novo = new Noh(mDado);
        if(tamanho == 0){
            inicio = novo;
        } else {
            fim->proximo = novo;
        }
        fim = novo;
        tamanho++;
    }

    int dequeue(){
        if(tamanho == 0) {
            cout << "Fila vazia! Não é possível desenfileirar." << endl;
            return -1;
        }
        int dado = inicio->mDado;
        Noh *aux = inicio;
        inicio = inicio->proximo;
        delete aux;
        tamanho--;
        if (tamanho == 0){
            fim = NULL;
        }
        return dado;
    }

    void limpaPilha(){
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

};

int main(){
    Fila f1;
    int opcao, dado;
    
    while(true){
        cout << "\n1 - Enfileirar um cliente" << endl;
        cout << "2 - Atender um cliente" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        switch(opcao){
            case 1:
                cout << "Digite o dado do cliente: ";
                cin >> dado;
                f1.enqueue(dado);
                cout << "Cliente enfileirado com sucesso!" << endl;
                break;
            case 2:
                if(f1.vazia()){
                    cout << "Fila vazia! Não é possível atender." << endl;
                } else {
                    cout << "Cliente atendido: " << f1.dequeue() << endl;
                }
                break;
            case 3:
                cout << "Saindo..." << endl;
                f1.limpaPilha();
                return 0;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}