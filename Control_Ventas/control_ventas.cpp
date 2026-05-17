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
#include <string> // agregamos la libreria para usar cadena de texto
using namespace std;

// Constante global para el tamaño máximo de los arreglos
const int N = 20;

// Prototipo de las funiones
// Mostrar el menu
void mostrarMenu();

// Validar que el usuario ingrese un número entero dentro de un rango específico
int validarOpcion(int min, int max);

// Permitir ingresar productos al sistema
void registrarProductos(string nombres[], float precios[], int stock[], int &cantidadActual);

// Mostrar la lista de productos en formato de tabla
void mostrarInventario();

// Procesar la venta, descuentor stock y acumular el dinero en caja
void realizarVenta();

// Funcion principal
int main(){
    // Declaramos los arreglos para la base de datos de la tienda
    string nombresProductos[N]; // cadena de texto
    float preciosProductos[N];
    int stockProductos[N];
    
    // Variables de control
    int cantidadActual = 0; // Cuantos productos se han registrado realmente
    float totalCaja = 0.0;  // Acumulador de dinero recaudado
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        opcion = validarOpcion(1, 5); // Valida que solo elija entre 1 y 5

        switch (opcion) {
            case 1:
                cout << "\n--- REGISTRO DE PRODUCTOS ---" << endl;
                // Llamamos a registrarProductos
                break;
            case 2:
                cout << "\n--- INVENTARIO ACTUAL ---" << endl;
                // Llamamos a mostrarInventario
                break;
            case 3:
                cout << "\n--- NUEVA VENTA ---" << endl;
                // Llamamos a realizarVenta
                break;
            case 4:
                cout << "\n--- CIERRE DE CAJA ---" << endl;
                cout << "Total recaudado el dia de hoy: $" << totalCaja << endl;
                break;
            case 5:
                cout << "\n¡Gracias por usar el sistema! Saliendo..." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
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

// Funcion para crear una base de datos para registar los productos
void registrarProductos(string nombres[], float precios[], int stock[], int &cantidadActual) {
    if (cantidadActual >= N) {
        cout << "Error: La base de datos esta llena.\n";
        return; 
    }

    // Leemos el string
    cout << "Ingrese el nombre (use guion bajo para espacios, ej: papa_frita): ";
    cin >> nombres[cantidadActual];

    float precio;
    cout << "Ingrese el precio del producto: $";
    cin >> precio;
    
    // Validación de precio con un while 
    while (precio <= 0) {
        cout << "Error: El precio debe ser mayor a 0. Intente de nuevo: $";
        cin >> precio;
    }
    precios[cantidadActual] = precio;

    cout << "Ingrese el stock inicial: ";
    stock[cantidadActual] = validarOpcion(0, 10000); // podemos usar la funcion para validar opcion en el rango que queramos

    cantidadActual++;
    cout << "¡Producto registrado exitosamente!" << endl;
}