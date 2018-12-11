#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

class ArbolB
{
public:
	ArbolB(int m);
	Nodo* buscarNodoAgregacion(Nodo* nodo, int id);
	Nodo * buscarNodoAnterior(Nodo * nodo, Nodo * nodo_original, int id);
	void agregarDato(int id);
	void agregarDato(Nodo* nodo, int id);
	bool isOverflow(Nodo* nodo);
	void imprimir();
	void imprimirArbol(Nodo* nodo);
	~ArbolB();

private:
	int m;
	Nodo* raiz;
};

