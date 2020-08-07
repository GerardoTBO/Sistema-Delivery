#include "Cliente.h"
Cliente::Cliente() {
    codigo=0;
    nombre="";
    dni=0;
    telefono=0;
    direccion="";
}
void Cliente::setDireccion(string d) {
    direccion = d;
}
string Cliente::getDireccion() {
    return direccion;
}
void Cliente::realizarPedido(Pedido p) {
    //p.setPedido();
}

void Cliente::pagarPedido(Pedido p) {
    //p.setEstado(1);
}
void Cliente::cancelarPedido(Pedido p) {
    //p.pop_back();
}
void Cliente::validarClienteDni() {
    ifstream lec_clientes;
    int d;
    lec_clientes.open("clientes.txt", ios::in);
    cout<<"\n\tIngrese DNI de cliente >> ";
    try {
        cin >> d;
        while (!lec_clientes.eof()) {
            lec_clientes >> codigo >> nombre >> dni >> telefono >> direccion;
            if (d==dni) {
                //cout<<nombre<<endl;
                break;
            }
            else {
                codigo=0;nombre="";dni=0;telefono=0;direccion="";
                if (lec_clientes.eof()) {
                    throw dni;
                }
            }
        }
    }
    catch (...) {
        cout << "\n\tDNI no encontrado, ingrese de nuevo" << endl;
    }
    lec_clientes.close();
}
