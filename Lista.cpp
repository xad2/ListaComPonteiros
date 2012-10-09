/*
 * ListaContabil.cpp
 *
 *  Created on: Sep 29, 2012
 *      Author: Alexandre e Tao
 */

#include "Lista.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>

Lista::Lista() 
    : ultimo(-1)
{
    for (int i = 0; i < MAXLISTA; ++i)
        lista[i] = NULL;
}

Lista::~Lista() {
    limpar();
}

void Lista::limpar() {
    while (!listaVazia())
        retirar();
}

bool Lista::listaCheia() const {
    return ultimo + 1 == MAXLISTA;
}

bool Lista::listaVazia() const {
    return ultimo == -1;
}

//Adiciona no final
int Lista::adicionar(const char* dado) {
    return adicionaNaPosicao(dado, ultimo + 1);
}

int Lista::adicionarNoInicio(const char* dado) {
    return adicionaNaPosicao(dado, 0);
}

//Retira do último.
int Lista::retirar() {
    return retirarDaPosicao(ultimo);
}

int Lista::retirarDoInicio() {
    return retirarDaPosicao(0);
}

//Adiciona na posição do argumento dado.
int Lista::adicionaNaPosicao(const char* lancamento, int pos_destino) {

    int pos;

    if (listaCheia() || pos_destino > ultimo + 1 || pos_destino < 0) {
        return -1;
    }

    //// find out the size of the string to be inserted
    //// this is very dangerous as we assume the input string is '\0' terminated
    //// a malicious user may pass an ill-formed and/or huge string
    size_t length = strlen(lancamento);

    //// we could return -1 here
    assert(length < 10000);

    //// Suppose we have this list:
    //// [A, B, C]
    ////        ^ ultimo
    //// And we want to insert D in pos = 1
    //// so that in the end we would have
    //// [A, D, B, C]
    ////           ^ ultimo

    //// [A, D, B, C, NULL]
    ////                 ^ ultimo
    ultimo++;
    pos = ultimo;

    while (pos > pos_destino) {
        lista[pos] = lista[pos - 1];
        pos--;
    }
    //// When the while loop exits we have
    //// [A, B, B, C]
    ////           ^ ultimo

    //// [A, D, B, C]
    ////           ^ ultimo
    lista[pos_destino] = new char[length + 1]; //// allocate memory to the destination buffer
    strncpy(lista[pos_destino], lancamento, length); //// copy data from src to dst
    lista[pos_destino][length] = '\0'; //// make sure we '\0' the dst buffer, very important!

    return pos_destino;
}

//Remove um lançamento de acordo com a posição dada.
int Lista::retirarDaPosicao(int pos_fonte) {

    if (pos_fonte > ultimo || pos_fonte < 0 || listaVazia()) {
        return -1;
    }

    // make a copy
    // we use std:string because it handles memory allocation/deallocation for us automatically
    std::string removedValue = lista[pos_fonte];

    //// Suppose we have a list like this:
    //// [A, B, C]
    ////        ^ ultimo
    //// And we want to remove the second item
    //// so that in the end we would have
    //// [A, C, NULL]
    ////     ^ ultimo

    //// [A, NULL, C]
    ////           ^ ultimo
    delete[] lista[pos_fonte]; // we have to delete memory! avoiding leaks
    lista[pos_fonte] = NULL;

    int pos = pos_fonte;
    while (pos < ultimo) {
        lista[pos] = lista[pos + 1];
        pos++;
    }
    //// When the while loop exits we have
    //// [A, C, C]
    ////        ^ ultimo

    //// [A, C, NULL]
    ////           ^ ultimo
    lista[ultimo] = NULL; //// Note that we moved the pointer, we didnt copy data
    
    //// [A, C, NULL]
    ////           ^ ultimo
    ultimo--;

    // return removedValue; ?
    return 1;
}

//Olha se o lançamento está contido
bool Lista::contem(const char* lancamento) const {
    return posicao(lancamento) > 0;
}

int Lista::adicionarEmOrdem(const char* lancamento) {
    if (listaCheia())
        return -1;

    int pos = 0;
    while (pos <= ultimo && strcmp(lancamento, lista[pos]) > 0) {
        pos++;
    }

    return adicionaNaPosicao(lancamento, pos);
}

//Retorna posição lançamento.
int Lista::posicao(const char* lancamento) const {
    for (int i = 0; i <= ultimo; i++) {
        if (strcmp(lancamento, lista[i]) == 0)
            return i;
    }
    return -1;
}

//Retira dado elemento
int Lista::retirarEspecifico(const char* lancamento) {
    int pos = posicao(lancamento);
    if (pos < 0)
        return -1;
    return retirarDaPosicao(pos);
}

std::string Lista::retornarUltimo() const {
    return lista[ultimo];
}

std::string Lista::retornarLancamento(int pos) const {
    return lista[pos];
}
