/*
 * ListaContabil.h
 *
 *  Created on: Sep 29, 2012
 *      Author: Alexandre e Tao
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <string>

const int MAXLISTA = 100;

class Lista {

private:
    /// This array holds the POINTERS to data, it is an array of pointers
    /// Each position has the address of the memory that actually holds the data
    char* lista[MAXLISTA];

    /// This index points to the last element of the list, inclusive
    /// the list have ultimo+1 elements
    int ultimo;

    /// we dont allow copy constructor and assignment operator for now
    /// since we manage memory by hand we have to implement these
    /// the default leak memory and dont copy the data properly
    Lista(const Lista &);
    Lista& operator=(const Lista &);

public:
    Lista();
    ~Lista();

    /// const because these methods do not change the object's state, i.e. they "read" and dont "write" memory
    bool listaCheia() const;
    bool listaVazia()  const;
    bool contem(const char* dado) const;
    int posicao(const char* dado) const;
    std::string retornarUltimo() const;
    std::string retornarLancamento(int pos) const;
    int numeroElementos() const { return ultimo + 1; }

    ///  ************ Important *********************
    ///  When we add strings to the list we copy the string we are adding to the list.
    ///  That's why all these methods have const char* as parameter.
    ///  What should these functions return? Error code? Why dont we return bool?
    int adicionar(const char* dado); ///< returns < 0 if error
    int adicionarNoInicio(const char* dado);
    int adicionaNaPosicao(const char* dado, int pos_destino);
    int adicionarEmOrdem(const char* dado);

    /// Clears the list, deallocating the memory
    void limpar();

    /// When we remove elements we deallocate memory, wiping out the data
    /// What should these functions return? A copy of the removed string or an error code?
    int retirar();
    int retirarDoInicio();
    int retirarDaPosicao(int pos);
    int retirarEspecifico(const char* dado);
};

#endif /* LISTA_H_ */
