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
	char* lista[MAXLISTA];
	int ultimo;

public:
	Lista();
	~Lista();

	bool listaCheia ();
	bool listaVazia ();
	bool contem(const char* dado);


	void inicializar();
	void destruir();
	int adicionar(char* dado);
	int adicionarNoInicio(char* dado);
	int adicionaNaPosicao(char* dado, int pos_destino);
	int adicionarEmOrdem(char* dado);
	int retirar();
	int retirarDoInicio();
	int retirarDaPosicao(int pos);
	int retirarEspecifico( char* lancamento);
	int posicao(char* dado);
	int retornarUltimo();
	std::string retornarLancamento(int pos);
};

#endif /* LISTA_H_ */
