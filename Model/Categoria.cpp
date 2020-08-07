
#include "Categoria.h"

Categoria::Categoria(int _Codigo,string _Nombre){
	Codigo=_Codigo;
	Nombre=_Nombre;
}
void Categoria::setNombre(string _Nombre){
	Nombre=_Nombre;
}
string Categoria::getNombre(void){
	return Nombre;
}
int Categoria::getCodigo(void){
	return Codigo;
}
void Categoria::mostrar(void){
	cout<<"Nombre de la Categoria: "<<Nombre<<"--- Codigo: "<<Codigo<<"\n";
}
