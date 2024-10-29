/*
Implemente uma função que realize a busca por valores dos dados da estrutura pilha que estão dentro de uma faixa informada. Para resolver o problema, o algoritmo pode utilizar somente outra pilha como estrutura auxiliar. Após encontrar determinado valor, o mesmo deve ser impresso

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Pilha com armazenamento em vetor - Lista de tarefas para robô doméstico" como base.

Entradas:

Com essa finalidade, você deverá adicionar mais um comando, como segue:

b seguido de dois inteiros: para buscar (e imprimir) os valores dos dados que são maiores que o primeiro elemento e menores que o segundo. É garantido que o primeiro valor sempre será menor que o segundo
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 60
i quarto3 q 45
i cozinha c 130
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 143
e
Nome: cozinha Tipo: c Valor: 143
i varanda v 111
i banheiro b 33
Erro: pilha cheia!
b 30 90
Nome: quarto3 Tipo: q Valor: 45
Nome: quarto2 Tipo: q Valor: 60
Nome: quarto1 Tipo: q Valor: 45
b 30 60
Nome: quarto3 Tipo: q Valor: 45
Nome: quarto1 Tipo: q Valor: 45
f
Nome: varanda Tipo: v Valor: 111
Nome: cozinha Tipo: c Valor: 143
Nome: quarto3 Tipo: q Valor: 45
Nome: quarto2 Tipo: q Valor: 60
Nome: quarto1 Tipo: q Valor: 45
Nome: sala Tipo: s Valor: 150

*/

/* Classe pilha estatica
 Implemente uma estrutura de dados pilha, utilizando armazenamento em vetor, para implementar uma lista de tarefas para um robô doméstico. A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha e limpeza da lista de afazeres (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"), quando a pilha já estiver vazia. O empilhamento também deve gerar mensagem de erro ("Erro: pilha cheia!"), quanto todas as posições do vetor estiverem ocupadas. Os itens da lista de tarefas possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e tempo de execução em minutos (um inteiro). Além disso, sabe-se que esse robô tem capacidade de memória limitada para no máximo seis tarefas.

Entradas:

O programa deve aceitar os seguintes comandos:

i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de tarefas
r: para retirar um item da lista de tarefas
l: para limpar (remover todos) os itens da lista de tarefas
e: para espiar o topo da lista de tarefas (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Antes dos comandos, o programa recebe a capacidade de armazenamento da pilha.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 45
i quarto3 q 60
i cozinha c 130	
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 145
e
Nome: cozinha Tipo: c Valor: 145
i varanda v 100
i banheiro b 120
Erro: pilha cheia!
f
Nome: varanda Tipo: v Valor: 100
Nome: cozinha Tipo: c Valor: 145
Nome: quarto3 Tipo: q Valor: 60
Nome: quarto2 Tipo: q Valor: 45
Nome: quarto1 Tipo: q Valor: 45
Nome: sala Tipo: s Valor: 150
 */
#include <iostream>

using namespace std;

const int PILHAVAZIA = -1;
const int TAMANHOPILHA = 6;

struct Dado {
    string nome;
    char tipo;
    int valor;
};

// Imprime informações de um dado qualquer.
void imprimir_dado(const Dado& umDado){
    cout<< "Nome: " << umDado.nome << " ";
    cout<< "Tipo: " << umDado.tipo << " ";
    cout<< "Valor: " << umDado.valor << endl;
}

class Pilha {
    private:
        Dado* mPilha;
        int posTopo;
    public:
        // Constrói pilha vazia.
        Pilha();
        // Destrutor que desaloca memória.
        ~Pilha();
        // Retira e retorna o valor que estiver no topo da pilha.
        Dado Desempilhar(); 
        // Insere um elemento na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Imprime o valor que está no topo sem desempilhar.
        inline void Topo();
        // Informa se a pilha está Vazia.
        inline bool Vazia();
        // Informa se a pilha está Cheia.
        inline bool Cheia();
        void buscar(int min, int max);
};

Pilha::Pilha(){
    posTopo = 0;
    mPilha = new Dado[TAMANHOPILHA];
}

Pilha::~Pilha() {
    LimparTudo();
}


Dado Pilha::Desempilhar() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");
    // completar com código necessário caso pilha não esteja vazia
    Dado apagado = mPilha[posTopo-1];
    posTopo--;
    return apagado;  // retorna o valor apagado
}

void Pilha::Empilhar(const Dado& d) {
    if (this->Cheia()){
        cout << "Erro: pilha cheia!" << endl;
    } else {
    // completar com código necessário caso pilha não esteja vazia
        mPilha[posTopo] = d;
        posTopo++;   
    } 
}

void Pilha::LimparTudo() {
    while(posTopo > 0){
        Desempilhar();
    }
}

void Pilha::Topo() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");
    // completar com código necessário caso pilha não esteja vazia
    imprimir_dado(mPilha[posTopo-1]);   

}

bool Pilha::Vazia() {
    return (posTopo == 0);
}

bool Pilha::Cheia() {
    return (posTopo == TAMANHOPILHA);
}

void Pilha::buscar(int min, int max){
    Pilha aux;
    Dado d;
    while(!this->Vazia()){
        d = this->Desempilhar();
        
        if(d.valor > min && d.valor < max){
            imprimir_dado(d);
        }

        aux.Empilhar(d);
    }

    while(!aux.Vazia()){
        this->Empilhar(aux.Desempilhar());
    }
}
    


int main() {
    Pilha pilha;
    Dado info;
    char comando;
    int min, max;
    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.tipo >> info.valor;
                    pilha.Empilhar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(pilha.Desempilhar());
                    break;
                case 'l': // limpar tudo
                    pilha.LimparTudo();
                    break;
                case 'e': // espiar             
                    pilha.Topo();
                    break;
                case 'b': // buscar
                    cin >> min >> max;
                    pilha.buscar(min, max);
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
    while (not pilha.Vazia()) {
        imprimir_dado(pilha.Desempilhar());
    }
    cout << endl;
    return 0;
}