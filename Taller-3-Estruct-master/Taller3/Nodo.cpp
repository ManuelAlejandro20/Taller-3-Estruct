#include "pch.h"
#include "Nodo.h"


Nodo::Nodo(int m, bool esHijo)
{
	for (int i = 0; i < m; i++) {
		this->hijos.push_back(nullptr);
	}
}

void Nodo::limpiarHijos()
{
	int largo = this->hijos.size();
	this->hijos.clear();
	for (int i = 0; i < largo; i++) {
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

bool Nodo::esHijo(Nodo * nodo)
{
	if (nodo == nullptr) {
		return false;
	}
	for (int i = 0; i < this->hijos.size(); i++) {
		if (this->hijos[i] == nodo) {
			return true;
		}
	}
	return false;
}

bool Nodo::tieneHijos()
{
	for (int i = 0; i < this->hijos.size(); i++) {
		if (this->hijos[i] != nullptr) {
			return true;
		}
	}
	return false;
}




Nodo::~Nodo()
{
}
