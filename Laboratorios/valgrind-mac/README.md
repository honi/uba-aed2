# Valgrind + MacOS

Una forma de correr Valgrind en MacOS es usando Docker. En esencia recompilamos el proyecto adentro de un container de Ubuntu y luego corremos Valgrind adentro del container.

Es necesario recompilar ya que el binario compilado para MacOS no funciona para Linux (al menos con la configuración default de los labos).

La solución es super básica, es simplemente un bash script para tipear menos (uno podría ejecutar el comando explícito cada vez pero sería muy incómodo).

## Configuración

### Docker
Instalar [Docker](https://docs.docker.com/desktop/mac/install/) si no lo tenés.

### PATH

Agregá esta carpeta en tu `$PATH` así podes ejecutar el comando `valgrind-mac` desde cualquier ubicación. Caso contrario, tenes que buscar la forma de referenciar al script desde la carpeta del labo que estés haciendo, ya sea con una ruta relativa o absoluta.

Una forma de hacer esto es con el siguiente comando:

```bash
echo "PATH=\"$(pwd):\$PATH\"" >> ~/.bash_profile
```

### Buildear imagen

La imagen de Docker es un Ubuntu con el toolchain de C++ y Valgrind. Por única vez es necesario hacer un build de esta imagen con el siguiente comando:

```bash
valgrind-mac setup
```

Podemos verificar que el build fue exitoso con el siguiente comando:

```
docker images | grep aed2-valgrind
```

Deberías ver una línea con el hash y tamaño de la imagen de Docker. Si no aparece nada es porque pasaron cosas.

## Modo de uso

Para correr los targets de Valgrind de un proyecto del labo tenemos que abrir una terminal y pararnos en la raíz del proyecto C++ (donde está ubicado el archivo `CMakeLists.txt`).

Luego, simplemente corremos el siguiente comando:

```bash
valgrind-mac TARGET
```

Donde `TARGET` es algún target de CMake. Generalmente vamos a correr algún target que invoca a Valgrind. Cada proyecto define sus propios targets así que hay que mirar el archivo `CMakeLists.txt` para ver cómo se llaman exactamente (algunos ejemplos: `correrValgrind`, `ej2_correrValgrind`, etc).
