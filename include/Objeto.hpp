#ifndef OBJETO_HPP
#define OBJETO_HPP

struct No {
    int id;
    double x, y, largura;
    No* proximo;
};


class Objeto {
    private:
        No* cabeca;

        //Funções para ordenar a lista
        No* dividir(No* cabeca);
        No* merge(No* esquerda, No* direita);
        No* mergeSort(No* cabeca);        
    public:
        Objeto(); //Construtor padrão
        ~Objeto();
        void inserir(int id, double x, double y, double largura);
        void movimentaObjeto(int id, double x, double y);
        No* procuraObjeto(int id);
        void ordenaPorY(); //Ordena usando mergesort
};

#endif // OBJETO_HPP