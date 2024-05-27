#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100

struct Producto {
    char nombre[50];
    int cantidad;
    float precio;
};

struct Producto inventario[MAX_PRODUCTOS];
int numProductos = 0;

// Funciones
void ingresarProducto();
void editarProducto();
void eliminarProducto();
void listarProductos();
int buscarProducto(const char *nombre);

int main() {
    int opcion;

    do {
        printf("\nSistema de Inventario de Ropa\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");

        // Limpiar el búfer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

void ingresarProducto() {
    if (numProductos >= MAX_PRODUCTOS) {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
        return;
    }

    printf("\nIngresar nuevo producto:\n");
    printf("Nombre: ");
    scanf("%s", inventario[numProductos].nombre);

    printf("Cantidad: ");
    scanf("%d", &inventario[numProductos].cantidad);
    printf("Precio: ");
    scanf("%f", &inventario[numProductos].precio);

    numProductos++;
    printf("Producto ingresado exitosamente.\n");
}

void editarProducto() {
    char nombre[50];
    printf("\nEditar producto:\n");
    printf("Nombre del producto a editar: ");
    scanf("%s", nombre);

    int indice = buscarProducto(nombre);
    if (indice == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Nueva cantidad (actual: %d): ", inventario[indice].cantidad);
    scanf("%d", &inventario[indice].cantidad);
    printf("Nuevo precio (actual: %.2f): ", inventario[indice].precio);
    scanf("%f", &inventario[indice].precio);

    printf("Producto editado exitosamente.\n");
}

void eliminarProducto() {
    char nombre[50];
    printf("\nEliminar producto:\n");
    printf("Nombre del producto a eliminar: ");
    scanf("%s", nombre);

    int indice = buscarProducto(nombre);
    if (indice == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = indice; i < numProductos - 1; i++) {
        inventario[i] = inventario[i + 1];
    }
    numProductos--;

    printf("Producto eliminado exitosamente.\n");
}

int buscarProducto(const char *nombre) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void listarProductos() {
    if (numProductos == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("\nListado de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n",
               inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}
