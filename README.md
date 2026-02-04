This project has been created as part of the 42 curriculum by akwadran, kegonzal.

# DESPCRIPTION
The project CUB3D aims to create a game engine in C using raycasting and the MiniLibX library.

# INSTRUCTIONS
After compiling, execute the cub3d file selecting one of the maps from the .maps directory
```bash
make
./cub3d maps/map.cub
```

# RESOURCES
https://lodev.org/cgtutor/raycasting.html
https://www.youtube.com/watch?v=NbSee-XM7WA
https://aaaa.sh/creatures/dda-algorithm-interactive/
https://hackmd.io/@nszl/H1LXByIE2

The IA was used for explaining the math concepts needed for the project and for getting ideas of how to test it.




# cub3d - 42 Project

---

## 📜 Descripción

Proyecto **cub3D** de la escuela 42 (raycasting en 3D estilo Wolfenstein).

---

## 📋 Requisitos

Para compilar y ejecutar este proyecto, necesitas:

Un sistema UNIX (macOS o Linux)
Make y un compilador compatible con C (gcc o clang)
En macOS: Los frameworks OpenGL y AppKit (incluidos por defecto en el sistema)
En Linux: Las bibliotecas X11 y Xext

---

## Objetivo

- Implementar un motor de raycasting en C usando la librería MiniLibX.
- Renderizar un mapa 2D en una vista pseudo-3D en primera persona.
- Gestionar:
  - Movimientos del jugador
  - Colisiones con paredes
  - Texturas
  - Minimapa (opcional)

## 🛠️ Cómo Compilar y Ejecutar

1. Clonar el repositorio

```bash
  git clone https://github.com/Kevgonz93/cub3D
  cd cub3d
```

2. Compilar el proyecto

```bash
  make
```

3. Ejecutar el programa

```bash
  ./cub3D mapa.cub
```

---

## 🚀 Características

### Makefile

El Makefile de este proyecto está hecho para poder compilar tanto en MacOS y Linux, según corresponda.

### Movimientos

- Flechas: Izquierda y derecha girarán la vista en el sentido que corresponda.
- Letras : "A,S,D,W" moverán la visa hacia el sentido que corresponda.
- Teclas : "Esc" abrirá un menú de confirmación de salida del juego.

## Estructura del Proyecto

📦 cub3d
├── 📂 debug			# Funciones auxiliares con fines de debug
├── 📂 includes			# Headers utilizados en el proyecto.
├── 📂 maps				# Ficheros con mapas predeterminados.
├── 📂 minilibx			# minilibx descomprimida.
├── 📂 src				# Funciones útiles para la app.
    ├── 📂 config		# Funciones de configuración de estructuras principales para el desarrollo de la app.
    ├── 📂 events		# Funciones de ejecución de eventos.
    ├── 📂 parsing		# Funciones de parseo del mapa.
    ├── 📂 rendering	# Funciones de renderizado.
	└── 📂 utils		# Funciones de utilidad (libft).
├── 📂 textures			# Ficheros con texturas predeterminadas.
├── main.c					# Fichero principal, incluye main.
├── Makefile				# Makefile para compilar el proyecto.
└── READEME.md				# Este documento