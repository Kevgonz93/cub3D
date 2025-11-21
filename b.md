# 👤 Persona B — Motor gráfico, MLX, Raycasting y Movimiento

La parte más visible del proyecto. Es más matemática y práctica.

Responsable de:

## 1️⃣ Setup de MLX

- mlx_init()
- mlx_new_window()
- mlx_new_image()
- Obtener buffer con mlx_get_data_addr

## 2️⃣ Dibujar un pixelfill (test inicial)

Comprobar que puedes pintar la pantalla de un color.

## 3️⃣ Implementar el Raycasting (DDA)

- Lógica columna por columna
- Cálculo de rayos
- Algoritmo DDA para encontrar muros
- Distancia perpendicular
- Altura de la pared
- Dibujar paredes sólidas (sin textura todavía)

## 4️⃣ Movimiento del jugador

- W/S → avanzar, retroceder
- A/D → girar
- Colisiones con el mapa

## 5️⃣ Texturas

- mlx_xpm_file_to_image
- Obtener pixel de textura
- Calcular texX, texY
- Aplicar textura según el lado del muro

## 6️⃣ Event Loop

- mlx_hook para teclas
- Movimiento continuo al mantener tecla
- Manejo del cierre de ventana

## 7️⃣ Integración final

- Unir las estructuras de Persona A
- Cargar texturas con las rutas parseadas
- Usar las coordenadas iniciales de jugador
- Mapear la matriz validada
