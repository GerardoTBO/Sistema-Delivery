#include <iostream>
using namespace std;
/* Ejemplo de usar este metodo
 supongamos queremos ingresar los nombres lo unico que se tiene que hacer
 es asignar el el resultado de la funciona a la variable y mandar el mensaje como
 paramtro igual para todas las validaciones
 String nombre;
 nombre validarString("Ingrese el nombre");
*/
// FUNCION PARA VALIDAR NUMEROS
int validarNumero(string msg){
    int i;
    string cad;
    cout << msg;
    while(true) {
        getline(cin, cad);
        stringstream mystream(cad);
        if(mystream >> i) break;
        cout << "error, ingrese solo numeros" << endl;
    }
    return i;
}
// FUNCION PARA INTERVALOS DE NUMEROS
int intervaloNumeros(string msg, int v1, int v2) {
    int i;
    string cad;
    bool valido = false;
    cout << msg;
    do {
        getline(cin, cad);
        stringstream mystream(cad);
        if(mystream >> i) {
            if(i >= v1 && i <= v2) valido = true;
        }
        if(!valido) cout << "Error, ingrese un numero en el rango de "<<v1<<" a "<<v2<<": ";
    } while(!valido);
    return i;
}
// FUNCION PARA VALIDAR LETRAS
string validarString(string msg){
    bool bandera = true;
    string s;
    while(bandera){
        bandera = false;
        cout<<msg;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
			if (!isalpha(s[i]) && !isspace(s[i]))
                bandera=true;
    }
    return s;
}
