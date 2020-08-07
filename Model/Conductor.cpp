#include "Conductor.h"
Conductor::Conductor(){
    codigo=0;
    nombre="Jose";
    dni=0;
    telefono=0;
    licencia = 0;
    disponibilidad = true;
}
Conductor::Conductor(int c,string n,int d,int t,int l,bool di){
    codigo=c;
    nombre=n;
    dni=d;
    telefono=t;
    licencia = l;
    disponibilidad = di;
}
void Conductor::setLicencia(int l){licencia = l;}
int Conductor::getLicencia(){return licencia;}
void Conductor::setDisponibilidad(bool d){disponibilidad = d;}
bool Conductor::getDisponibilidad(){return disponibilidad;}
/*void Conductor::llevarPedido(Pedido p) {
    p.cambiarPedido(true);
}*/
