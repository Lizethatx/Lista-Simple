#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Nodo.h"

using namespace std;

class Lista
{
	public:
		Lista();
		Nodo *h;
		bool Vacia(void);
		int Tamano(void);
		void IsertarInicio(string nombre, int codigo, int edad);
		void InsertarFinal(string nombre, int codigo, int edad);
		void Mostrar(void);
		void Guardar(void);
		void Cargar(void);
		void Eliminar(Nodo*);
		Nodo *Anterior(Nodo*);
		Nodo *Siguiente(Nodo*);
		Nodo *buscarNombre(string);
		Nodo *buscarCod(int);
		Nodo *primero(void);
		Nodo *ultimo(void);
};

#endif
