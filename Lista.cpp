/*
 * ListaContabil.cpp
 *
 *  Created on: Sep 29, 2012
 *      Author: Alexandre e Tao
 */

#include "Lista.h"
#include <cstring>

Lista::Lista() {

	ultimo = -1;
}

Lista::~Lista() {
	ultimo = -1;
}

void Lista::inicializar() {
	ultimo = -1;
}

bool Lista::listaCheia() {
	if (ultimo + 1 == MAXLISTA) {
		return true;
	}
	return false;
}

bool Lista::listaVazia() {
	if (ultimo == -1) {
		return true;
	}
	return false;
}

//Adiciona no final
int Lista::adicionar(const char* lancamento) {

	if (listaCheia()) {
		return '\0';
	}

	ultimo++;

	strcpy(lista[ultimo], lancamento);
	return ultimo;

}

int Lista::adicionarNoInicio(const char* lancamento) {

	int pos;
	if (listaCheia()) {
		return '\0';

	}

	ultimo++;
	pos = ultimo;

	while (pos > 0) {
		lista[pos] = lista[pos - 1];
		pos--;
	}

	strcpy(lista[0], lancamento);

	return ultimo;

}

//Retira do último.
int Lista::retirar() {
	if (listaVazia()) {
		return '\0';
	}
	ultimo--;
	return ultimo;

}

int Lista::retirarDoInicio() {

	int pos;
	char *valor;

	if (listaVazia()) {
		return '\0';
	}
	ultimo--;
	strcpy(valor, lista[0]);
	pos = 0;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];
		pos++;

	}

	return *valor;

}

//Adiciona na posição do argumento dado.
int Lista::adicionaNaPosicao(const char* lancamento, int pos_destino) {

	int pos;

	if (listaCheia())
		return '\0';
	else if (pos_destino > ultimo + 1 || pos_destino < 0) {
		return '\0';
	}

	ultimo++;
	pos = ultimo;

	while (pos > pos_destino) {
		lista[pos] = lista[pos - 1];

		pos--;
	}

	strcpy(lista[pos_destino], lancamento);

	return pos_destino;

}
//Remove um lançamento de acordo com a posição dada.
int Lista::retirarDaPosicao(int pos_fonte) {

	int pos;
	char *valor;
	if (pos_fonte > ultimo || pos_fonte < 0) {
		return '\0';
	} else if (listaVazia()) {
		return '\0';
	}

	ultimo--;

	strcpy(valor, lista[pos_fonte]);
	pos = pos_fonte;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];

		pos++;
	}

	return *valor;

}

//Olha se o lançamento está contido
bool Lista::contem(const char* lancamento) {
	for (int i = 0; i <= ultimo; i++) {
		if (lancamento == lista[i])
			return true;
	}

	return false;
}

int Lista::adicionarEmOrdem(const char* lancamento) {
	int pos;

	if (listaCheia())
		return '\0';

	pos = 0;
	while (pos <= ultimo && lancamento > lista[pos]) {
		pos++;
	}

	return adicionaNaPosicao(lancamento, pos);
}

//Retorna posição lançamento.
int Lista::posicao(const char* lancamento) {

	int pos = 0;

	while (pos <= ultimo && (lancamento != lista[pos])) {
		pos++;
	}
	if (pos > ultimo)
		return '\0';

	return pos;

}

//Retira dado elemento
int Lista::retirarEspecifico(const char* lancamento) {

	int pos;
	if (listaVazia())
		return '\0';

	pos = posicao(lancamento);
	if (pos < 0)
		return '\0';

	return retirarDaPosicao(pos);

}

int Lista::retornarUltimo() {
	return ultimo;
}
char Lista::retornarLancamento(int pos) {
	return *lista[pos];
}
