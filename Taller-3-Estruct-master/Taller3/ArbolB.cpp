#include "pch.h"
#include "ArbolB.h"


ArbolB::ArbolB(int m)
{
	this->raiz = new Nodo(m, false);
	this->m = m;
}

Nodo * ArbolB::buscarNodoAgregacion(Nodo* nodo, int id) //busca el nodo al que hay que agregar
{
	if (!nodo->tieneHijos()) {
		return nodo;
	}
	if (id > nodo->idclaves[nodo->idclaves.size() - 1]) {
		return buscarNodoAgregacion(nodo->hijos[nodo->idclaves.size()], id);
	}
	for (int i = 0; i < nodo->idclaves.size(); i++)
	{
		if (id < nodo->idclaves[i]) {
			return buscarNodoAgregacion(nodo->hijos[i], id);
		}
	}
}

Nodo * ArbolB::buscarNodoAnterior(Nodo * nodo, Nodo* nodo_original) // retorna el nodo anterior al nodo de agregacion
{
	if (nodo != nullptr) {
		if (nodo->esHijo(nodo_original)) {
			return nodo;
		}
		if (nodo->tieneHijos()) {
			for (int i = 0; i < m; i++) {
				if (buscarNodoAnterior(nodo->hijos[i], nodo_original) == nodo->hijos[i]) {
					return nodo->hijos[i];
				}
			}
			return nullptr;
		}
	}
	return nullptr;

}


void ArbolB::agregarDato(int id)
{
	agregarDato(buscarNodoAgregacion(this->raiz,id),id);
}


void ArbolB::agregarDato(Nodo* nodo, int id)
{
	if (isOverflow(nodo)) { // pregunta si esta lleno
		Nodo * nodoaux = nullptr;
		Nodo * nodoaux2 = nullptr;
		vector<int> aux = nodo->idclaves;
		aux.push_back(id);
		sort(aux.begin(), aux.end());
		int n = ceil((double)m / 2) - 1;
		if (nodo == this->raiz) {
			nodoaux = new Nodo(m, true);
			nodoaux2 = new Nodo(m, true);
			for (int i = 0; i < n; i++) // se copian los datos izquierdos al nodo izquierdo
			{
				nodoaux->idclaves.push_back(aux[i]);
				nodoaux->hijos[i] = nodo->hijos[i];
			}
			nodoaux->hijos[n] = nodo->hijos[n]; // residuo de referencia
			for (int i = n + 1; i < m; i++) { // se copian los datos derechos al nodo derecho
				nodoaux2->idclaves.push_back(aux[i]);
				nodoaux2->hijos[i - (n + 1)] = nodo->hijos[i];
			}
			nodoaux2->hijos[nodoaux->idclaves.size()] = nodo->hijos[m - 1]; // residuo
			nodo->idclaves.clear();
			nodo->limpiarHijos();
			nodo->idclaves.push_back(aux[n]);
			nodo->hijos[0] = nodoaux;
			nodo->hijos[1] = nodoaux2;
		}
		else {
			nodoaux = buscarNodoAnterior(this->raiz, nodo);
			int ind = 0;
			agregarDato(nodoaux, aux[n]);
			nodoaux = buscarNodoAnterior(this->raiz, nodo);
			nodoaux2 = new Nodo(this->m, true);
			for (int i = n + 1; i < m; i++) // se copian los datos del lado derecho al nuevo nodo
			{
				nodo->idclaves.pop_back();
				nodoaux2->idclaves.push_back(aux[i]);
				ind = i - (n + 1);
				nodoaux2->hijos[ind] = nodo->hijos[i];
				nodo->hijos[i] = nullptr;
			}
			int pos = nodoaux->retornarPos(aux[n]);
			for (int i = nodoaux->idclaves.size() - 1; i > pos - 1; i--) {
				if (i == pos) {
					nodoaux->hijos[i + 1] = nodoaux2;
					break;
				}
				nodoaux->hijos[i + 1] = nodoaux->hijos[i];
			}
		}
		nodoaux = nodoaux2 = NULL;
		delete nodoaux, nodoaux2;
		return;

	}
	nodo->idclaves.push_back(id); // si no esta lleno se agrega
	sort(nodo->idclaves.begin(), nodo->idclaves.end());
	return;
}

bool ArbolB::isOverflow(Nodo * nodo)
{
	return (nodo->idclaves.size() == (m - 1)) ? true : false;
}

void ArbolB::imprimir()
{
	cout << "" << endl;
	imprimirArbol(this->raiz);
}

void ArbolB::imprimirArbol(Nodo* nodo)
{
	if (nodo == nullptr) {
		return;
	}

	cout << "[";
	for (int i = 0; i < nodo->idclaves.size(); i++) {
		cout << nodo->idclaves[i];
		cout << ",";
	}
	for (int i = 0; i < nodo->hijos.size(); i++) {
		imprimirArbol(nodo->hijos[i]);
	}
	cout << "]";
}


ArbolB::~ArbolB()
{
}
