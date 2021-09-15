#include "Lista.h"

Lista::Lista()
{
	h= NULL;
}


bool Lista::Vacia(void)
{
	if (h == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Lista::Tamano()
{
	int cont =0;
	Nodo *aux;
	aux = h;
	if (Vacia()){
		return 0;
	}
	else{
		while (aux != NULL )
		{
			aux = aux->sig;
			cont++;
		}
		return cont;
	}
	
}

void Lista::IsertarInicio(string nombre, int codigo, int edad)
{
	Nodo *tmp = new Nodo;
	
	tmp->dato.setNombre(nombre);
	tmp->dato.setEdad(edad);
	tmp->dato.setCodigo(codigo);
	tmp->sig = NULL;
	
	if (Vacia())
	{
		h=tmp;
	}
	else
	{
		tmp->sig = h;
		h = tmp;
	}
}

void Lista::InsertarFinal(string nombre, int codigo, int edad)

{
	Nodo *tmp = new Nodo;
	
	tmp->dato.setNombre(nombre);
	tmp->dato.setEdad(edad);
	tmp->dato.setCodigo(codigo);
	
	if (Vacia())
	{
		h=tmp;
		tmp->sig = NULL;
		return;
	}
	if(Vacia()==false and h->sig==NULL){
		h->sig=tmp;
		return;
	}
	else{
		Nodo *aux=new Nodo();
		aux=h;
		while(aux->sig!=NULL){
			aux=aux->sig;		
		}
		aux->sig=tmp;
	}

}


void Lista::Mostrar(void)
{
	Nodo *aux= h;
	while(aux != NULL)
	{
		aux->dato.get();
		aux= aux->sig;
	}
}

void Lista::Guardar(void)
{
	Nodo *aux=new Nodo();
	aux=h;
	
	ofstream archivo;
	archivo.open("file01.txt"); 
	if(archivo.fail()){
			ofstream archivo("file01.txt"); 
			archivo.open("file01.txt");
	}
	while(aux){
		archivo<<"" <<aux->dato.getNombre()<<"|"<<aux->dato.getCodigo()<<"|"<<aux->dato.getEdad()<<"*";
		aux=aux->sig;
	}
	archivo.close();
}


void Lista::Cargar(void)
{
	string txt, nom, cod, ed, b;
	int  c,d;
	h=NULL;
	ifstream archivo("file01.txt");
	if(archivo.fail()){
			ofstream archivo("file01.txt");
			archivo.open("file01.txt");
	}
	while(!archivo.eof()){
		getline(archivo, b,'|');
		getline(archivo, cod,'|');
		c=atoi(cod.c_str());
		getline(archivo, ed,'*');
		d=atoi(ed.c_str());
		if(archivo.eof())
		{
			break;
		}
		InsertarFinal(b,c,d);
	}
	archivo.close();
	return;

}

Nodo* Lista::buscarNombre(string x)
{
	Nodo *find=new Nodo();
	Nodo *aux=new Nodo();
	find->dato.setNombre(x);
	aux=h;
	if(Vacia())
	{
		return NULL;
	}
	else{
		while(aux){
			if(aux->dato.getNombre() == find->dato.getNombre())
			{
				return aux;
			}
			aux=aux->sig;
		}
		return NULL;
	}

}

Nodo* Lista::buscarCod(int x)
{
	Nodo *find=new Nodo();
	Nodo *aux=new Nodo();
	find->dato.setCodigo(x);
	aux=h;
	if(Vacia())
	{
		return NULL;
	}
	else
	{
		while(aux){
			if(aux->dato.getCodigo() == find->dato.getCodigo())
			{
				return aux;
			}
			aux=aux->sig;
		}
		return NULL;
	}
}


Nodo* Lista::primero()
{
	return h;
}

Nodo* Lista::ultimo()
{
	Nodo *aux=h;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	return aux;

}

Nodo* Lista::Anterior(Nodo *find)
{
	Nodo *aux=new Nodo();
	aux=h;
	if(find==NULL){
		return NULL;
	}
	while(aux){
		if(aux->sig==find){
			return aux;
		}
		aux=aux->sig;
	}
	return NULL;
}

Nodo* Lista::Siguiente(Nodo* find)
{
	Nodo *aux=new Nodo();
	aux=ultimo();
	if(find==NULL){
		return NULL;
	}
	if(aux==find){
		return NULL;
	}
	return find->sig;

}

void Lista::Eliminar(Nodo* find)
{
	Nodo *aux=new Nodo();
	Nodo *asis=new Nodo();
	aux=h;
	if(h==ultimo()){
		delete h;
		h=NULL;
		return;
	}
	if(find==h){
		h=h->sig;
		delete find;
		return;
	}
	asis=ultimo();
	if(find==asis){
		aux=Anterior(find);
		aux->sig=NULL;
		delete find;
		return;
	}
	else{
		aux=Anterior(find);
		asis=Siguiente(find);
		aux->sig=asis;
		delete find;
		return;
	}

} 



