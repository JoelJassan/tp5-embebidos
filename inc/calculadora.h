/*
 * 
 * Copyright may/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


/** \brief Declaracion de tipos y definicion de funciones de forma global (public) de la
 * calculadora.
 * 
*/


#ifndef CALCULADORA_H
#define CALCULADORA_H

/*---  Includes  ------------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

/* ---  Macros definitions  -------------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/**
 * @brief Puntero a la estructura calculadora_s.
 * El tipo de dato al que apunta es la calculadora que guarda las operaciones
 */
typedef struct calculadora_s * calculadora_t;

/**
 * @brief Funcion de Callback
 * Recibe 2 enteros y devuelve un entero. Solo se pueden usar este tipo de funciones
 */
typedef int(*funciont_t)(int,int);

/*---  Public Function Declaration  ------------------------------------------------------------ */

/**
 * @brief Crea la calculadora, creando el puntero a la direccion de memoria donde empieza la
 * calculadora creada.
 * El espacio se inicializa en NULL.
 * 
 * @return calculadora_t 
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Agrega operaciones a la calculadora a partir de un operador ingresado.
 * 
 * @param calculadora puntero a la calculadora creada
 * @param operador operador que se quiere agregar
 * @param funcion funcion que resuelve el operador que se quiere agregar
 * @return true si el operador se agregó
 * @return false si el operador no se agregó
 */
bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion);

/**
 * @brief Calcula una operacion a partir de una cadena ingresada. Se pone en formato "a(operador)b"
 * 
 * @param calculadora puntero a la calculadora creada
 * @param cadena cadena a calcular
 * @return int 
 */
int Calcular(calculadora_t calculadora, char * cadena);

/*---  End of File  ---------------------------------------------------------------------------- */
#endif