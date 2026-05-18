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
    Dimension cantidadVendida[N];

    Definir cantidadActual como Entero
    Definir totalCaja como Real
    Definir opcion como Entero

    Funcion mostrarMenu()
    Funcion validarOpcion()
    Funcion registrarProductos()
    Funcion mostrarInventario()
    Funcion realizarVenta()
    Funcion gestionarReportes()
    Funcion reporteStockCritico()
    Funcion reporteProductoMasnVendido()
    Funcion reporteProductoMenosVendido()


FinAlgoritmo

Inicio
    mostrarMenu(...)
    validarOpcion(...)
    registrarProductos(...)
    mostrarInventario(...)
    realizarVenta(...)
    gestionarReportes(...)
    reporteStockCritico()
    reporteProductoMasnVendido(...)
    reporteProductoMenosVendido(...)

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
void registrarProductos(string nombres[], float precios[], int stock[], int cantidadVendida[], int &cantidadActual);

// Mostrar la lista de productos en formato de tabla
void mostrarInventario(string nombres[], float precios[], int stock[], int cantidadActual);

// Procesar la venta, descuentor stock y acumular el dinero en caja
void realizarVenta(string nombres[], float precios[], int stock[], int cantidadVendida[], int cantidadActual, float &totalCaja);

// Mejora creativa, funcoines
void gestionarReportes(string nombres[], float precios[], int stock[], int cantidadVendida[], int cantidadActual, float totalCaja);
void reporteStockCritico(string nombres[], int stock[], int cantidadActual);
void reporteProductoMasVendido(string nombres[], int cantidadVendida[], int cantidadActual);
void reporteProductoMenosVendido(string nombres[], int cantidadVendida[], int cantidadActual);

// Funcion principal
int main(){
    // Declaramos los arreglos para la base de datos de la tienda
    string nombresProductos[N]; // cadena de texto
    float preciosProductos[N];
    int stockProductos[N];
    // Mejora creativa
    int cantidadVendida[N];
    
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
                registrarProductos(nombresProductos, preciosProductos, stockProductos, cantidadVendida, cantidadActual);
                break;
            case 2:
                cout << "\n--- INVENTARIO ACTUAL ---" << endl;
                // Llamamos a mostrarInventario
                mostrarInventario(nombresProductos, preciosProductos, stockProductos, cantidadActual);
                break;
            case 3:
                cout << "\n--- NUEVA VENTA ---" << endl;
                // Llamamos a realizarVenta
                realizarVenta(nombresProductos, preciosProductos, stockProductos, cantidadVendida, cantidadActual, totalCaja);
                break;
            case 4:
                cout << "\n--- REPORTES ADMINISTRATIVOS ---\n";
                // Llamamos a la nueva función que manejará el submenú
                gestionarReportes(nombresProductos, preciosProductos, stockProductos, cantidadVendida, cantidadActual, totalCaja);
                break;
            case 5:
                cout << "\nGracias por usar el sistema Saliendo..." << endl;
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
    cout << "4. Reportes Administrativos" << endl;
    cout << "5. Salir" << endl;
}

int validarOpcion(int min, int max) {
    int entrada;
    cin >> entrada;

    // Bucle while para controlar los datos ingresados por si ingresan un número fuera de rango
    while (entrada < min || entrada > max) {
        cout << "Opcion invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> entrada; // Volver a pedir el dato
    }
    return entrada;
}

// Funcion para crear una base de datos para registar los productos
void registrarProductos(string nombres[], float precios[], int stock[], int cantidadVendida[], int &cantidadActual) {
    if (cantidadActual >= N) {
        cout << "Error: La base de datos esta llena." << endl;
        return; 
    }

    // Ingresar el texto como una sola palabra
    cout << "Ingrese el nombre (use guion bajo para espacios, ej: agua_sin_gas): ";
    cin >> nombres[cantidadActual];

    float precio;
    cout << "Ingrese el precio del producto: $";
    cin >> precio;
    
    while (precio <= 0) {
        cout << "Error: El precio debe ser mayor a 0. Intente de nuevo: $";
        cin >> precio;
    }
    precios[cantidadActual] = precio;

    cout << "Ingrese el stock inicial: ";
    stock[cantidadActual] = validarOpcion(0, 10000);

    // [MEJORA] Sincronizamos el nuevo arreglo: el producto nace con 0 unidades vendidas
    cantidadVendida[cantidadActual] = 0; 

    cantidadActual++;
    cout << "Producto registrado exitosamente" << endl;
}

void mostrarInventario(string nombres[], float precios[], int stock[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "El inventario esta vacio. Registre productos primero." << endl;
        return;
    }

    cout << "ID     NOMBRE          PRECIO      STOCK" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        cout << i + 1 << "      " << nombres[i];
        cout << "            $" << precios[i];
        cout << "       " << stock[i] << endl;
    }
    cout << "---------------------------------------------\n";
}

void realizarVenta(string nombres[], float precios[], int stock[], int cantidadVendida[], int cantidadActual, float &totalCaja) {
    if (cantidadActual == 0) {
        cout << "No hay productos en el sistema para vender." << endl;
        return;
    }

    // Llamamos a la funcion mostrar inventario
    mostrarInventario(nombres, precios, stock, cantidadActual);
    
    cout << "\nIngrese el ID del producto que desea vender: ";
    int id = validarOpcion(1, cantidadActual); 
    int indice = id - 1; // Para ubicarnos en la posicion del arreglo

    if (stock[indice] == 0) {
        cout << "Lo sentimos, el producto '" << nombres[indice] << "' esta agotado.\n";
        return;
    }

    cout << "Ingrese la cantidad a vender (Stock disponible: " << stock[indice] << "): ";
    int cantidad = validarOpcion(1, stock[indice]);

    float subtotal = precios[indice] * cantidad;
    float iva = subtotal * 0.15; 
    float total = subtotal + iva;

    // Actualización de variables por referencia
    stock[indice] = stock[indice] - cantidad; 
    totalCaja = totalCaja + total;            
    
    // [MEJORA] Guardamos la cantidad de artículos para las estadísticas del Producto Estrella
    cantidadVendida[indice] = cantidadVendida[indice] + cantidad;       

    cout << "\n=== TICKET DE VENTA ===" << endl;
    cout << "Producto: " << nombres[indice] << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (15%): $" << iva << endl;
    cout << "TOTAL A PAGAR: $" << total << endl;
    cout << "=======================" << endl;
    cout << "Venta procesada con exito" << endl;
}

// Funcion de reportes (Mejora creativa)
void gestionarReportes(string nombres[], float precios[], int stock[], int cantidadVendida[], int cantidadActual, float totalCaja) {
    int opcionReporte;

    do {
        cout << "\n====================================" << endl;
        cout << "        MENU DE REPORTES            " << endl;
        cout << "====================================" << endl;
        cout << "1. Ver Total en Caja" << endl;
        cout << "2. Ver Productos en Stock Critico" << endl;
        cout << "3. Ver Producto Mas vendido" << endl;
        cout << "4. Ver Producto Menos Vendido" << endl;
        cout << "5. Regresar al Menu Principal" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opcion: ";
        
        opcionReporte = validarOpcion(1, 5);

        if (opcionReporte == 1) {
            cout << "\nTotal recaudado en caja: $" << totalCaja << "\n";
        } else if (opcionReporte == 2) {
            reporteStockCritico(nombres, stock, cantidadActual);
        } else if (opcionReporte == 3) {
            reporteProductoMasVendido(nombres, cantidadVendida, cantidadActual);
        } else if (opcionReporte == 4) {
            reporteProductoMenosVendido(nombres, cantidadVendida, cantidadActual);
        }

    } while (opcionReporte != 5);
    
    cout << "Regresando al Menu Principal..." << endl;
}

void reporteStockCritico(string nombres[], int stock[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay productos registrados en el sistema." << endl;
        return;
    }

    cout << "\n--- ALERTA DE STOCK CRITICO (3 unidades o menos) ---" << endl;
    int contadorCriticos = 0;

    for (int i = 0; i < cantidadActual; i++) {
        if (stock[i] <= 3) {
            cout << "- " << nombres[i] << " (Quedan " << stock[i] << " unidades)" << endl;
            contadorCriticos++;
        }
    }

    if (contadorCriticos == 0) {
        cout << "Todo bajo control! Ningun producto tiene stock bajo." << endl;
    }
}

void reporteProductoMasVendido(string nombres[], int cantidadVendida[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay productos registrados en el sistema." << endl;
        return;
    }

    int mayorVenta = 0;
    int indiceEstrella = -1; 

    // Algoritmo para encontrar el número mayor en un arreglo
    for (int i = 0; i < cantidadActual; i++) {
        if (cantidadVendida[i] > mayorVenta) {
            mayorVenta = cantidadVendida[i];
            indiceEstrella = i;
        }
    }

    cout << "\n--- ESTADISTICAS: PRODUCTO MAS VENDIDO ---" << endl;
    if (mayorVenta == 0) {
        cout << "Aun no se han realizado ventas. Ningun producto destaca todavia." << endl;
    } else {
        cout << "El producto mas vendido de la jornada es: '" << nombres[indiceEstrella] << "'" << endl;
        cout << "Total de unidades facturadas: " << mayorVenta << endl;
    }
}

void reporteProductoMenosVendido(string nombres[], int cantidadVendida[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay productos registrados en el sistema.\n";
        return;
    }

    // Validamos primero si realmente se ha vendido algo en el día
    int totalVendidoSistema = 0;
    for (int i = 0; i < cantidadActual; i++) {
        totalVendidoSistema = totalVendidoSistema + cantidadVendida[i];
    }

    cout << "\n--- ESTADISTICAS: PRODUCTO MENOS VENDIDO ---\n";
    if (totalVendidoSistema == 0) {
        cout << "Aun no se han realizado ventas. Ningun producto registra movimiento.\n";
        return;
    }

    // Algoritmo para encontrar el menor en un arreglo
    // Inicializamos asumiendo que el primero (índice 0) es el menos vendido
    int menorVenta = cantidadVendida[0];
    int indiceMenor = 0;

    // Recorremos desde la posición 1 en adelante para comparar
    for (int i = 1; i < cantidadActual; i++) {
        if (cantidadVendida[i] < menorVenta) {
            menorVenta = cantidadVendida[i];
            indiceMenor = i;
        }
    }

    cout << "El producto menos vendido de la jornada es: '" << nombres[indiceMenor] << "'" << endl;
    cout << "Total de unidades facturadas: " << menorVenta << endl;
}