#include "alumno.h"
Alumno::Alumno()
{
	nombre="ninguno";
	codigo=0;
	edad=0;
}



void Alumno::setNombre(string a)
{
	nombre = a;
}

string Alumno::getNombre(void)
{
	return nombre;
}

void Alumno::setCodigo(int a)
{
	codigo = a;
}
int Alumno::getCodigo(void)
{
	return codigo;
}

void Alumno::setEdad(int a)
{
	edad = a;
}

int Alumno::getEdad(void)
{
	return edad;
}

void Alumno::get()
{
	cout << "Nombre: "<< nombre <<"  Codigo: " << codigo << " Edad: " << edad << endl;
}
