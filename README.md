# 🧠 Tarea 2 - Principios de Sistemas Operativos

Repositorio para el control de versiones de la **Tarea 2** del curso **Principios de Sistemas Operativos**.

**Autor:** René Sánchez Torres  
**Carné:** 2020051805  
**Institución:** Tecnológico de Costa Rica

---

## 🛠️ Descripción

Este programa permite realizar un **rastreo de llamadas al sistema** realizadas por otro programa, con diferentes niveles de detalle y control.

---

## 🚀 Compilación

Para compilar el programa, usa el siguiente comando en la terminal:

```bash
gcc -o rastreador rastreador.c syscall_map.c
```
## 🦾 EJECUCIÓN 
Muestra un menú para ver las 3 opciones de llamado.
```bash
./rastreador -h 
```
Rastreo básico.
```bash
./rastreador ls
```
Rastreo con detalles.
```bash
./rastreador -v ls 
```
Rastreo con pausas.
```bash
./rastreador -V ls
```


