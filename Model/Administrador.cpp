#include "Administrador.h"
Administrador::Administrador() {
    codigo=0;
    nombre="";
    dni=0;
    telefono=0;
}
/*Administrador::Administrador(int c,string n,int d,int t){
    codigo=c;
    nombre=nombre;
    dni=d;
    telefono=t;
}*/
void Administrador::listarProductos() {
    Producto p;
    p.listarProductos();
}
void Administrador::agregarProducto() {
    Producto p;
    p.agregarProducto();
}
void Administrador::modificarProducto() {
    int c, s;
    char n[10];
    float pre;
    Producto p;
    p.listarProductos();
    cout<<"Seleccionar con codigo que producto desea modificar"<<endl;
    cin>>c;
    cout<<"Nuevo precio"<<endl;
    cin>>pre;
    cout<<"Nuevo nombre"<<endl;
    cin>>n;
    cout<<"Nuevo stock"<<endl;
    cin>>s;
    p.modificarProducto(c, n, pre, s);
}
void Administrador::eliminarProducto() {
    int c;
    Producto p;
    p.listarProductos();
    cout<<"Escribe el codigo del producto que desea eliminar"<<endl;
    cin>>c;
    p.eliminarProducto(c);
}
void Administrador::validarAdministradorDni() {
    ifstream lec_administradores;
    int d;
    lec_administradores.open("administradores.txt", ios::in);
    cout<<"\n\tIngrese DNI de Administrador >> ";
    try {
        cin>>d;
        while (!lec_administradores.eof()) {
            lec_administradores >> codigo >> nombre >> dni >> telefono;
            if (d==dni) {
                //cout<<nombre<<endl;
                break;
            }
            else {
                codigo=0;nombre="";dni=0;telefono=0;
                if (lec_administradores.eof()) {
                    throw dni;
                }
            }
        }
    }
    catch (...) {
        cout << "\n\tDNI no encontrado, ingrese de nuevo" << endl;
    }
    lec_administradores.close();
}
/*void Administrador::agregarProducto(){
}*/
/*void Administrador::modificarProducto();
void Administrador::eliminarProducto();*/
