#include "../include/Objeto.hpp"
#include <iostream>

//Construtor
Objeto::Objeto() {
    cabeca = nullptr;
}

//Destrutor
Objeto::~Objeto() {
    No* atual = cabeca;
    while(atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

//Inserir no final
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

No* Objeto::dividir(No* cabeca) {
    No *l = cabeca, *r = cabeca->proximo;

    while(r != nullptr && r->proximo != nullptr) {
        l = l->proximo;
        r = r->proximo->proximo;
    }

    No* segundaMetade = l->proximo;
    l->proximo = nullptr; //Devide a lista em duas partes
    return segundaMetade;
}

No* Objeto::merge(No* esquerda, No* direita) {
    No aux;
    No* atual = &aux;

    aux.proximo = nullptr;

    while(esquerda != nullptr && direita != nullptr) {
        if(esquerda->y < direita->y || (esquerda->y == direita->y && esquerda->x < direita->x)) {
            atual->proximo = esquerda;
            esquerda = esquerda->proximo;
        }
        else {
            atual->proximo = direita;
            direita = direita->proximo;
        }
        atual = atual->proximo;
    }

    if(esquerda != nullptr) {
        atual->proximo = esquerda;
    }
    else {
        atual->proximo = direita;
    }

    return aux.proximo;
}

No* Objeto::mergeSort(No* cabeca) {
    if(cabeca == nullptr || cabeca -> proximo == nullptr) {
        return cabeca; //lista vazia ou com ume elemento
    }

    //Divide a lista
    No* segundaMetade = dividir(cabeca);

    //Ordena recursivamente as duas metades
    cabeca = mergeSort(cabeca);
    segundaMetade = mergeSort(segundaMetade);

    //Junta as metades ordenadas
    return merge(cabeca, segundaMetade);
}

void Objeto::ordenaPorY() {
    cabeca = mergeSort(cabeca);
} 