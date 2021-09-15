#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <iomanip>

using namespace std;

class Alumno
{
	
	string nombre;
	int codigo;
	int edad;
	
public:
	Alumno();
	
	void setNombre(string a);
	string getNombre(void);
	
	void setCodigo(int a);
	int getCodigo(void);
	
	void setEdad(int a);
	int getEdad(void);
	
	void get();
friend class Nodo;

};

#endif
