# 👤 Persona A — Parsing, Validación y Gestión de recursos

Es la parte más delicada pero muy controlable. Incluye todo lo que no es MLX.

Responsable de:

## 1️⃣ Parsing del archivo .cub

- Leer línea por línea
- Identificar NO, SO, WE, EA
- Leer colores F y C
- Guardar el mapa en una matriz dinámica

## 2️⃣ Validación del mapa

- Comprobar que el mapa es rectangular
- Que solo contiene caracteres válidos
- Que hay solo un jugador y obtener su posición
- Cerrar el mapa con flood fill
- Comprobar huecos o espacios peligrosos

## 3️⃣ Normalización de datos

- Quitar espacios sobrantes
- Alinear todas las filas del mapa
- Rellenar con ‘1’ o ‘0’ si hace falta

## 4️⃣ Gestión de estructuras

Crear todas las estructuras necesarias:

```C
typedef struct s_map {
    char **grid;
    int width;
    int height;
}   t_map;

typedef struct s_texture {
    void *img;
    char *addr;
}   t_texture;

typedef struct s_config {
    char *no;
    char *so;
    char *we;
    char *ea;
    int floor_color;
    int ceil_color;
    t_map map;
}   t_config;
```

## 5️⃣ Manejo de errores y memory leaks

- free_split
- free_map
- exit_error("msg")

## 6️⃣ Dejar funciones listas para el motor

- t_player init_player(t_map \*map)
- int \*\*convert_map_to_int(...) (opcional)
- t_config *parse_file(char *path)
