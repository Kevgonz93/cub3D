# cub3d - 42 Project

---

## 📜 Description

**cub3D** project from School 42 (Wolfenstein-style 3D raycasting).

---

## 📋 Requirements

To compile and run this project, you need:

A UNIX system (macOS or Linux)
Make and a C-compatible compiler (gcc or clang)
On macOS: The OpenGL and AppKit frameworks (included by default in the system)
On Linux: The X11 and Xext libraries

---

## Objective

- Implement a raycasting engine in C using the MiniLibX library.
- Render a 2D map in a pseudo-3D first-person view.
- Manage:
  - Player movements
  - Collisions with walls
  - Textures
  - Minimap (optional)

## 🛠️ How to Compile and Run

1. Clone the repository

```bash
  git clone https://github.com/Kevgonz93/cub3D
  cd cub3d
```

2. Compile the project

```bash
  make
```

3. Run the program

```bash
  ./cub3D mapa.cub
```

---

## 🚀 Features

### Makefile

The Makefile for this project is designed to compile on both MacOS and Linux, as appropriate.

### Movements

- Arrows: Left and right will rotate the view in the corresponding direction.
- Letters: “A,S,D,W” will move the view in the corresponding direction.
- Keys: “Esc” will open a menu to confirm exiting the game.

## Project Structure

📦 cub3d
├── 📂 debug            # Auxiliary functions for debugging purposes.
├── 📂 includes         # Headers used in the project.
├── 📂 maps             # Files with default maps.
├── 📂 minilibx         # Unzipped minilibx.
├── 📂 src              # Useful functions for the app.
    ├── 📂 config       # Configuration functions for main structures for app development.
    ├── 📂 events       # Event execution functions.
    ├── 📂 parsing      # Map parsing functions.
    ├── 📂 rendering    # Rendering functions.
    └── 📂 utils        # Utility functions (libft).
├── 📂 textures         # Files with default textures.
├── main.c              # Main file, includes main.
├── Makefile            # Makefile for compiling the project.
└── READEME.md          # This document

---

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

## Recursos

https://lodev.org/cgtutor/raycasting.html
https://www.youtube.com/watch?v=NbSee-XM7WA
https://aaaa.sh/creatures/dda-algorithm-interactive/
https://hackmd.io/@nszl/H1LXByIE2

The IA was used for explaining the math concepts needed for the project and for getting ideas of how to test it.

