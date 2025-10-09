#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "../include/Objeto.hpp"
#include "../include/Cena.hpp"

int main() {
    std::string linha;
    int numObjs = 0;

    Objeto objetos;

    std::cout << "Programa iniciado" << std::endl;

    while(std::getline(std::cin, linha)) {
        char tipo = linha[0];
        std::string dados = linha.substr(1);
        
        std::istringstream iss(dados);

        if(tipo == 'O') {
            int id;
            double x, y, largura;
            iss >> id >> x >> y >> largura;
            objetos.inserir(id, x, y, largura);
            numObjs++;
            std::cout << "Objeto registrado" << std::endl;
        }
        if(tipo == 'M') {
            int id, tempo;
            double x, y;
            iss >> tempo >> id >> x >> y;
            objetos.movimentaObjeto(id, x, y);
            objetos.ordenaPorY();
            std::cout << "Comando Movimentacao registrado" << std::endl;
        }
        if(tipo == 'C') {
            objetos.ordenaPorY(); //Retirar esse trecho posteriormente
            int tempo;
            iss >> tempo;
            Cena(tempo, numObjs, &objetos);
            std::cout << "Comando Cena registrado" << std::endl;
        }

    }
    std::cout << "Programa encerrado" << std::endl;
    return 0;
}