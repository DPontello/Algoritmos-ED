/*
Modifique o tipo do campo prêmio para inteiro, sendo o valor a ser recebido em moedas digitais pela atividade realizada pelo jogador. Implemente uma função que imprima a soma das recompensas das atividades com tempo menor que o informado e coloque essas atividade no início da fila. Caso não exista nenhuma atividade menor que o valor informado, deve ser impresso o valor 0.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com encadeamento - Lista de tarefas do jogador" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

p seguido de um inteiro: para contabilizar (e imprimir) o valor total do premio das atividades que foram realizadas dentro do valor determinado.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: Fila vazia!
i destruirArmazen 252 f 100
i salvarDonzela 888 e 300
i montarObservatorioMonteM2 582 d 400
i eliminarChefao 12585 a 2000
i eliminarBando 25354 a 30000
p 500
1722
r
Nome: destruirArmazen Premio: 252 Tipo: f tempo: 100
e
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
f
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: 582 Tipo: d tempo: 400
Nome: eliminarChefao Premio: 12585 Tipo: a tempo: 2000
Nome: eliminarBando Premio: 25354 Tipo: a tempo: 30000
*/

#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado {
    string nome;
    int premio;
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
        int contabilizar(int valor);
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

int Fila::contabilizar(int tempo){
    Fila filaAux; 
    int soma = 0;
    while(!this->Vazia()){
        Dado temp = this->Desenfileirar();
        if(temp.tempo < tempo){
            soma += temp.premio;
        }
        filaAux.Enfileirar(temp);
    }
    while(!filaAux.Vazia()){
        this->Enfileirar(filaAux.Desenfileirar());
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
                case 'p': // contabilizar premios
                    int valor;
                    cin >> valor;
                    cout << fila.contabilizar(valor) << endl;
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