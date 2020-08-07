#ifndef _CLIENTE_H
#define _CLIENTE_H
#include <iostream>
class Cliente: public Persona {
private:
    string direccion;
    //vector<Pedido> pedidos;
public:
    Cliente();
    void setDireccion(string d);
    string getDireccion();
    void realizarPedido(Pedido p);
    void pagarPedido(Pedido p);
    void cancelarPedido(Pedido p);
    void validarClienteDni();
};
#endif
