#ifndef _CONDUCTOR_H
#define _CONDUCTOR_H
#include "Persona.h"
class Conductor: public Persona {
    private:
        int licencia;
        bool disponibilidad;
    public:
        // Constructor
        Conductor(int c,string n,int d,int t,int l,bool di);
        Conductor();
        // Setter y Getters
        void setLicencia(int l);
        int getLicencia();
        void setDisponibilidad(bool d);
        bool getDisponibilidad();
        // Metodos
        void llevarPedido();
};
#endif //_CONDUCTOR_H
