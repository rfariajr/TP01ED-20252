#include "../include/Cena.hpp"
#include "../include/Objeto.hpp"
#include <iostream>

class Objeto;

//Construtor
Cena::Cena(int tempo, int numObjetos, Objeto* objetos) {
    this->tempo = tempo;
    this->numObjetos = numObjetos;
    primeiro = nullptr;

    for(int i = 0; i < numObjetos; i++) {
        adicionaTrecho(i, objetos);
    }
}

//Destrutor
Cena::~Cena() {
    Trecho* atual = primeiro;
    while(atual != nullptr) {
        Trecho *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

void Cena::adicionaTrecho(int indice, Objeto* objetos) {
    No* atual = objetos->cabeca;
    Trecho* novoTrecho;
    for(int i = 0; i < indice; i++) {
        atual = atual->proximo;
    }

    if(primeiro == nullptr) {
        primeiro = novoTrecho;
        novoTrecho->id = atual->id;
        novoTrecho->inicio = atual->x - (atual->largura / 2);
        novoTrecho->fim = atual->x + (atual->largura / 2);            
        return;
    }

    
    //Implementar a função para definição de trecho

    //Insere no fim da lista
    Trecho* tAtual = primeiro;
    while(tAtual->proximo != nullptr) {
        tAtual = tAtual->proximo;
    }
    tAtual->proximo = novoTrecho;
}

void Cena::imprimeCena() {

}