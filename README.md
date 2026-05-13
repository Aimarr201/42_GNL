# Get Next Line

*Este proyecto ha sido creado como parte del currículo de 42 por amendibi.*

---

## Descripción

**Get Next Line** es un proyecto fundamental en el currículo de 42 que te enseña a manejar descriptores de archivo y lectura de datos en C. El objetivo es implementar una función que devuelva línea por línea el contenido de un archivo, utilizando un buffer de tamaño configurable.

### Objetivo
Crear una función `get_next_line()` que:
- Lee de un descriptor de archivo línea a línea
- Permite iterar sobre el contenido completo de un archivo
- Maneja correctamente el final de línea (`\n`)
- Gestiona múltiples archivos y stdin
- Utiliza un buffer de lectura configurable para optimizar el rendimiento

Este proyecto es esencial para comprender:
- Variables estáticas en C
- Gestión de memoria dinámica
- Lectura de archivos y descriptores de archivo
- Buffers y algoritmos de lectura eficientes

---

## Instrucciones

### Compilación

#### Compilación básica
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

#### Con tamaño de buffer por defecto (sin -D BUFFER_SIZE)
```bash
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
```

### Uso

La función tiene el siguiente prototipo:
```c
char    *get_next_line(int fd);
```

#### Parámetro
- `fd`: Descriptor de archivo (file descriptor) a leer

#### Valor devuelto
- **Éxito**: Pointer a la línea leída (terminada en `\n`, excepto en EOF sin `\n`)
- **Fallo o fin de archivo**: `NULL`

#### Ejemplo de uso
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Lectura de stdin
```c
char *line;

while ((line = get_next_line(0)) != NULL)  // fd 0 = stdin
{
    printf("Leído: %s", line);
    free(line);
}
```

---

## Algoritmo y Decisiones Técnicas

### Enfoque General

La implementación utiliza una **variable estática** para mantener el estado entre llamadas:

1. **Buffer estático**: Almacena datos no procesados de lecturas anteriores
2. **Lectura incremental**: Lee solo lo necesario con `read()` usando `BUFFER_SIZE`
3. **Búsqueda de salto de línea**: Busca `\n` en el buffer actual
4. **Extracción de línea**: Cuando encuentra `\n`, crea una nueva línea y guarda el resto

### Flujo de ejecución

```
┌─ get_next_line(fd)
│
├─ ¿Buffer estático está vacío?
│  ├─ SÍ → Leer con read() (BUFFER_SIZE)
│  └─ NO → Continuar
│
├─ Buscar '\n' en el buffer
│  ├─ Encontrado → Extraer línea
│  └─ No encontrado → Leer más
│
├─ ¿Fin de archivo (EOF)?
│  ├─ SÍ → Devolver línea incompleta
│  └─ NO → Continuar leyendo
│
└─ Guardar resto y devolver línea
```

### Puntos clave de implementación

**1. Variable estática para persistencia**
```c
static char *buffer = NULL;
```

**2. Lectura adaptativa**
- Si `BUFFER_SIZE = 1`: Lee byte a byte (lento pero funciona)
- Si `BUFFER_SIZE = 42`: Balance entre rendimiento y memoria
- Si `BUFFER_SIZE = 9999`: Lectura más rápida, más memoria

**3. Manejo de final de línea**
- Si hay `\n`: se devuelve incluyéndola
- Si es EOF sin `\n`: se devuelve la última línea sin `\n`
- Si es EOF sin datos: devuelve `NULL`

---

## Archivos del proyecto

- `get_next_line.h` - Archivo de cabecera con el prototipo de la función
- `get_next_line.c` - Implementación principal de la función
- `get_next_line_utils.c` - Funciones auxiliares

---

## Recursos

### Documentación y referencias
- [Manual de read() - Linux](https://man7.org/linux/man-pages/man2/read.2.html)
- [Manual de open() - Linux](https://man7.org/linux/man-pages/man2/open.2.html)
- [Gestión de memoria en C - malloc/free](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Variables estáticas en C](https://en.cppreference.com/w/c/language/storage_duration)

### Artículos y tutoriales
- [File Descriptors en Unix/Linux](https://en.wikipedia.org/wiki/File_descriptor)
- [Buffering en C - Conceptos básicos](https://www.cprogramming.com/tutorial/cfileio.html)
- [Memory Management in C](https://www.geeksforgeeks.org/memory-management-in-c/)