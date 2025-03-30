# Tarea2-SO
Repositorio para control de cambios de la Tarea 2 de Principios de Sistemas Operativos 

René Sánchez Torres
2020051805
Tec

Uso del programa:
1. Compilar 
gcc -o rastreador rastreador.c syscall_map.c

2. Ejecutar con las diferentes opciones
./rastreador -h -> Muestra un menú para ver las 3 opciones de llamado.


Rastreo básico: ./rastreador ls
Rastreo con detalles: ./rastreador -v ls 
Rastreo con pausas: ./rastreador -V ls
