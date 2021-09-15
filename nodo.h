#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Alumno.h"

using namespace std;

class Nodo
{
	public:
		Nodo();
		Nodo *sig;
		Alumno dato;
	
	friend class Lista;
};


#endif
