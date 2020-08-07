/**
 * Sección Cabezera Pedido
 */

#include <iostream> // Libreria importada que nos proporciona herramientas
#include <stdlib.h> // Libreria que nos proporciona el operador new
#include <windows.h>
#include <fstream>
using namespace std; // Código para reconocer las diversas funcionalidades

#ifndef _PEDIDO_H
#define _PEDIDO_H

// Declaracion de estructura Date

struct DateP {
    int dia;
    int mes;
    int anio;
};

// Declaracion de clase Pedido

class Pedido {

    private:
        int codigo;
        string nombre;
        int precio;
        bool estado;
        int numeroTicket;
        string tipo;

    public:
        struct DateP Fecha;

        // Setter de atributos
        void setCodigo(int c);
        void setNombre(string n);
        void setPrecio(int p);
        void setEstado(bool e);
        void setNumeroTicket(int n);
        void setTipo(string t);

        // Getter de atributos
        int getCodigo();
        string getNombre();
        int getPrecio();
        bool getEstado();
        int getNumeroTicket();
        string getTipo();

        // Definir metodos necesarios
        void contadorTicket(); // Declarar metodo contadorTicket
        void setDateP(); // Declarar metodo setDateP

        // Declaracion de funciones
        void getPedido(); // Check
        void setPedido(); // Check
};


#endif //_PEDIDO_H
