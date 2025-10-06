#ifndef CENA_HPP
#define CENA_HPP

class Trecho;
class Objeto;

class Cena {
    private:
        int tempo;
        Trecho* primeiro; //Ponteiro para o primeiro trecho da lista 
        Objeto* objetos; //Ponteiro para o vetor de Objeto
        int tamanhoObjetos; //Tamanho do vetor de Objeto

    public:        
        Cena(); //Construtor padrão
        Cena(int tempo, Objeto* objetos, int tamanhoObjetos);
        ~Cena(); //Destrutor
        int menorX(Objeto* objetos, int tamanhoObjetos) const;
        void adicionaTrecho(); //Adiciona um Trecho a Cena
        void imprimeCena(); //Imprime a cena

};

#endif //CENA_HPP