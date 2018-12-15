#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Nodo
{
public:
	Nodo(int m, bool esHijo);
	void limpiarHijos();
	int retornarPos(int num);
	bool esHijo(Nodo* nodo);
	bool tieneHijos();
	~Nodo();

private:
	vector<int> idclaves;
	vector<Nodo*> hijos;
	friend class ArbolB;
};

