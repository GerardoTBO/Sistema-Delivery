#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>
using namespace std;

class Categoria {
private: 
	int Codigo;
	string Nombre;
public:
	Categoria(int _Nombre,string _Codigo);
	void setNombre(string _Nombre);
	string getNombre(void);
	int getCodigo(void);
	void mostrar(void);
	
};

#endif

