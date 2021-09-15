//Lizeth Avendaño Garcia
#include <iostream>
#include "windows.h"
#include "Lista.h"
using namespace std;

int main() {
	
	Lista *l=new Lista;
	string b, opc;
	int c, d, x;
	Nodo *aux=new Nodo;
	while (true)
	{
		cout << "-----MENU-----" << endl;
		cout << "1. Agregar" << endl;
		cout << "2. Vacia" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Tamano" << endl;
		cout << "5. Buscar" << endl;
		cout << "6. Primero y ultimo" << endl;
		cout << "7. Mostrar" << endl;
		cout << "8. Guardar" << endl;
		cout << "9. Cargar" << endl;
		cout << "0. Salir" << endl;
		getline(cin,opc);
		
		if(opc == "1")
		{
			cout << "Nombre: ";
			cin >> b;
			cout << "Codigo: ";
			cin >> c;
			cout << "Edad: ";
			cin >> d;
			l->InsertarFinal(b,c,d);
			cin.ignore();
		}
		else if(opc== "2")
		{
			if(l->Vacia())
			{
				cout<<"La lista esta vacia"<<endl;
			}
			else
			{
				cout<<"La lista tiene informacion"<<endl;
			}
		}
		else if(opc == "3")
		{
			x=100;
			if(l->Vacia())
			{
				cout<<"La lista esta vacia..."<<endl;
				x=0;
			break;
			}
			do{
				cout<<"Buscar por: "<<endl;
				cout<<"1. Nombre"<< endl;
				cout<<"2. Codigo"<< endl;
				cout<<"0. Salir"<< endl;
				cin>>x;
				cin.ignore();
				switch(x)
				{
					case 0:
						break;
					case 1:
						cout<<"Nombre: ";
						cin>>b;
						cin.ignore();
						aux=l->buscarNombre(b);
						if(aux){
							l->Eliminar(aux);
							cout<<b<<" ha sido eliminado"<<endl;
							x=0;
							break;
						}
						cout<<"Alumno no encontrado"<< endl;
						x=0;
						break;
					case 2:
						cout<<"Codigo: ";
						cin>>c;
						cin.ignore();
						aux=l->buscarCod(c);
						if(aux)
						{
							b=aux->dato.getNombre();
							l->Eliminar(aux);
							cout<<b<<" ha sido eliminado"<<endl;
							x=0;
							break;
						}
						cout<<"Alumno no encontrado"<< endl;
						cout<<endl<<"\t";
						x=0;
						break;
					}	
			}while(x!=0);
		}
		else if(opc == "4")
		{
			cout << "El tamaño de la lista es: "<< l->Tamano() << endl;
			
		}
		else if (opc == "5")
		{
			x=100;
			if(l->Vacia())
			{
				cout<<"La lista esta vacia..."<<endl;
				x=0;
			break;
			}
			do{
				cout<<"Buscar por: "<<endl;
				cout<<"1. Nombre"<< endl;
				cout<<"2. Codigo"<< endl;
				cout<<"0. Salir"<< endl;
				cin>>x;
				cin.ignore();
				switch(x)
				{
					case 0:
						break;
					case 1:
						cout<<"Nombre: ";
						cin>>b;
						cin.ignore();
						aux=l->buscarNombre(b);
						if(aux){
							cout << "Informacion:  ";
							cout << endl;
							aux->dato.get();
							x=0;
							break;
						}
						cout<<"Alumno no encontrado"<< endl;
						x=0;
						break;
					case 2:
						cout<<"Codigo: ";
						cin>>c;
						cin.ignore();
						aux=l->buscarCod(c);
						if(aux)
						{
							cout << "Informacion: ";
							cout << endl;
							aux->dato.get();
							x=0;
							break;
						}
						cout<<"Alumno no encontrado"<< endl;
						cout<<endl<<"\t";
						x=0;
						break;
					}	
			}while(x!=0);
		}
		else if(opc == "6")
		{
			if(l->Vacia())
			{
				cout<<"La lista esta vacia..."<<endl;
				x=0;
			break;
			}
			cout << "Elige una opcion" << endl;
			cout << "1.Primero" << endl;
			cout << "2.Ultimo" << endl;
			cin >> x;
			cin.ignore();
			cout << endl;
			if (x==1)
			{
				aux = l->primero();
				aux->dato.get();
			}
			else if (x==2)
			{
				aux= l->ultimo();
				aux->dato.get();
			}
			
		}
		else if(opc == "7")
		{
			l->Mostrar();
		}
		else if(opc == "8")
		{
			l->Guardar();
			cout << "Informacion guardada con exito..." << endl;
		}
		else if(opc == "9")
		{
			l->Cargar();
			cout << "Archivo cargado..." << endl;
		}
		else if(opc == "0")
		{
			break;
		}
		
		
	}
	
	
	return 0;
}
