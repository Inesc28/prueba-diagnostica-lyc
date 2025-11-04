# Guía de Instalación y Ejecución de Ejercicios

Este documento describe los componentes y pasos necesarios para compilar y ejecutar los ejercicios desarrollados en Windows, Linux y macOS.

---

## ⚙️ Ejercicios de C++

Los ejercicios están escritos en C++ y requieren un compilador.

### 1. Dependencias (Componentes)

Se necesita un compilador de C++ (como `g++`) y la herramienta `make`.

### 2. Script de Instalación

#### En Windows

En Windows, no tenemos `g++` o `make` por defecto. La forma más sencilla de instalarlos es a través del paquete **MinGW-w64** (que provee `g++`) y **Make for Windows**.

Puedes instalarlos usando el gestor de paquetes `winget` (desde PowerShell o Símbolo del sistema):

```bash
# Instala el compilador g++ (parte de MinGW)
winget install -e --id MinGW-w64.MinGW-w64

# Instala la herramienta 'make'
winget install -e --id GnuWin32.Make
```

**NOTA MUY IMPORTANTE:** Después de instalar, debes agregar las carpetas `bin` de MinGW y Make a tu **PATH** del sistema para poder usarlos desde cualquier terminal.
* Por lo general, estarán en `C:\Program Files\mingw-w64\...\bin` y `C:\Program Files (x86)\GnuWin32\bin`.

#### En Debian/Ubuntu (Linux)

```bash
sudo apt update
sudo apt install build-essential g++ make
```

#### En macOS

```bash
brew install gcc make
```

### 3. Compilación y Ejecución

Para compilar el [nombre de tu programa, ej: ejercicio_final]:

```bash
# Compila el programa usando el Makefile
make

# Si no tienes Makefile, usa este comando manual:
# g++ -o [nombre_del_ejecutable] [nombre_del_fuente.cpp] -Wall
```

Para ejecutar el programa:

```bash
# En Windows (CMD o PowerShell)
.\\[nombre_del_ejecutable].exe

# En Linux/macOS
./[nombre_del_ejecutable]
```

Para limpiar los archivos compilados:

```bash
make clean
```

---

## 🐍 Ejercicio de Python

El script de Python se desarrolló con **Python 3.11**.

### 1. Dependencias (Componentes)

> No se requiere ninguna librería externa. Solo se utiliza la biblioteca estándar de Python.

### 2. Script de Instalación

#### En Windows

Puedes usar `winget` para instalar Python, lo cual lo agregará a tu PATH automáticamente:

```bash
winget install -e --id Python.Python.3.11
```

Alternativamente, descarga el instalador desde `python.org` y asegúrate de marcar la casilla **"Add Python to PATH"** durante la instalación.

### 3. Ejecución

El comando de ejecución es el mismo en todos los sistemas:

```bash
python [nombre_del_archivo.py]
```
