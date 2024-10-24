/*
Implemente uma função que realize a contagem e impressão do tempo para realizar as atividades de um mesmo tipo e as coloque na frente da fila.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com encadeamento - Lista de tarefas do jogador" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

a seguido de um char: para contabilizar (e imprimir) o tempo para realizar as atividades de um mesmo tipo.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens são desenfileirados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: Fila vazia!
i destruirArmazen jaqueta f 100
i salvarDonzela hb20 e 300
i montarObservatorioMonteM2 binoculo d 400
i eliminarChefao milDolares a 2000
i eliminarBando dezmilDolares a 30000
a a
32000
r
Nome: eliminarChefao Premio: milDolares Tipo: a tempo: 2000
e
Nome: eliminarBando Premio: dezmilDolares Tipo: a tempo: 30000
f
Nome: eliminarBando Premio: dezmilDolares Tipo: a tempo: 30000
Nome: destruirArmazen Premio: jaqueta Tipo: f tempo: 100
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: binoculo Tipo: d tempo: 400

*/

#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado {
    string nome;
    string premio;
    char tipo;
    int tempo;
};

// Imprime as informações de um dado qualquer
void imprimir_dado(const Dado& umDado) {
    cout << "Nome: " << umDado.nome << " Premio: " << umDado.premio  << " Tipo: " << umDado.tipo << " tempo: " << umDado.tempo << endl;
}

class Noh {
    friend class Fila;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mProx;
    public:
        Noh(Dado v) {
            mDado = v;
            mProx = NULL;
        }        
};

class Fila {
    public:
        // Constrói Fila vazia.
        Fila();
        // Destrutor que desaloca memória.
        ~Fila();
        // Retira e retorna o elemento que estiver na frente da Fila.
        // Escreve uma mensagem de erro se não for possível desenfileirar.
        Dado Desenfileirar(); 
        // Insere um elemento na Fila.
        void Enfileirar(const Dado& d);
        // Apagar todos os dados da Fila.
        void LimparTudo();
        // Retorna o elemento que está na frente da Fila, sem desenfileirar.
        inline void Topo();
        // Informa se a Fila está Vazia.
        inline bool Vazia();
        int contagem(char tipo);
    private:
        Noh* inicio;
        Noh* fim;
};

Fila::Fila() {   
    inicio = NULL;
    fim = NULL;
}

Fila::~Fila() {
    LimparTudo();
}

Dado Fila::Desenfileirar() {
    if (this->Vazia()) throw runtime_error("Erro: Fila vazia!");
    // completar com o código, caso não esteja vazia
    Dado apagado;
    Noh *aux = inicio;
    apagado = inicio->mDado;
    inicio = inicio->mProx;
    aux->mProx = NULL;
    delete aux;
    return apagado;
}

void Fila::Enfileirar(const Dado& d) {
   Noh *novo = new Noh(d);
   if(inicio == NULL){
    inicio = novo;
    fim = novo;
   } else {
    fim->mProx = novo;
    fim = novo;
   }
}

void Fila::LimparTudo() {
    while(inicio != NULL){
        Desenfileirar();
    }
}

void Fila::Topo() {
    if (this->Vazia()) throw runtime_error("Erro: Fila vazia!");
    // completar com o código, caso não esteja vazia
    imprimir_dado(inicio->mDado);
}

bool Fila::Vazia() {
    return (inicio == NULL);
}

int Fila::contagem(char tipo){
    Fila aux;
    Fila aux2;
    Dado temp;
    int soma = 0;
    while(!this->Vazia()){
        temp = this->Desenfileirar();
        if(temp.tipo == tipo){
            soma += temp.tempo;
            aux.Enfileirar(temp);
        } else{
            aux2.Enfileirar(temp);
        }
    }
    while(!aux.Vazia()){
        this->Enfileirar(aux.Desenfileirar());
    }
    while(!aux2.Vazia()){
        this->Enfileirar(aux2.Desenfileirar());
    }
    return soma;

}

int main() {
    Fila fila;
    Dado info;
    char comando;
    do {
        try{
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.premio >> info.tipo >> info.tempo;
                    fila.Enfileirar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(fila.Desenfileirar());
                    break;
                case 'l': // limpar tudo
                    fila.LimparTudo();
                    break;
                case 'e': // espiar primeiro dado (INICIO)               
                    fila.Topo();
                    break;
                case 'a': // contar tempo para atividades do mesmo tipo
                    char tipo;
                    cin >> tipo;
                    cout << fila.contagem(tipo) << endl;
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    while (not fila.Vazia()) {
        imprimir_dado(fila.Desenfileirar());
    }
    cout << endl;
    return 0;
}