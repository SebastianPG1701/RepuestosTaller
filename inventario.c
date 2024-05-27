#include <stdio.h>
#include <string.h>
#include "inventario.h"

int maxProductos = 20;
int maxNombre = 50;

char nombres[20][50];
int cantidades[20];
float precios[20];

int numRepuestos = 0;

void imprimirMenu() {
    printf("\n=== Menú ===\n");
    printf("1. Ingresar nuevo repuesto\n");
    printf("2. Editar repuesto\n");
    printf("3. Eliminar repuesto\n");
    printf("4. Listar repuestos\n");
    printf("5. Calcular total de dinero\n");
    printf("6. Salir\n");
    printf("============\n");
}

void ingresarRepuesto() {
    if (numRepuestos >= maxProductos) {
        printf("Error: inventario lleno.\n");
        return;
    }

    printf("Ingrese el nombre del repuesto: ");
    scanf("%s", nombres[numRepuestos]);

    
    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombres[numRepuestos]) == 0) {
            printf("Ingrese la cantidad adicional: ");
            scanf("%d", &cantidades[i]);
            cantidades[i] += cantidades[numRepuestos];
            printf("Cantidad actualizada correctamente.\n");
            return;
        }
    }

   
    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidades[numRepuestos]);
    printf("Ingrese el precio: ");
    scanf("%f", &precios[numRepuestos]);

    numRepuestos++;
    printf("Repuesto ingresado correctamente.\n");
}

void editarRepuesto() {
    char nombreEditar[50];
    printf("Ingrese el nombre del repuesto a editar: ");
    scanf("%s", nombreEditar);

    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreEditar) == 0) {
            printf("Ingrese la nueva cantidad: ");
            scanf("%d", &cantidades[i]);
            printf("Repuesto editado correctamente.\n");
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}

void eliminarRepuesto() {
    char nombreEliminar[50];
    printf("Ingrese el nombre del repuesto a eliminar: ");
    scanf("%s", nombreEliminar);

    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreEliminar) == 0) {
            for (int j = i; j < numRepuestos - 1; j++) {
                for (int k = 0; k < maxNombre; k++) {
                    nombres[j][k] = nombres[j + 1][k];
                }
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            numRepuestos--;
            printf("Repuesto eliminado correctamente.\n");
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}

void listarRepuestos() {
    printf("\n=== Inventario de Repuestos ===\n");
    for (int i = 0; i < numRepuestos; i++) {
        printf("Nombre: %s\n", nombres[i]);
        printf("Cantidad: %d\n", cantidades[i]);
        printf("Precio: %.2f\n", precios[i]);
        printf("Total: %.2f\n", cantidades[i] * precios[i]);
        printf("-----------------------------\n");
    }
    printf("Total de repuestos: %d\n", numRepuestos);
    printf("==============================\n");
}

float calcularTotalDinero() {
    float total = 0;
    for (int i = 0; i < numRepuestos; i++) {
        total += cantidades[i] * precios[i];
    }
    return total;
}




