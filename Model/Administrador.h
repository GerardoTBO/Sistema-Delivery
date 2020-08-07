#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H
class Administrador: public Persona {
    public:
        Administrador();
        //Administrador(int c,string n,int d,int t);
        void listarProductos();
        void agregarProducto();
        void modificarProducto();
        void eliminarProducto();
        void validarAdministradorDni();
};
#endif //_ADMINISTRADOR_H
