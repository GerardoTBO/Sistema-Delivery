#include <iostream>
#include <windows.h>
#include <Windows.h>
#include "Persona.h"
#include "TextTable.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "funciones.cpp"
#include "Pedido.cpp"
#include "Producto.cpp"
#include "Conductor.cpp"
#include "Administrador.cpp"
#include "Cliente.cpp"
#include "Comprobante.cpp"
void salirVentana(string opcion) {
    cout<<"\n\n\tSALIR DE " << opcion;
    Sleep(500);cout << ".";Sleep(300);cout << ".";
    Sleep(300);cout << ".";Sleep(100);
}
int main()
{
    int opt;
    /*Conductor c;
    cout<<c.getCodigo()<<endl;
    cout<<c.getNombre()<<endl;*/
    Administrador a;
    //cout<<a.getNombre();
    Cliente c;
    Pedido p;
    /*do{
        cout<<"1. listar Pr"<<endl;
        cout<<"2. agregr Pr"<<endl;
        cout<<"3. modifc Pr"<<endl;
        cout<<"4. elimin Pr"<<endl;
        cout<<"5. Validad Cliente"<<endl;
        cout<<"6. Realizar Pe"<<endl;
        cout<<"7. Pagar Pedido"<<endl;
        cout<<"8. Validar Administrador"<<endl;
        cout<<"9. Salir"<<endl;
        cin>>opt;
        switch(opt){
            case 1: //setPedido();
                    //Pedido p;
                    //p.contadorTicket();
                    a.listarProductos();
                    break;
            case 2: a.agregarProducto();
                    break;
            case 3: a.modificarProducto();
                    break;
            case 4: a.eliminarProducto();
                    break;
            case 5: //cout<<c.getDni()<<endl;
                    //system("pause");
                    //cout<<c.getCodigo()<<endl;
                    c.validarClienteDni();
                    //cout<<c.getCodigo()<<endl;
                    while (c.getCodigo()==0){
                        cout<<"El DNI no existe en el sistema vuelve a inrsar DNI: ";
                        c.validarClienteDni();
                    }
                    cout<<"Bienvenido "<<c.getNombre()<<endl;
                    system("pause");
                    break;
            case 6: p.setPedido();
                    break;
            case 7: Comprobante comp;
                    comp.setPago();
            case 8: a.validarAdministradorDni();
                    while (a.getCodigo()==0){
                        cout<<"El DNI no existe en el sistema vuelve a inrsar DNI: ";
                        c.validarClienteDni();
                    }
                    cout<<"Bienvenido "<<a.getNombre()<<endl;
                    system("pause");
                    break;
            case 9: break;
            default:  "No existe esta opcion";
        }
    }while(opt!=9);*/
    system("color f0");
    int opc;
    do {
        system("cls");
        cout<<"\t\t\t"<<setiosflags(ios::left) << setw(80);
        cout<< "_________________________________" << endl;
        cout<<"\t\t\t"<<setiosflags(ios::left) << setw(80);
        cout<<"| SISTEMA DE PEDIDOS DE DELIVERY |"<<endl;
        cout<<"\t\t\t"<<setiosflags(ios::left) << setw(80);
        cout<< "---------------------------------"<<endl;
        cout<<"\n\t[1] Administrador";
        cout<<"\n\t[2] Hacer Pedido";
        cout<<"\n\t[3] Salir";
        cout<<"\n\n\tElige una opcion >> ";
        cin>>opc;
        switch (opc) {
        case 1: {
            int opcion;
            do {
                if (a.getDni()==0)
                    a.validarAdministradorDni();
                for (int i=0;i<2;i++) {
                    if (a.getDni()==0) {
                        a.validarAdministradorDni();
                    }
                }
                if (a.getDni()==0) {
                    system("cls");
                    cout<<"\n\tSupero el numero de intentos permitidos!!!\n\t\a";
                    break;
                }
                system("cls");
                string nombreAdmin = a.getNombre();
                for (int i = 0; i < nombreAdmin.length(); i++) {
                    nombreAdmin[i] = toupper(nombreAdmin[i]);
                }
                cout<<"\n\t\t"<<setiosflags(ios::left) << setw(15);
                string mssg = "---------------BIENVENIDO " + nombreAdmin +"---------------";
                cout<<"\n\t"<<mssg<<endl;
                cout<<"\n\tADMINISTRADOR\n\n";
                //cout<<"\n\t1.-CRUD Producto";
                cout<<"\n\t[1] Agregar Producto";
                cout<<"\n\t[2] Eliminar Producto";
                cout<<"\n\t[3] Modificar Producto";
                cout<<"\n\t[4] Listar Productos";
                cout<<"\n\t[5] Salir";
                cout<<"\n\n\tElige una opcion >> ";
                cin>>opcion;

                switch (opcion) {
                case 1: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tNUEVO PRODUCTO\n\n\t";
                    a.agregarProducto();
                    system("pause");
                    break;
                }
                case 2: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tELIMINAR PRODUCTO"<<endl;
                    a.eliminarProducto();
                    system("pause");
                    break;
                }
                case 3: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tMODIFICAR PRODUCTO"<<endl;
                    a.modificarProducto();
                    system("pause");
                    break;
                }
                case 4: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tLISTAR PRODUCTO\n";
                    a.listarProductos();
                    //system ("pause");
                    break;
                }
                case 5: {
                    a.setDni(0);
                    break;
                }
                default: {
                    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n";
                    Sleep(800);
                    break;
                }
                }
            } while (opcion!=5);
            salirVentana("ADMINISTRADOR");
            break;
        }
        case 2: {
            //system("cls");
            int opcion;
            do {
                //if(c != null){
                if (c.getDni()==0) {
                    c.validarClienteDni();
                }
                for (int i=0;i<2;i++) {
                    if (c.getDni()==0) {
                        c.validarClienteDni();
                    }
                }
                if (c.getDni()==0) {
                    system("cls");
                    cout<<"\n\tSupero el numero de intentos permitidos!!!\n\t\a"<<endl;
                    break;
                }
                system("cls");
                string nombreCliente = c.getNombre();
                for (int i = 0; i < nombreCliente.length(); i++) {
                    nombreCliente[i] = toupper(nombreCliente[i]);
                }
                cout<<"\n\t\t"<<setiosflags(ios::left) << setw(15);
                string mssg = "---------------BIENVENIDO " + nombreCliente +"---------------";
                cout<<"\n\t"<<mssg<<endl;
                cout<<"\n\tHACER PEDIDO\n\n";
                cout<<"\n\t[1] Ver Productos";
                cout<<"\n\t[2] Realizar Pedido";
                cout<<"\n\t[3] Pagar Pedido";
                cout<<"\n\t[4] Ver Carrito de compras";
                cout<<"\n\t[5] Salir";
                cout<<"\n\n\tElige una opcion >>  ";
                cin>>opcion;

                switch (opcion) {
                case 1: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tVER PRODUCTOS\n";
                    a.listarProductos();
                    break;
                }
                case 2: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tREALIZAR PEDIDO\n     ";
                    p.setPedido();
                    system("pause");
                    break;
                }
                case 3: {
                    system("cls");
                    cout<<"\n\t\t";
                    cout<<"\n\tPAGAR PEDIDO\n\t\t";
                    Comprobante comp;
                    comp.setPago();
                    system("pause");
                    break;
                }
                      /*case 4:{
                          system("cls");
                          cout<<"\n\t\t";
                          cout<<"\n\tCACELAR PEDIDO\n\t\t";
                          system ("pause");
                          break;
                      }*/
                case 4: {
                    system("cls");
                    cout<<"\n\n\tCarrito de Compras...\n\n";
                    //Pedido a;
                    p.getPedido();
                    //system ("pause");
                    break;
                }
                case 5: {
                    c.setDni(0);
                    break;
                }
                default: {
                    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t";
                    Sleep(800);
                    break;
                }
                }
            } while (opcion!=5);
            salirVentana("PEDIDO");
            break;
        }
        case 3: {
            int k = 79;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, k);
            cout<<"\a";
            salirVentana("SISTEMA   ");
            break;
        }
        default: {
            cout<<"\n\n\tHa elegido una opcion inexistente...\n\n";
            Sleep(800);
            break;
        }
        }//fin switch
    } while (opc!=3);
    system("cls");
    return 0;
}
