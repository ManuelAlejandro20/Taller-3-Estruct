
// Taller3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Menu.h"
#include "ArbolB.h"

using namespace std;

int main()
{
	ArbolB *b = new ArbolB(4);
	b->agregarDato(15);
	b->agregarDato(20);
	b->agregarDato(5);
	b->imprimir();
}

