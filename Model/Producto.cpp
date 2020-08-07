#include <iostream>
#include <string>
//#include <cstdio>
#include <cstring>
//#include <cstdlib>
//#include <conio.h>
//#include <iomanip>
#include "Producto.h"
#include "Categoria.h"
Producto::Producto(){
    codigo=0;
    nombre="";
    //strcpy(nombre,"NaN");
    precio=0.0;
    stock=0;
}
Producto::Producto(int c,string n,double p,int s){
    codigo=c;
    nombre=n;
    //strcpy(nombre,n);
    precio=p;
    stock=s;
}
void Producto::listarProductos(){
    //Producto lectura;
    ifstream finput;
    finput.open("productos.txt", ios::in);
    TextTable t( '-', '|', '+' );
    t.add( "Codigo" );
    t.add( "  Nombre" );
    t.add( "Precio" );
    t.add( "Stock" );
    t.endOfRow();
	finput >> codigo >> nombre >> precio >> stock;
    while(!finput.eof()){
        //finput.read(reinterpret_cast<char*>(this),sizeof(Producto));
        /*string c = static_cast<ostringstream*>(&(ostringstream() << lectura.codigo))->str();
        string p = static_cast<ostringstream*>(&(ostringstream() << lectura.precio))->str();
        string s = static_cast<ostringstream*>(&(ostringstream() << lectura.stock))->str();*/
        string c = static_cast<ostringstream*>(&(ostringstream() << codigo))->str();
        string p = static_cast<ostringstream*>(&(ostringstream() << precio))->str();
        string s = "   " + static_cast<ostringstream*>(&(ostringstream() << stock))->str();
        /*string c = to_string(codigo);
        string p = to_string(precio);
        string s = to_string(stock);*/
        t.add( c );
        t.add( nombre );
        t.add( p );
        t.add( s );
        t.endOfRow();
		finput >> codigo >> nombre >> precio >> stock;
    }
    finput.close();
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << t;
    system("pause");
}
void Producto::agregarProducto(){
    //cout<<"Codigo: ";
    //cin>>codigo;
    cin.ignore();
    nombre=validarString("Nombre >> ");
    precio=validarNumero("\tPrecio >> ");
    stock=validarNumero("\tStock >> ");
    /*cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Precio: ";
    cin>>precio;
    cout<<"Stock: ";
    cin>>stock;*/
    ofstream foutput;
    foutput.open ("productos.txt", ios::out | ios::app);
    codigoAutogenerado();
    foutput << getCodigo() <<" "<<nombre<<" "<<precio<<" "<<stock<<endl;
    //foutput.write(reinterpret_cast<char*>(this),sizeof(Producto));
    foutput.close();
    cout<<"\n\t";
    //system("pause");
}
void Producto::modificarProducto(int c,string n,float p, int s){
    // code to update and modify
    // the content of the binary file
    cout<<"entro a modificar"<<endl;
    int pos, flag = 0;
    // rno=9
    fstream fs;
    //fs.open("productos.dat",ios::in | ios::binary | ios::out);
    fs.open("productos.txt",ios::in | ios::out);
    while (!fs.eof()) {
        // storing the position of
        // current file pointeri.e. at
        // the end of previously read record
        pos = fs.tellg();
        fs >> codigo >> nombre >> precio >> stock;
        //fs.read((char*)this, sizeof(Producto));
        if (fs) {
            // comparing the roll no with that
            // of the entered roll number
            if (c == codigo) {
                flag = 1;

                // setting the new (modified )
                // data of the object or new record
                //getdata(r, str);
                //codigo = a;
                /*strcpy(nombre,n);
                precio = p;
                stock = s;*/
                nombre = n;
                precio = p;
                stock = s;
                // placing the put(writing) pointer
                // at the starting of the  record
                fs.seekp(pos);

                // writing the object to the file
                fs<<codigo<<" "<<nombre<<" "<<precio<<" "<<stock<<endl;
                //fs.write((char*)this, sizeof(Producto));
                // display the data
                //putdata();
                cout<<nombre<<endl;
                break;
            }
        }
    }
    fs.close();

    if (flag == 1)
        cout << "\nrecord successfully modified \n";
    else
        cout << "\nrecord not found \n";
}
void Producto::eliminarProducto(int c){
    int pos, flag = 0;
    ifstream ifs;
    ifs.open("productos.txt", ios::in );
    ofstream ofs;
    ofs.open("temp.txt", ios::out );
    while (!ifs.eof()) {
        //ifs.read((char*)this, sizeof(Producto));
        ifs >> codigo >> nombre >>precio >> stock;
        // if(ifs)checks the buffer record in the file
        if (ifs) {
            // comparing the roll no with
            // roll no of record to be deleted
            if (codigo== c) {
//                temp << codigo << nombre << precio << stock << endl;
                flag = 1;
                cout << "El registro eliminado es is \n";
                // display the record
                cout<<nombre;
                //putdata();
            }
            else {
                // copy the record of "he" file to "temp" file
                ofs << codigo<<" "<<nombre<<" "<<precio<<" "<<stock<<endl;
                //ofs.write((char*)this, sizeof(Producto));
            }
        }
    }
    ofs.close();
    ifs.close();
    // delete the old file
    remove("productos.txt");
    // rename new file to the older file
    rename("temp.txt", "productos.txt");
    if (flag == 1)
        cout << "\nRegistro eliminado exitosamente \n";
    else
        cout << "\nRegistro no encontrado \n";
}
void Producto::setCodigo(int c){
    codigo = c;
}
int Producto::getCodigo(){
    return codigo;
}
void Producto::codigoAutogenerado() {
    //cout<<"Entro al codigoAutogenerado"<<endl;
    ifstream lec_productos;   // Lectura para pedidos
    char pro_nombre[50];    // Para poder leer pedidos
    int ticket,contador = 0;
    lec_productos.open("productos.txt", ios::in); // Agregamos este producto a la base de datos pedidos.txt
    //if (lec_pedidos.is_open()){ // Si el archivo est� disponible para su lectura
        while (!lec_productos.eof()) {
            //cout<<"Entro al while"<<endl;
            lec_productos >> ticket;
            contador++;                          // Contador para saber cuantos productos hay en pedidos.txt
            lec_productos.getline(pro_nombre, 50); // Leer una l�nea de pedidos.txt
        }
        /*if (contador == 0) { // Si no hay ning�n producto en pedidos.txt
            contador++; // Se le aumenta uno porque estariamos creando nuestro primero producto de pedido.txt
        }*/
    //}
    lec_productos.close();
    //cout<<"Numero Ticket "<<ticket<<endl;
    //cout<<"contador "<<contador<<endl;
    setCodigo(contador); // Establecer cantidad de tickets
}
/*
void crud_producto(){
    FILE *fp, *ft;
	char another;
	int choice;
	struct producto
	{
		char nombre[50], categoria[50];
		char descripcion[50];
		int codigo;
		int stock;
		float precio;
	};
	struct producto e;
	char cod[50];
	long int recsize;

	fp=fopen("producto.txt","rb+");

	if (fp == NULL)
	{
		fp = fopen("producto.txt","wb+");

		if (fp==NULL)
		{
			puts("Cannot open file");
			//return 0;
		}
	}
	recsize = sizeof(e);
	do{
		system("cls");

		cout << "\t\t====== SISTEMA DE DELIVERY ======";
		cout <<"\n\n                                          ";
		cout << "\n\n";
		cout << "\n \t\t\t 1. Agregar Producto";
		cout << "\n \t\t\t 2. Mostrar Todo los Productos";
		cout << "\n \t\t\t 3. Modificar Producto";
		cout << "\n \t\t\t 4. Eliminar producto";
		cout << "\n \t\t\t 5. Salir";
		cout << "\n\n";
		cout << "\t\t\t Seleccionar opcion :=> ";
		//fflush(stdin);
		//choice = getche();
		cin>>choice;
		switch(choice)
		{
		case 1 :
			fseek(fp,0,SEEK_END);
			another ='Y';
			while(another == 'Y' || another == 'y')
			{
				string linea;
				bool repite =true;
				system("cls");
				do{
					cout << "Ingresar codigo : ";
					getline(cin,linea);
					if (esNumerico(linea)){
						repite=false;
					}else{
						cout<<"\nSolo numeros"<<endl;
					}
				} while(repite);
				stringstream geek(linea);
				geek>> e.codigo;
				cout << "Ingresar nombre del producto : ";
				cin >> e.nombre;
				cout << "Ingresar categoria: ";
				cin >> e.categoria;
				cout << "Ingresar descripcion: ";
				cin >> e.descripcion;
				cout << "Ingresar precio : ";
				cin >> e.precio;
				cout << "Ingresar stock : ";
				cin >> e.stock;
				fwrite(&e,recsize,1,fp);
				cout << "\n Agregar otro producto? (Y/N) ";
				fflush(stdin);
				another = getchar();
			}
			break;
		case 2:
			system("cls");
			rewind(fp);
			cout << "=== Lista de Productos ===";
			cout << "\n";
			cout <<"\n" << "Codigo " << setw(10) << "Nombre" << setw(15)  << "Categoria" << setw(15) <<"Descripcion" << setw(10) <<"Precio" << setw(10) <<"Stock";
			while (fread(&e,recsize,1,fp) == 1)
			{
				cout << "\n";
				cout <<"\n" << e.codigo << setw(18) << e.nombre << setw(15)  << e.categoria << setw(10) <<e.descripcion << setw(11) <<e.precio << setw(11) << e.stock;
				cout << "\n";
			}
			cout << "\n\n";
			system("pause");
			break;

		case 3 :
			system("cls");
			another = 'Y';
			while (another == 'Y'|| another == 'y')
			{
				cout << "\n Ingresar nombre del producto a modificar : ";
				cin >> cod;

				rewind(fp);
				while (fread(&e,recsize,1,fp) == 1)
				{
					if (strcmp(e.nombre,cod) == 0)
					{
						cout << "Ingresar codigo : ";
						cin >> e.codigo;
						cout << "Ingresar nombre : ";
						cin >> e.nombre;
						cout << "Ingresar categoria: ";
						cin >> e.categoria;
						cout << "Ingresar descripcion: ";
						cin >> e.descripcion;
						//fflush(stdin);
						int p;
						cout << "Ingresar precio: ";
						cin >> p;
						e.precio=p;
						float s;
						cout<<"Ingresar stock: ";
						cin>>s;
						e.stock=s;
						fseek(fp, - recsize, SEEK_CUR);
						fwrite(&e,recsize,1,fp);
						break;
					}
					else
						cout<<"codigo de producto no existe";
				}
				cout << "\n Modificar otro producto? (Y/N) ";
				fflush(stdin);
				another = getchar();
			}
			break;


		case 4:
			system("cls");
			another = 'Y';
			while (another == 'Y'|| another == 'y')
			{
				cout << "\n Ingresar nombre de producto a eliminar: ";
				cin >> cod;

				ft = fopen("temp.dat", "wb");

				rewind(fp);
				while (fread (&e, recsize,1,fp) == 1)

					if (strcmp(e.nombre,cod) != 0)
				{
						fwrite(&e,recsize,1,ft);
				}
					fclose(fp);
					fclose(ft);
					remove("producto.txt");
					rename("temp.dat","producto.txt");

					fp=fopen("producto.txt","rb+");

					cout << "\n Eliminar otro producto? (Y/N) ";
					fflush(stdin);
					another = getchar();
			}

			break;

		case 5:
			fclose(fp);
			/*cout << "\n\n";
			cout << "\t\t     GRACIAS ...HASTA LUEGO";
			cout << "\n\n";*/
			//exit(0);
		/*}
	}while(choice!=5);
	//system("pause");

	//return 0;
}*/
/*Producto::Producto(){
    Codigo = 0;
	Nombre= "";
	Descripcion= "";
	Precio=0;
	Stock=0;
}
Producto::Producto(int _codigo,string _nombre,string _descripcion,double _precio,int _stock){
	Codigo = _codigo;
	Nombre= _nombre;
	Descripcion= _descripcion;
	Precio=_precio;
	Stock=_stock;
}
void Producto::setProducto(){
	int op;
	string des;
	int cod;
	double prec;
	int st;
	string name;
	cout<<"\nQue atributo desea cambiar"<<endl;
	cout<<"1- Codigo"<<endl;
	cout<<"2- Nombre"<<endl;
	cout<<"3- Descripcion"<<endl;
	cout<<"4- Precio"<<endl;
	cout<<"5- Stock"<<endl;
	cin>>op;
	switch (op){
	case 1:

		cout<<"Nuevo Codigo\n";
		cin>>cod;
		Codigo=cod;
		break;
	case 2:

		cout<<"Nuevo Nombre\n";
		cin>>name;
		Nombre=name;
		break;
	case 3:
		cout<<"Nueva Descripcion\n";
		cin>>des;
		Descripcion=des;
		break;
	case 4:

		cout<<"Nuevo Precio\n";
		cin>>prec;
		Precio=prec;
		break;
	case 5:

		cout<<"Nuevo Stock\n";
		cin>>st;
		Stock=st;

	default:
		cout<<"Esa Opcion No existe\n";
		break;
	}


}
void Producto::mostrarProducto(){
	cout << "\nNombre del Producto : " << Nombre;
	cout << "\nCodigo del Producto : " << Codigo;
	cout << "\nDescripcion del Producto : " << Descripcion;
	cout << "\nPrecio por unidad : " << Precio;
	cout << "\nStock del producto : " << Stock;
}
double Producto::getPrecio()
{
	return Precio;
}
*/
