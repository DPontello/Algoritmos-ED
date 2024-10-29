/*
Considere os TADs e métodos estudados para a implementação de uma pilha. Implemente um método inverter() que, dada a chamada P1.inverter(), a ordem dos elementos de P1 é invertida. Os elementos da pilha devem continuar armazenados em P1 após a inversão.

Você pode utilizar o código base fornecido no enunciado.

Dica: utilize estruturas auxiliares para a inversão.

Entradas:

Número de elementos a serem inseridos em P1.
Elementos de P1 em ordem de inserção
Saídas:

Elementos da pilha P1, após inversão
Exemplo de Entrada 1:

5
3 6 8 1 9 (elementos impressos em ordem de inserção)
Exemplo de Saída1:

3 6 8 1 9 (elementos desempilhados após a inversão da pilha P1)
Exemplo de Entrada 2:

10
5 1 2 3 8 6 1 9 12 19 (elementos impressos em ordem de inserção)
Exemplo de Saída2:

5 1 2 3 8 6 1 9 12 19 (elementos desempilhados após a inversão da pilha P1)
Exemplo de Entrada 3:
23
1 3 5 7 9 0 2 4 6 8 11 13 15 17 19 10 12 14 16 18 21 23 25  (elementos impressos em ordem de inserção)
Exemplo de Saída3:

1 3 5 7 9 0 2 4 6 8 11 13 15 17 19 10 12 14 16 18 21 23 25 (elementos desempilhados após a inversão da pilha P1)
*/

#include <iostream>
using namespace std;

class dado{
    friend class pilha;
    private:
    int elemento;
    dado *proximo;

    public:
    dado(int v){
        elemento = v;
        proximo = NULL;
    }
};

class pilha{
	private:
		dado *topo;
	public:
		pilha(){
			topo = NULL;
		}
		void empilha (dado entrada){
			dado *novo = new dado(entrada);
			*novo = entrada;
			novo->proximo = topo;
			topo = novo;
		}
		int desempilha(){
			if (topo == NULL) throw runtime_error("Pilha vazia!");
			int removido;
			dado *apagado = topo;
			removido = topo->elemento;
			topo = topo->proximo;
			apagado->proximo = NULL;
			delete apagado;
			return removido;
		}
		~pilha(){
			while (topo != NULL)
				desempilha();
		}		
		void inverte(){
            pilha aux1, aux2;
            while(this->topo != NULL){
                aux1.empilha(this->desempilha());
            }
            while(aux1.topo!= NULL){
                aux2.empilha(aux1.desempilha());
            }
            while(aux2.topo!= NULL){
                empilha(aux2.desempilha());
            }
        }
            


		void imprime(){
            while(this->topo != NULL){
                cout << desempilha() << " ";
		    }
        cout << endl;
        }		

	};
int main(){
	int tamanho;
	cin >> tamanho;
	int valor;
	pilha mp;
	for (int i=0; i<tamanho; i++){
		cin >> valor;
		mp.empilha(valor);
	}
	
    mp.inverte();
	mp.imprime();
	
    return 0;
}