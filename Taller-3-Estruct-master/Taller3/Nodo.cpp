#include "pch.h"
#include "Nodo.h"


Nodo::Nodo(int m, bool esHijo)
{
	this->esHijo = esHijo;
	this->tienehijos = false;
	for (int i = 0; i < m; i++) {
		this->hijos.push_back(nullptr);
	}
}

void Nodo::limpiarHijos()
{
	this->hijos.clear();
	for (int i = 0; i < this->hijos.size() - 1; i++) {
		this->hijos.push_back(nullptr);
	}
}

int Nodo::retornarPos(int num)
{
	for (int i = 0; i < this->idclaves.size(); i++) {
		if (this->idclaves[i] == num) return i;
	}
	return -1;
}




Nodo::~Nodo()
{
}
