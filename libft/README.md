*Este proyecto ha sido creado como parte del currículo de 42 por <rafsanch>.*

# Libft

## Descripción

**Libft** es el primer proyecto del cursus de 42 y consiste en la creación de una librería propia en C.
El objetivo principal es **reimplementar funciones básicas de la libc**, así como desarrollar funciones adicionales y utilidades para trabajar con **cadenas, memoria y listas enlazadas**.

Esta librería está pensada para ser reutilizada en proyectos futuros, sirviendo como una base sólida para comprender el funcionamiento interno de funciones estándar y mejorar la calidad del código en C.

## Instrucciones

### Compilación

Para compilar la librería, ejecuta:

```bash
make
```

Esto generará el archivo `libft.a` en la raíz del repositorio.

### Reglas disponibles en el Makefile

* `make` o `make all` → compila la librería
* `make clean` → elimina archivos objeto
* `make fclean` → elimina archivos objeto y `libft.a`
* `make re` → recompila todo desde cero

### Uso

Para usar la librería en tu proyecto:

1. Incluye el header:

```c
#include "libft.h"
```

2. Compila tu proyecto enlazando `libft.a`:

```bash
cc main.c libft.a -Wall -Wextra -Werror
```

## Contenido de la librería

### Parte 1 – Funciones de libc

Reimplementación de funciones estándar, entre otras:

* `ft_strlen`
* `ft_memset`
* `ft_bzero`
* `ft_memcpy`
* `ft_memmove`
* `ft_strlcpy`
* `ft_strlcat`
* `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* `ft_toupper`, `ft_tolower`
* `ft_strchr`, `ft_strrchr`
* `ft_strncmp`
* `ft_memchr`, `ft_memcmp`
* `ft_strnstr`
* `ft_atoi`
* `ft_calloc`
* `ft_strdup`

### Parte 2 – Funciones adicionales

Funciones utilitarias para trabajar con strings y números:

* `ft_substr`
* `ft_strjoin`
* `ft_strtrim`
* `ft_split`
* `ft_itoa`
* `ft_strmapi`
* `ft_striteri`
* `ft_putchar_fd`
* `ft_putstr_fd`
* `ft_putendl_fd`
* `ft_putnbr_fd`

### Parte 3 – Listas enlazadas

Implementación de una estructura de lista enlazada y sus funciones asociadas:

* `ft_lstnew`
* `ft_lstadd_front`
* `ft_lstsize`
* `ft_lstlast`
* `ft_lstadd_back`
* `ft_lstdelone`
* `ft_lstclear`
* `ft_lstiter`
* `ft_lstmap`

## Recursos

### Documentación y referencias

* Manuales de Unix (`man strlen`, `man memcpy`, etc.)
* Documentación oficial de C

### Uso de IA

La IA **no se ha utilizado para generar código directamente**.
Se ha empleado únicamente como **herramienta de apoyo teórico**, para:

* Comprender el comportamiento de funciones estándar
* Aclarar conceptos de memoria, punteros y listas enlazadas
* Revisar explicaciones y mejorar la comprensión del subject

Todo el código ha sido **diseñado, escrito y probado manualmente** como parte del proceso de aprendizaje.
