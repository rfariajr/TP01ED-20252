#include "../include/Objeto.hpp"
#include <iostream>

Objeto::Objeto() {
    cabeca = nullptr;
}

Objeto::~Objeto() {
    No* atual = cabeca;
    while(atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}
/*
//Contrutror padrão
Objeto::Objeto() {
    id = 0;
    x = -1.0;
    y = -1.0;
    largura = 0.0;
}

//Constrututor
Objeto::Objeto(int id, double x, double y, double largura) {
    this -> id;
    this -> x;
    this -> y;
    this -> largura;
}
*/

void Objeto::inserir(int id, double x, double y, double largura) {
    No* novoNo = new No;
    novoNo->id = id;
    novoNo->x = x;
    novoNo->y = y;
    novoNo->largura = largura;
    novoNo->proximo = nullptr;

    //Novo nó é a cabeça se a lista é vazia
    if(cabeca == nullptr) {
        cabeca = novoNo;
        return;
    }
    
    No* atual = cabeca;
    
    //Insere o novo No no final caso a lista não seja vazia
    while(atual->proximo != nullptr) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
}

void Objeto::movimentaObjeto(int id, double x, double y) {
    No* procurado = procuraObjeto(id);

    if(procurado != nullptr) {
        procurado->x = x;
        procurado->y = y;        
    }
    return;
}

No* Objeto::procuraObjeto(int id) {
    No* atual = cabeca;

    while(atual != nullptr) {
        if(atual->id == id) {
            return atual; //Retorna o No com o id procurado
        }
        atual = atual->proximo;
    }
    return nullptr; //Nulo caso não haja o id procurado
}

void Objeto::ordenaPorY() {
    
} 