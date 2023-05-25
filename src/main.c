/*
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



/** \brief Calculadora con operaciones basicas de suma, resta, multiplicacion y division.
 * @note Se realiza toda la funcionalidad del programa a traves de funciones de callback.
 * 
*/

/* ---  Headers files inclusions   ------------------------------------------------------------- */

#include "calculadora.h"
#include <stdio.h>

/* ---  Macros definitions  -------------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Private Function Declaration  ----------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------- */

/*---  Private Function Implementation  -------------------------------------------------------- */

// Suma de enteros, a y b
int suma(int a, int b) {
    return a + b;
}

// Resta de enteros, a y b
int resta(int a, int b) {
    return a - b;
}

// Multiplicacion de enteros, a y b
int multiplicacion(int a, int b) {
    return a * b;
}

// Division de enteros, a y b
int division(int a, int b) {
    return a / b;
}

/*---  Public Function Implementation  --------------------------------------------------------- */
int main (void) {
    int resultado;

    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '+',suma);
    AgregarOperacion(calculadora, '-',resta);
    AgregarOperacion(calculadora, '*',multiplicacion);
    AgregarOperacion(calculadora, '/',division);

    resultado = Calcular(calculadora, "4+4");
    printf("Resultado %i\r\n", resultado);
}

/*---  End of File  ---------------------------------------------------------------------------- */