#include <stdio.h>
#include "inventario.h"

int main() {
    char predefinidos[5][50] = {"Aceite", "Filtro_de_Aire", "Bujia", "Amortiguador", "Llantas"};
    int cantidadesPredefinidos[5] = {10, 15, 30, 5, 20};
    float preciosPredefinidos[5] = {20.0, 10.0, 5.0, 50.0, 100.0};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < maxNombre; j++) {
            nombres[i][j] = predefinidos[i][j];
        }
        cantidades[i] = cantidadesPredefinidos[i];
        precios[i] = preciosPredefinidos[i];
        numRepuestos++;
    }

    int opcion;

    do {
        imprimirMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarRepuesto();
                break;
            case 2:
                editarRepuesto();
                break;
            case 3:
                eliminarRepuesto();
                break;
            case 4:
                listarRepuestos();
                break;
            case 5:
                printf("El total de dinero en el inventario es: %.2f\n", calcularTotalDinero());
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while(opcion != 6);

    return 0;
}



