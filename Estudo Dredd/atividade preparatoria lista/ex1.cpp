/*
Crie um programa que seja capaz de armazenar em uma lista encadeada as equipes de uma maratona de programação. Para cada equipe deverá ser informado o seu nome, o nome do líder da equipe, a linguagem de programação que será utilizada e a quantidade de membros. Você poderá utilizar o código fornecido como base de implementação.

Os comandos que deverão ser utilizados para execução do programa são:

i: inserir uma nova equipe no inicio da lista. O formato de entrada é: NomeEquipe Lider Linguagem QtdMembros
h: inserir uma nova equipe no fim da lista. O formato de entrada é: NomeEquipe Lider Linguagem QtdMembros
m: inserir uma nova equipe na posição informada pelo usuário através de um número inteiro. Considere 0 como a posição inicial da lista. Caso não seja possível inserir na posição indicada imprima "Posição Inexistente!". O formato de entrada é: posiçãoASerInserida NomeEquipe Lider Linguagem QtdMembros
r: apagar uma determinada equipe do início da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
a: apagar uma determinada equipe do fim da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
p: imprimir lista de equipes cadastradas. Imprimir Lista vazia! quando não tiver elemento a ser impresso.
s: buscar por uma equipe a partir de seu nome. Imprimir Nao encontrado quando a busca não obtiver sucesso.
Nota: o formato de saída das equipes deve ser: (Nome, Lider, Linguagem, QtdMembros). Para mais instâncias de equipes (comando de impressão), cada uma delas devem ser separadas por quebras de linha.

Entradas:

Comandos detalhados no exercício
Saídas:

Impressões detalhadas no exercício
Exemplo de Entrada e Saída misturados:

r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s Thundercats
Lista vazia!
i Vingadores Stark Ruby 3
h LigaDaJustica Batman C++ 4
m 1 MuppetBabies Kermit Phyton 9
p
(Vingadores, Stark, Ruby, 3)
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
s Thundercats
Nao encontrado
r
p
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
a
p
(MuppetBabies, Kermit, Phyton, 9)
f
*/

/* 
 * Classe lista, uma lista dinamicamente encadeada
 * 
 * by Joukim, 2017-2019, Estruturas de Dados
 * alterado em 2023 by Renato
 */

#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

struct equipe {
    string nomeEquipe;
    string lider;
    string linguagem; 
    int qtdMembros;
};

class noh {
friend class lista;
private:
    equipe elenco; // poderia ser outro tipo de variável
    noh* proximo;
public:
    noh(equipe d);
};

noh::noh(equipe d) {
    elenco = d;
    proximo = NULL; // Inicializa o ponteiro como NULL
}

class lista {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista
public:
    lista();
    ~lista();
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string valor); // retorna a posição do nó com o valor
    void imprime();
    bool vazia();
    void removeNoFim();
    void removeNoInicio();
};

// Construtor: inicializa uma lista vazia
lista::lista() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

// Destrutor: remove todos os elementos da lista
lista::~lista() {
    removeTodos();
}

// Remove todos os elementos da lista
void lista::removeTodos() {
    noh* aux = primeiro;
    while (aux != NULL) {
        noh* temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

// Insere no final da lista
void lista::insereNoFim(equipe elenco) {
    noh* novo = new noh(elenco);
    if (vazia()) {
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

// Insere no início da lista
void lista::insereNoInicio(equipe elenco) {
    noh* novo = new noh(elenco);
    if (vazia()) {
        primeiro = novo;
        ultimo = novo;
    } else {
        novo->proximo = primeiro;
        primeiro = novo;
    }
    tamanho++;
}

// Insere em uma posição específica
void lista::insereNaPosicao(int posicao, equipe elenco) {
    if (posicao < 0 || posicao > tamanho) {
        cout << "Posição Inexistente!" << endl;
        return;
    }
    if (posicao == 0) {
        insereNoInicio(elenco);
    } else if (posicao == tamanho) {
        insereNoFim(elenco);
    } else {
        noh* novo = new noh(elenco);
        noh* aux = primeiro;
        for (int i = 0; i < posicao - 1; i++) {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        tamanho++;
    }
}

// Procura por uma equipe pelo nome e retorna a posição
int lista::procura(string valor) {
    noh* aux = primeiro;
    int posicao = 0;
    while (aux != NULL) {
        if (aux->elenco.nomeEquipe == valor) {
            return posicao;
        }
        aux = aux->proximo;
        posicao++;
    }
    return -1; // Não encontrado
}

// Imprime a lista de equipes
void lista::imprime() {
    if (vazia()) {
        cout << "Lista vazia!" << endl;
    } else {
        noh* aux = primeiro;
        while (aux != NULL) {
            cout << "(" << aux->elenco.nomeEquipe << ", " 
                 << aux->elenco.lider << ", " 
                 << aux->elenco.linguagem << ", " 
                 << aux->elenco.qtdMembros << ")" << endl;
            aux = aux->proximo;
        }
    }
}

// Verifica se a lista está vazia
bool lista::vazia() {
    return (primeiro == NULL);
}

// Remove do final da lista
void lista::removeNoFim() {
    if (vazia()) {
        cout << "Remoção em lista vazia!" << endl;
        return;
    }
    if (primeiro == ultimo) {
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
    } else {
        noh* aux = primeiro;
        while (aux->proximo != ultimo) {
            aux = aux->proximo;
        }
        delete ultimo;
        ultimo = aux;
        ultimo->proximo = NULL;
    }
    tamanho--;
}

// Remove do início da lista
void lista::removeNoInicio() {
    if (vazia()) {
        cout << "Remoção em lista vazia!" << endl;
        return;
    }
    noh* aux = primeiro;
    primeiro = aux->proximo;
    delete aux;
    if (primeiro == NULL) {
        ultimo = NULL;
    }
    tamanho--;
}

int main() {
    lista minhaLista;
    equipe info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        cin >> comando;
        switch (comando) {
            case 'i': // Inserir no início
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNoInicio(info);
                break;
            case 'h': // Inserir no fim
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNoFim(info);
                break;
            case 'm': // Inserir na posição
                cin >> posicao >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNaPosicao(posicao, info);
                break;
            case 's': // Procurar por nome
                cin >> nomeEquipe;
                if (minhaLista.procura(nomeEquipe) != -1) {
                    cout << minhaLista.procura(nomeEquipe) << endl;
                } else {
                    cout << "Nao encontrado" << endl;
                }
                break;
            case 'r': // Remover no início
                minhaLista.removeNoInicio();
                break;
            case 'a': // Remover no fim
                minhaLista.removeNoFim();
                break;
            case 'p': // Imprimir lista
                minhaLista.imprime();
                break;
            case 'f': // Finalizar
                break;
            default:
                cerr << "Comando inválido!" << endl;
        }
    } while (comando != 'f');

    return 0;
}
