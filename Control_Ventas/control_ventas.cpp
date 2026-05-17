/* 
Bootcamp Programación Cero a POO 

Mini proyecto en C++ - Tema: Sistema de control de ventas

Autor: Sebastian Guayaquil
Fecha: 15 de mayo del 2026

Enunciado: Desarrollar un sistema de control de ventas.
El sistema debe realizar operaciones con la información almacenada:
    • cálculo
    • conteos
    • búsquedas
    • promedios
    • totales
    • máximos y mínimos
    • reportes simples

E/P/S

Entrada:
    Menu: una opcion.
    Gestión de Productos: nombre, precio, stock del producto.
    Venta tipo de producto y cantidad a vender.

Proceso:
    Inicialización: Definir el tamaño máximo de los arreglos y declarar las variables para el control de caja.
    Validación de Datos.
    Verificar que los precios y cantidades sean mayores a cero.
    Realizar los calulos, conteos, busquedas.
    Búsqueda: Localizar el producto en los arreglos.
    Cálculo de Ventas
        subtotal
        total
        total de caja
        actualizacion de inventario

Salida:
    Mostrar un menu
    Alertas y errores
    Reportes de inventario
    Factura o recibo
    Cierre de caja
*/

/*
PSEUDOCÓDIGO

Algoritmo ControlVentas
    Definir N como entero 
    Dimension nombresProductos[N];
    Dimension arreglo preciosProductos[N];
    Dimension stockProductos[N];

    Definir cantidadActual como Entero
    Definir totalCaja como Real
    Definir opcion como Entero

    Funcion mostrarMenu()
    Funcion validarOpcion()
    Funcion registrarProductos()
    Funcion mostrarInventario()
    Funcion realizarVenta()


FinAlgoritmo

Inicio
    mostrarMenu(...)
    validarOpcion(...)
    registrarProductos(...)
    mostrarInventario(...)
    realizarVenta(...)

Fin
*/

#include <iostream>
#include <string>
using namespace std;

// Constante global para el tamaño máximo de los arreglos
const int N = 20;

// Prototipo de las funiones
// Mostrar el menu
void mostrarMenu();

// Validar que el usuario ingrese un número entero dentro de un rango específico
int validarOpcion(int min, int max);

// Permitir ingresar productos al sistema
void registrarProductos();

// Mostrar la lista de productos en formato de tabla
void mostrarInventario();

// Procesar la venta, descuentor stock y acumular el dinero en caja
void realizarVenta();

// Funcion principal
int main(){

}

// Funciones
void mostrarMenu() {
    cout << "====================================" << endl;
    cout << "    SISTEMA DE CONTROL DE VENTAS    " << endl;
    cout << "====================================" << endl;
    cout << "1. Registrar Productos" << endl;
    cout << "2. Ver Inventario" << endl;
    cout << "3. Realizar Venta" << endl;
    cout << "4. Ver Total en Caja" << endl;
    cout << "5. Salir" << endl;
}

int validarOpcion(int min, int max) {
    int entrada;
    cin >> entrada;

    // Bucle while para controlar los datos ingresados
    while (entrada < min || entrada > max) {
        cout << "Opcion invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> entrada; // Volver a pedir el dato
    }
    return entrada;
}