#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file stack.h
 * @brief Pila (stack) dinámica de enteros con disciplina LIFO.
 *
 * Implementa una pila de `int` respaldada por un arreglo redimensionable en el heap.
 * Las operaciones principales (`push`, `pop`, `top`) son O(1) en costo amortizado.
 *
 * ### Ejemplo de uso
 * @code
 * stack_t* s = stack_create(0);
 * stack_push(s, 10);
 * stack_push(s, 20);
 * int v;
 * stack_top(s, &v);
 * stack_pop(s, &v);
 * stack_destroy(s);
 * @endcode
 */

/** @brief Tipo que representa la pila de enteros. */
typedef struct stack stack_t;

/**
 * @brief Crea una pila vacía.
 *
 * Si `initial_cap` es 0, la reserva del buffer interno se difiere hasta el primer `push`.
 *
 * @param initial_cap Capacidad inicial del arreglo interno (puede ser 0).
 * @return
 *   - Puntero válido a `stack_t` si la creación tuvo éxito.
 *   - `NULL` si no hay memoria suficiente (OOM).
 */
stack_t* stack_create(size_t initial_cap);

/**
 * @brief Destruye la pila y libera todos los recursos asociados.
 *
 * Libera el arreglo interno y la propia estructura.
 * Tolera `s == NULL` (no realiza acción en ese caso).
 *
 * @param s Puntero a la pila a destruir.
 */
void stack_destroy(stack_t* s);

/**
 * @brief Inserta un entero en el tope de la pila (push).
 *
 * Si no hay capacidad disponible, intenta crecer la capacidad de forma geométrica.
 *
 * @param s     Puntero a la pila (no debe ser `NULL`).
 * @param value Valor entero a insertar.
 * @retval 0 Operación exitosa.
 * @retval -1 Error: `s == NULL` o falta de memoria (OOM) al crecer el buffer.
 */
int stack_push(stack_t* s, int value);

/**
 * @brief Extrae el entero del top de la pila (pop).
 *
 * @param s   Puntero a la pila (se permite `NULL`).
 * @param out Puntero de salida donde se escribirá el valor extraído.
 *            Puede ser `NULL` si se desea descartar el valor.
 * @retval 0 Operación exitosa; si `out != NULL`, se escribe el valor.
 * @retval -1 Error: pila vacía o `s == NULL`.
 *
 * @warning Llamar a `stack_pop` sobre una pila vacía no modifica el estado y
 *          retorna `-1`.
 */
int stack_pop(stack_t* s, int* out);

/**
 * @brief Lee el entero del tope sin extraerlo (peek/top).
 *
 * @param s   Puntero a la pila (se permite `NULL`).
 * @param out Puntero de salida donde se escribirá el valor del tope.
 *            Debe ser no-NULL para obtener el dato; si es `NULL`, la función
 *            sirve sólo como comprobación de no-vacío.
 * @retval 0 Operación exitosa; si `out != NULL`, se escribe el valor.
 * @retval -1 Error: pila vacía o `s == NULL`.
 */
void stack_top(const stack_t* s, int* out);

/**
 * @brief Devuelve el número de elementos actualmente en la pila.
 *
 * @param s Puntero a la pila (se permite `NULL`).
 * @return Cantidad de elementos; si `s == NULL`, devuelve 0.
 */
size_t stack_size(const stack_t* s);

/**
 * @brief Indica si la pila está vacía.
 *
 * @param s Puntero a la pila (se permite `NULL`).
 * @retval true  Si `s == NULL` o si el tamaño es 0.
 * @retval false En caso contrario.
 */
bool stack_is_empty(const stack_t* s);

/**
 * @brief Imprime el contenido de la pila de tope a fondo.
 *
 * @param s Puntero a la pila. Se permite `NULL` (no hace nada).
 */
void stack_print(const stack_t* s);

#endif /* STACK_H */

