#ifndef _PRODUCTO_H
#define _PRODUCTO_H
#include "Producto.h"
class Producto {
private:
	int codigo;
	string nombre;
	//Categoria Cat;
	//string descripcion;
	float precio;
	int stock;
public:
    Producto();
	Producto(int c,string n,double precio,int stock);
	void listarProductos();
	void agregarProducto();
    void modificarProducto(int c,string n,float p, int s);
    void eliminarProducto(int c);
	void setProducto();
	void mostrarProducto();
	double getPrecio();
	void setCodigo(int c);
	int getCodigo();
	void codigoAutogenerado();
};
#endif //_PRODUCTO_H
