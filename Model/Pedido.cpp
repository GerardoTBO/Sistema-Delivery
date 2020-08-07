#include <iostream> // Libreria importada que nos proporciona herramientas
#include <stdlib.h> // Libreria que nos proporciona el operador new
#include <conio.h>  // Libreria para reconocer la letra enter
#include <sstream> // Fecha
#include <ctime> // Fecha
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include "Pedido.h"
using namespace std;
void Pedido::setPedido() {
    //Producto p;
    //Pedido pedido = Pedido();
    ifstream lec_productos; // Variable para lectura de base de datos
    ofstream agr_pedido;    // Escritura para pedidos
    ofstream agr_comprobante;
    string tipo, estado;
    //string n;
    char n[50];
    char nom[50];
    int p, c, s;
    bool bandera = true;
    cout << "Ingrese sus productos\n";
    cin.ignore();
    while (bandera) { // Bucle while padre
        cout << ">> ";
        //cin>>nombre;
        //cin.ignore();
        gets(n);
        if(strcmp(n,"")==0){ // Reconoce cuando se presione enter
            bandera = false; // Romper bucle while padre
            cout << "\n_______Fin de pedido_______" <<endl;
        } else { // Si no se presiona enter se puede seguir ingresando productos
            //pedido.setNombre(nombre);
            //strcpy(nombre,n);
            //nombre=n;
            agr_pedido.open("despacho.txt", ios::out | ios::app); // Crear (en caso sea necesario) y escribir en el txt
            lec_productos.open("productos.txt", ios::in);        // Lectura
            //lec_productos >> codigo >> nombre;
            while (!lec_productos.eof()) { // Mientras encuentre contenido
                lec_productos >> c >> nom >> p >> s;
                if (strcmp(n,nom)==0) { // Si el producto ingresado está en la base de datoss
                    //cout<<"entro al if"<<endl;
                    contadorTicket(); // Recorrido secuencial de pedidos.txt, para asignar el valor de ticket
                    //cout<<getNumeroTicket()<<endl;
                    agr_pedido << getNumeroTicket() << " " << nom << " " << p << endl; // Agregar el producto a pedidos.txt
                    //cout << pedido.getNumeroTicket() << " contador" << endl;
                    break;
                }
                //lec_productos >> nombre;
            }
            agr_pedido.close();
            lec_productos.close();
        }
    } // Fin de Bucle While Padre
    setDateP(); // Mostrar Fecha de Emision
}
void Pedido::getPedido() { // Muestra los productos almacenados en pedidos.txt
    char data[100];
    ifstream lec_pedidos;
    lec_pedidos.open("despacho.txt", ios::in);
    if (lec_pedidos.is_open()) {
        lec_pedidos.getline(data, 100);
        while (!lec_pedidos.eof()) {
            cout <<"\t"<<data << endl;
            lec_pedidos.getline(data, 100);
        }
    } else cout << "\tNo hay productos en el carrito";
    cout<<"\n\t";
    system("pause");
    lec_pedidos.close();
}
/* Métodos necesarias */

// Definir la cantidad de productos y definir el numero de ticket
void Pedido::contadorTicket() {
    //cout<<"Entro al contadorTicket"<<endl;
    ifstream lec_pedidos;   // Lectura para pedidos
    char ped_nombre[50];    // Para poder leer pedidos
    int ticket,contador = 0;
    lec_pedidos.open("despacho.txt", ios::in); // Agregamos este producto a la base de datos pedidos.txt
    //if (lec_pedidos.is_open()){ // Si el archivo está disponible para su lectura
        while (!lec_pedidos.eof()) {
            //cout<<"Entro al while"<<endl;
            lec_pedidos >> ticket;
            contador++;                          // Contador para saber cuantos productos hay en pedidos.txt
            lec_pedidos.getline(ped_nombre, 50); // Leer una línea de pedidos.txt
        }
        /*if (contador == 0) { // Si no hay ningún producto en pedidos.txt
            contador++; // Se le aumenta uno porque estariamos creando nuestro primero producto de pedido.txt
        }*/
    //}
    lec_pedidos.close();
    //cout<<"Numero Ticket "<<contador<<endl;
    setNumeroTicket(contador); // Establecer cantidad de tickets
}
// https://xtokio.github.io/blog/2017/c-obtener-fecha-actual/
// Definir la fecha actual
void Pedido::setDateP(){
    ofstream fecha_pedido; // Escritura para fecha del pedido
    fecha_pedido.open("fechaPedido.txt",ios::out | ios::app);
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string year = ss_year.str();
    Fecha.anio = atoi(year.c_str()); // Definir año

    stringstream ss_month;
    ss_month << timePtr->tm_mon+1;
    string month = ss_month.str();
    Fecha.mes = atoi(month.c_str()); // Definir mes

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string day = ss_day.str();
    Fecha.dia = atoi(day.c_str()); // Definir dia

    cout << "\nFecha de Emision: " << Fecha.dia <<"/"<< Fecha.mes <<"/"<< Fecha.anio << "\n\n";
    fecha_pedido << Fecha.dia << " " << Fecha.mes << " " << Fecha.anio;
    fecha_pedido.close();
}


// Setter and Getter

int Pedido::getCodigo()
{
    return codigo;
}

void Pedido::setCodigo(int c)
{
    codigo = c;
}

string Pedido::getNombre()
{
    return nombre;
}
void Pedido::setNombre(string n)
{
    nombre = n;
}

int Pedido::getPrecio()
{
    return precio;
}
void Pedido::setPrecio(int p)
{
    precio = p;
}

bool Pedido::getEstado()
{
    return estado;
}
void Pedido::setEstado(bool e)
{
    estado = e;
}

int Pedido::getNumeroTicket()
{
    return numeroTicket;
}
void Pedido::setNumeroTicket(int n)
{
    numeroTicket = n;
}

string Pedido::getTipo()
{
    return tipo;
}
void Pedido::setTipo(string t)
{
    tipo = t;
}
