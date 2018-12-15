#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

class ArbolB
{
public:
	ArbolB(int m);
	void agregarDato(int id);
	bool isOverflow(Nodo* nodo);
	void imprimir();
	~ArbolB();

private:
	Nodo* buscarNodoAgregacion(Nodo* nodo, int id);
	Nodo* buscarNodoAnterior(Nodo * nodo, Nodo * nodo_original);
	void agregarDato(Nodo* nodo, int id);
	void imprimirArbol(Nodo* nodo);

	int m;
	Nodo* raiz;
};

