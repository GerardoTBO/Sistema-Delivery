/**
 * Sección Cabezera Comprobante
 */

#include <iostream> // Libreria importada que nos proporciona herramientas
#include <stdlib.h> // Libreria que nos proporciona el operador new 
#include <windows.h>
#include <fstream>
using namespace std; // Código para reconocer las diversas funcionalidades  

#ifndef _COMPROBANTE_H
#define _COMPROBANTE_H

// Declaracion de estructura Date

struct DateC {
    int dia;
    int mes;
    int anio;
};

// Declaracion de clase Comprobante

class Comprobante {

    private:
        int ID;
        double Monto;

    public: 
        struct DateC Fecha;
        
        void setPago();
        void getPago();

        // Setter de atributos
        void setID(int i);
        void setMonto(double d);

        // Getter de atributos
        int getID();
        double getMonto();

        // Definir metodos necesarios
        void getPedidos();
};

#endif //_COMPROBANTE_H