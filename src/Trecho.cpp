#include "../include/Trecho.hpp"
#include "../include/Objeto.hpp"
#include <iostream>

//Construtor
Trecho::Trecho(int id, double inicio, double fim, Objeto* objetos, int tamanhoObjetos) {
    //Alterar a função para construção do trecho
    this -> inicio = inicio;
    this -> fim = fim;
    this -> proximo = nullptr;
}

//Destrutor
Trecho::~Trecho() {
    
}

//Obtem o próximo ponteiro
Trecho *Trecho::getProximo() {
    return proximo;
}