#ifndef CENA_HPP
#define CENA_HPP

class Objeto;

struct Trecho {
    int id;
    double inicio, fim;
    Trecho* proximo;
};


class Cena {
    private:
        int tempo, numObjetos; //
        Trecho* primeiro; //Ponteiro para o primeiro trecho da lista 

    public:        
        Cena(int tempo, int numObjetos, Objeto* objetos);
        ~Cena(); //Destrutor
        void adicionaTrecho(int numObjetos, Objeto* objetos); //Adiciona um Trecho a Cena
        void imprimeCena(); //Imprime a cena

};

#endif //CENA_HPP