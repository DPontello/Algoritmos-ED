#include <iostream> 
using namespace std;

struct noh{
    const int dado;
    noh* prox;
    noh* ante;
};

class lista{
    private: 
    noh* primeiro;
    noh* ultimo;

    public: 

    void funcA(){
        noh* noh1 = primeiro;
        noh *noh2;
        noh *noh3;

        while(noh1 != NULL){
            noh2 = noh1->ante;
            noh3 = noh1->prox;

            if(noh1->dado % 2 == 0){
                if(noh2 != NULL)
                    noh2->prox = noh3;
                else 
                    primeiro = noh1->prox;
                if (noh3 != NULL)
                    noh3->ante = noh2;
                else 
                    ultimo = noh1->ante;
                delete noh1;
            }
            noh1 = noh3;
        }
    }


    void funB(){
        noh *noh1 = primeiro;
        noh *noh2;

        while(noh1 != NULL){
             noh2 = noh1->prox;
             noh1->prox = noh1->ante;
             noh1->ante = noh2;
             noh1= noh2;
        }
        noh2 = ultimo;
        ultimo = primeiro;
        primeiro = noh2;
    }

};

int main(){
    lista lista1, lista2;

    int m, n;
    
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        list.inse
    }
}