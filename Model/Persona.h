#ifndef _PERSONA_H
#define _PERSONA_H
#include <iostream>
using namespace std;
class Persona {
    protected:
        int codigo;
        string nombre;
        int dni;
        int telefono;
    public:
        void setCodigo(int c){codigo = c;}
        int getCodigo(){return codigo;}
        void setNombre(string n){nombre = n;}
        string getNombre(){return nombre;}
        void setDni(int n){dni = n;}
        int getDni(){return dni;}
        void setTelefono(int t){telefono = t;}
        int getTelefono(){return telefono;}
};
#endif //_PERSONA_H
