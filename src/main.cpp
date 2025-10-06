#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "../include/Objeto.hpp"

int main() {
    std::string linha;

    Objeto objetos;

    while(std::getline(std::cin, linha)) {
        char tipo = linha[0];
        std::string dados = linha.substr(1);
        
        std::istringstream iss(dados);

        if(tipo == 'O') {
            int id;
            double x, y, largura;
            iss >> id >> x >> y >> largura;
            objetos.inserir(id, x, y, largura);
        }
        if(tipo == 'M') {
            int id, tempo;
            double x, y;
            iss >> tempo >> id >> x >> y;
            objetos.movimentaObjeto(id, x, y);
        }
        if(tipo == 'C') {

        }

    }
    return 0;
}