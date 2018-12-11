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
	~Nodo();

private:
	bool esHijo;
	bool tienehijos;
	vector<int> idclaves;
	vector<Nodo*> hijos;
	friend class ArbolB;
};

