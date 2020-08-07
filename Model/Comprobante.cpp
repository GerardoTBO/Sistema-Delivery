#include <iostream> // Libreria importada que nos proporciona herramientas
#include <stdlib.h> // Libreria que nos proporciona el operador new
#include <conio.h>  // Libreria para reconocer la letra enter
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include "Comprobante.h"
using namespace std;
void Comprobante::setPago() {
    ifstream lec_productos; // Variable para lectura de base de datos
    ofstream esc_pedidos; // Variable para la escritura de pedidos.txt
    lec_productos.open("fechaPedido.txt",ios::in);
    lec_productos >> Fecha.dia >> Fecha.mes >> Fecha.anio ;
    esc_pedidos.open("boleta.txt", ios::out);
    esc_pedidos << "\n   RESTAURANT-DELIVERY-PSI\n" << "\tBoleta de Pago\n\t  "
    << Fecha.dia <<"/"<< Fecha.mes <<"/"<< Fecha.anio  << "\n\nProductos\n\n";
    esc_pedidos.close();
    lec_productos.close();
    getPago();
}

void Comprobante::getPago() {
    cout << "\n\t<<<Imprimir Boleta>>>\n";
    getchar();
    system("cls");
    getPedidos();
    char data[100];
    ifstream lec_pedidos;
    lec_pedidos.open("boleta.txt", ios::in);
    if (lec_pedidos.is_open()) {
        lec_pedidos.getline(data, 100);
        while (!lec_pedidos.eof()) {
            cout << data << endl;
            lec_pedidos.getline(data, 100);
        }
    } else cout << "Hubo un error";
    lec_pedidos.close();
    remove("fechaPedido.txt");
    remove("despacho.txt");
}

void Comprobante::getPedidos() { // Muestra los productos almacenados en pedidos.txt
    int num,precio;
    double paga = 0;
    string producto;
    ofstream esc_pedidos("boleta.txt", ios::out | ios::app);
    ifstream lec_pedidos;
    lec_pedidos.open("despacho.txt", ios::in);
    if (lec_pedidos.is_open()) {
        lec_pedidos >> num >> producto >> precio;
        while (!lec_pedidos.eof()) {
            esc_pedidos << "\t" << producto << "  " << precio << "\n";
            paga += precio;
            lec_pedidos >> num >> producto >> precio;
        }
    } else cout << "Hubo un error";
    esc_pedidos << "_______________________\n";
    esc_pedidos << "Total paga:\t" << paga << endl;
    setMonto(paga);
    esc_pedidos.close();
    lec_pedidos.close();
}

// Setter and Getter

int Comprobante::getID() {
    return this->ID;
}

void Comprobante::setID(int ID) {
    this->ID = ID;
}

double Comprobante::getMonto() {
    return this->Monto;
}
void Comprobante::setMonto(double Monto) {
    this->Monto = Monto;
}
