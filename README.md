*Este proyecto ha sido creado como parte del curriculo de 42 por rafsanch.*

# ft_printf

## Descripcion

`ft_printf` es una reimplementacion de la funcion `printf()` de la libc.
El objetivo del proyecto es aprender a trabajar con funciones variadicas en C,
recorrer una cadena de formato y delegar cada conversion a una rutina
especifica.

La libreria generada por el proyecto es `libftprintf.a` y contiene la funcion:

```c
int ft_printf(const char *format, ...);
```

La parte obligatoria implementa las siguientes conversiones:

- `%c` para imprimir un caracter.
- `%s` para imprimir una cadena.
- `%p` para imprimir un puntero en hexadecimal.
- `%d` y `%i` para imprimir enteros con signo en base 10.
- `%u` para imprimir enteros sin signo en base 10.
- `%x` para imprimir un numero hexadecimal en minusculas.
- `%X` para imprimir un numero hexadecimal en mayusculas.
- `%%` para imprimir el simbolo `%`.

Este proyecto no implementa la gestion del buffer interno del `printf`
original ni, en su estado actual, la parte bonus.

## Instrucciones

### Requisitos

- Un compilador compatible con `cc`.
- `make`.

### Compilacion

Para compilar la libreria:

```bash
make
```

Esto genera `libftprintf.a` en la raiz del repositorio y compila primero la
`libft` incluida en el directorio `libft/`.

Reglas disponibles:

- `make` o `make all`: compila la libreria.
- `make clean`: elimina los objetos.
- `make fclean`: elimina los objetos y la libreria.
- `make re`: recompila desde cero.

### Uso

Ejemplo de programa:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, numero=%d, hex=%x, ptr=%p\n", "42", 42, 42, "42");
    return (0);
}
```

Ejemplo de compilacion enlazando la libreria:

```bash
cc main.c libftprintf.a -I. -o demo
```

### Pruebas recomendadas

Para revisar el comportamiento de la parte obligatoria conviene comparar la
salida y el valor de retorno con `printf()` usando casos como estos:

- cadenas normales y `NULL`
- enteros positivos, negativos y extremos
- enteros sin signo grandes
- hexadecimal en minusculas y mayusculas
- punteros validos y `NULL`
- mezclas de varias conversiones en una misma llamada

## Diseno y decisiones tecnicas

### Enfoque general

La implementacion sigue un recorrido lineal de la cadena `format`.
Cada vez que aparece un caracter normal, se escribe directamente con `write`.
Cuando aparece `%`, el caracter siguiente determina la conversion y se delega
en una funcion auxiliar encargada de imprimir ese tipo concreto.

Este enfoque es sencillo, mantiene la logica de parseo separada de la logica
de impresion y facilita depurar errores por conversion.

### Algoritmo

El algoritmo principal de `ft_printf` puede resumirse asi:

1. Inicializar `va_list` con `va_start`.
2. Recorrer `format` caracter a caracter.
3. Si el caracter actual no es `%`, escribirlo y sumar 1 al contador.
4. Si el caracter actual es `%`, identificar la conversion siguiente.
5. Llamar a la rutina adecuada para imprimir el argumento correspondiente.
6. Sumar al contador el numero de caracteres escritos por esa rutina.
7. Finalizar `va_list` con `va_end` y devolver el total.

La complejidad temporal es lineal respecto al tamano del formato mas el coste
de convertir cada numero en su representacion textual.

### Estructura de datos

La implementacion obligatoria no necesita estructuras de datos complejas.
La eleccion ha sido trabajar con:

- una cadena de formato recorrida secuencialmente
- un `va_list` para acceder a los argumentos variadicos
- pequenos buffers locales en la pila para reconstruir numeros en base 10
- recursion para imprimir numeros en hexadecimal de forma natural

La decision de no usar memoria dinamica en la parte obligatoria reduce mucho
el riesgo de fugas, simplifica el control de errores y es suficiente para el
alcance del proyecto.

### Conversion de numeros

Para `%d`, `%i` y `%u`, los digitos se obtienen dividiendo sucesivamente por la
base y guardando el resultado en un buffer local para despues imprimirlos en
orden inverso.

Para `%x`, `%X` y `%p`, la representacion hexadecimal se resuelve con una
funcion recursiva que imprime primero la parte mas significativa y despues el
digito actual. En el caso de `%p`, se antepone el prefijo `0x` y se trata el
caso `NULL` de forma explicita.

## Estructura del proyecto

```text
.
|-- ft_printf.c
|-- ft_format.c
|-- ft_utils.c
|-- ft_printf.h
|-- Makefile
`-- libft/
```

- `ft_printf.c`: recorrido del formato y control general del conteo.
- `ft_format.c`: seleccion de conversiones y salida de caracteres, cadenas y
  enteros con signo.
- `ft_utils.c`: salida de enteros sin signo, hexadecimales y punteros.
- `ft_printf.h`: prototipos e includes necesarios.
- `libft/`: copia de la `libft` usada por el proyecto.

## Recursos

### Referencias tecnicas

- Manual de `printf(3)`: <https://man7.org/linux/man-pages/man3/printf.3.html>
- Manual de `stdarg(3)`: <https://man7.org/linux/man-pages/man3/stdarg.3.html>
- Manual de `write(2)`: <https://man7.org/linux/man-pages/man2/write.2.html>
- Documentacion del lenguaje C en cppreference:
  <https://en.cppreference.com/w/c/variadic>

### Uso de IA

Durante la documentacion y revision de este proyecto se ha utilizado IA para:

- revisar el cumplimiento del subject
- detectar riesgos funcionales y de portabilidad

En el momento de escribir este documento, esta seccion describe con certeza el
uso de IA en la revision y en la documentacion. Si se ha utilizado IA en otras
partes del desarrollo, esta seccion debe ampliarse antes de la entrega para
que refleje con precision todo su uso.
