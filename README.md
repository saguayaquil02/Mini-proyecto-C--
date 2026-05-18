# Mini-proyecto en C++

## Descripción
Este repositorio corresponde al Mini - proyecto en C++

# Sistema de control de ventas
Este es un proyecto desarrollado en **C++**. El sistema simula la gestión interna de un negocio mediante el uso de arreglos para almacenar de forma síncrona los datos de productos, precios, existencias e historial de ventas.

El diseño del código se hizo empleando arreglos y funciones para cada tarea específica, pasos de parámetros por referencia (`&`) para la alteración de estados y estructuras de control iterativas para la validación de datos.

## Funcionalidades Principales

* **Menú de Navegación Interactivo:** Diseñado mediante un ciclo repetitivo `do-while` y una estructura condicional `switch` para interactuar fluidamente con el usuario.
* **Registro de Productos:** Permite dar de alta nuevos artículos en el sistema asignándoles un nombre, un precio unitario validado (mayor a $0$) y un stock inicial.
* **Control de Inventario:** Despliega de forma tabular la lista completa de artículos registrados junto con sus ID visuales, precios y existencias en tiempo real.
* **Procesamiento de Ventas:** Ejecuta transacciones comerciales restando las unidades vendidas del stock actual, aplicando un cálculo matemático de IVA (15%) y acumulando los ingresos en la caja general del día.
  
## Mejoras Creativas Implementadas

Para aportar un valor analítico y organizativo real a la solución, se incorporaron las siguientes mejoras funcionales:

1. **Submenú de Reportes Administrativos:** Se descongestionó el menú principal aislando las métricas del negocio en una sección exclusiva para la gerencia.
2. **Reporte de Stock Crítico:** El sistema escanea el arreglo de existencias mediante un ciclo `for` y genera una alerta automática listando únicamente los productos que tienen **3 o menos unidades disponibles**, permitiendo una toma de decisiones oportuna para el reabastecimiento.
3. **Métrica de Producto Estrella (El más vendido):** Se añadió un arreglo paralelo de acumuladores (`cantidadVendida`). Cada vez que se procesa una venta, se registra el volumen transaccionado y una función implementa un algoritmo de búsqueda del elemento mayor para determinar qué artículo ha tenido mayor éxito comercial en la jornada.

## Estructura del Código

La arquitectura del script fuente se divide de forma secuencial en cuatro bloques limpios:
1. **Directivas y Constantes:** Inclusión de librerías esenciales (`<iostream>`, `<string>`) y la definición del límite estático del sistema (`const int N = 20;`).
2. **Prototipos de Funciones:** Declaración anticipada de los módulos funcionales para una compilación limpia.
3. **Función Principal (`main`):** Inicialización de los arreglos paralelos, variables de control de estado y el ciclo del menú principal.
4. **Desarrollo de Funciones:** Bloques lógicos independientes encargados de las tareas de cálculo, muestra de datos y filtrado de entradas.

## Autor
Proyecto desarrollado por Sebastian Guayaquil

## Especificaciones Técnicas y de Uso

> [!IMPORTANT]
> **Regla de Entrada de Datos:**  Al registrar el nombre de un producto, **este debe ingresarse como una sola palabra o utilizando guiones bajos para simular los espacios** (Ejemplo: `papa_frita`, `leche_entera`, `atun`).

## Compilación y Ejecución

Se puede ejecutar con un compilador de C++ y un IDE compatible como Visual Studio Code.

