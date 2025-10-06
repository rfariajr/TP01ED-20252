#ifndef TRECHO_HPP
#define TRECHO_HPP

class Objeto;

class Trecho {
    private:
        int id;
        double inicio;
        double fim;
        Trecho* proximo;
        Objeto* objetos; //Ponteiro para o vetor de Objeto
        int tamanhoObjetos; //Tamanho do vetor de Objeto

    public:
        Trecho(int id, double inicio, double fim, Objeto* objetos, int tamanhoObjetos); //Construtor
        ~Trecho(); //Destrutor
        Trecho* getProximo(); //Obtem o ponteiro próximo
};

#endif //TRECHO_HPP