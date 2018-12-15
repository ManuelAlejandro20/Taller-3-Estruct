
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
	b->agregarDato(25);
	b->agregarDato(30);
	b->agregarDato(6);
	b->agregarDato(45);
	b->agregarDato(46);
	b->agregarDato(50);
	b->agregarDato(55);
	b->agregarDato(100);
	b->agregarDato(8);
	b->agregarDato(9);
	b->agregarDato(10);
	b->agregarDato(11);
	b->agregarDato(21);
	b->agregarDato(22);
	b->agregarDato(24);
	b->agregarDato(101);
	b->agregarDato(105);
	b->agregarDato(106);
	b->agregarDato(108);
	b->agregarDato(200);
	b->agregarDato(209);
	b->imprimir();
}

