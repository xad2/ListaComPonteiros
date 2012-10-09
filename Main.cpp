/*
 * Main.cpp
 *
 *  Created on: Oct 8, 2012
 *      Author: xad
 */

#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Lista.h"


//método que remove da posição
static void comandoRemoverDaPosicao(std::istream &stream, std::istream &file, Lista &lista) {
    int pos;
    stream >> pos;
    lista.retirarDaPosicao(pos);
}

static void comandoRemoverMembro(std::istream &stream, std::istream &file, Lista &lista) {
    int qtd;
    stream >> qtd;

    char line[10000];
    for (int i = 0; i < qtd; i++) {

        file.getline(line, 10000);

        // No need to copy, we are just reading here
        //char *lancamento = new char[strlen(line)];
        //strcpy(lancamento, line);

        if (lista.contem(line)) {
            lista.retirarEspecifico(line);
            //break;
        }

    }

}

static void comandoMostrar(Lista &lista) {
    for (int i = 0; i < lista.numeroElementos(); i++)
        std::cout << lista.retornarLancamento(i) << std::endl;
}

static void comandoInserirEmOrdem(std::istream &stream, std::istream &file, Lista &lista) {
    int qtd;
    stream >> qtd;

    char line[10000];

    for (int i = 0; i < qtd; i++) {
        file.getline(line, 10000);

        /// we dont need to create a copy
        /// Lista does this for us
        //char *lancamento = new char[strlen(line)];
        //strcpy(lancamento, line);

        lista.adicionarEmOrdem(line);

    }

}

static void comandoInserirNaPosicao(std::istream &stream, std::istream &file, Lista &lista) {

    int qtd;
    stream >> qtd;

    int pos;
    stream >> pos;

    char line[10000];

    for (int i = 0; i < qtd; i++) {
        file.getline(line, 10000);

        /// we dont need to create a copy
        /// Lista does this for us
        //char *lancamento = new char[strlen(line)];
        //strcpy(lancamento, line);

        // Is this necessary?
        //lista.adicionarEmOrdem(line);

        lista.adicionaNaPosicao(line, pos);

    }

}
static void comandoInserir(std::istream &stream, std::istream &file, Lista &lista) {
    int qtd;
    stream >> qtd;

    char line[10000];

    for (int i = 0; i < qtd; i++) {

        file.getline(line, 10000);

        /// we dont need to create a copy
        /// Lista does this for us
        // char *lancamento = new char[strlen(line)];

        lista.adicionar(line);
    }

}



// Método (incompleto) que executa o menu interativo. A ideia foi usar um ponteiro (*listaAtual) e, quando selecionado, ele apontaria para
// o tipo de conta.
static void execucaoInterativa() {

}

//Método que roda o caso de testes.
static void execucaoDeTestes(const std::string &filename) {

    Lista listaAtual;

    std::ifstream file(filename.c_str());
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::string command = line;
        stream >> command;

        if (command == "CRIAR") {
            listaAtual.limpar();
        } else if (command == "INSERIR") {
            comandoInserir(stream, file, listaAtual);
        } else if (command == "INSERIR_EM_ORDEM") {
            comandoInserirEmOrdem(stream, file, listaAtual);
        } else if (command == "INSERIR_NA_POSICAO") {
            comandoInserirNaPosicao(stream, file, listaAtual);
        } else if (command == "MOSTRAR") {
            comandoMostrar(listaAtual);
        } else if (command == "REMOVER") {
            listaAtual.retirar();
        } else if (command == "REMOVER_MEMBRO") {
            comandoRemoverMembro(stream, file, listaAtual);
        } else if (command == "REMOVER_DA_POSICAO") {
            comandoRemoverDaPosicao(stream, file, listaAtual);
        }

    }
}

int main(int argc, char** argv) {

    if (argc < 2) {
        execucaoInterativa();
    } else {
        execucaoDeTestes(argv[1]);
    }

}

