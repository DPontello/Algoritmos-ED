/*
Implemente uma estrutura de dados pilha, utilizando encadeamento de nós,
para implementar um inventário de itens em um jogo digital. A estrutura deve
possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens,
verificação do item no topoPilha da pilha e limpeza do inventário (remoção de todos os elementos da pilha).
O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"),
quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos:
nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

    i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
    r: para retirar um item do inventário
    l: para limpar (remover todos) os itens do inventário
    e: para espiar o topoPilha do inventário (escreve o topoPilha sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido.
Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
*/

#include <iostream>
using namespace std;