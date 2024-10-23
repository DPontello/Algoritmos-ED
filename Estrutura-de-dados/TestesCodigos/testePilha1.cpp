#include <iostream>
using namespace std;

class Stack{
private: 
    int *array; //array para armazenar os elementos da pilha
    int top; // indice do topo da pilha
    int capacity; //capacidade maxima da pilha

public:
Stack(int size);
~Stack();
void push(int value);
int pop();
int peek();
bool isEmpty();
bool isFull();
int size();
};

Stack::Stack(int size){
    array = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack(){
    delete[] array;
}

void Stack::push(int value){ //add a value to stack
    if(isFull()){
        cout << "Pilha cheia. Não é possível adicionar mais elementos." << endl;
    }
    array[top++] = value;
}

int Stack::pop(){ //remove o elemento do topo da pilha
    if(isEmpty()){
        cout << "Pilha vazia. Não é possível remover elementos." << endl;
        return -1;
    }
    return array[top--];
}

int Stack::peek(){  //pick top
    if(isEmpty()){
        cout << "Pilha vazia. Não é possível verificar o topo." << endl;
        return -1;
    }
    return array[top];
}

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity - 1;
}

int Stack::size(){ // return size
    return top + 1;
}

int main(){
    Stack stack(5); // criação de uma pilha com 5 elementos

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout <<"Elemento do topo: " << stack.peek() << endl;

    stack.pop();

    cout << "Elemento no topo apos pop: " << stack.peek() << endl;

    return 0;
}