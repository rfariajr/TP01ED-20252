#include "../include/Cena.hpp"
#include "../include/Trecho.hpp"
#include <iostream>

//Construtor padrão
Cena::Cena() {
    tempo = -1;
    primeiro = nullptr;
    objetos = nullptr;
    tamanhoObjetos = 0;
}

//Construtor
Cena::Cena(int tempo, Objeto* objetos, int tamanhoObjetos) {
    //Encontra o menor X que será 
    this -> tempo = tempo;
    this -> primeiro = nullptr;
    this -> objetos = objetos;
    this -> tamanhoObjetos = tamanhoObjetos;
    int xMin = menorX(objetos, tamanhoObjetos);
}

//Destrutor
Cena::~Cena() {
    Trecho *atual = primeiro;
    while(atual != nullptr) {
        Trecho *proximo = atual -> getProximo();
        delete atual;
        atual = proximo;
    }
}

int Cena::menorX(Objeto *objetos, int tamanhoObjetos) const {

}

void Cena::adicionaTrecho() {

}

void Cena::imprimeCena() {

}