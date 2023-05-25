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



/** \brief Formato (struct) y Functions de la calculadora
 * 
*/

/* ---  Headers files inclusions   ------------------------------------------------------------- */

#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* ---  Macros definitions  -------------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */

typedef struct operacion_s * operacion_t;

typedef struct operacion_s {
    char operador;
    funciont_t funcion;
    operacion_t siguiente;
} * op;

/*---  Public Data Declaration  ---------------------------------------------------------------- */

struct calculadora_s {
    operacion_t operaciones;
};


/*---  Private Function Declaration  ----------------------------------------------------------- */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/*---  Public Function Declaration  ------------------------------------------------------------ */

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------- */

/*---  Private Function Implementation  -------------------------------------------------------- */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t result = NULL;
    if (calculadora != NULL){
        for (operacion_t actual = calculadora->operaciones; actual->siguiente != NULL; actual = actual->siguiente) {
            if (actual->operador == operador) {
                result = actual;
                break;
            }
        }
    }

    return result;
}

/*---  Public Function Implementation  --------------------------------------------------------- */

calculadora_t CrearCalculadora(void) {
    calculadora_t result = malloc(sizeof(struct calculadora_s));

    if (result != NULL) 
        memset(result, 0, sizeof(struct calculadora_s));

    return result;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {
    operacion_t operacion = NULL;

    if (!BuscarOperacion(calculadora,operador))
        operacion = malloc(sizeof(struct operacion_s));

    if (operacion) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operaciones;

        calculadora->operaciones = operacion;
    }
    
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int result = 0;

    for (int indice = 0; indice<strlen(cadena); indice++) {
        if (cadena[indice]< '0') {
            operador = cadena[indice];
            a = atoi(cadena);
            b = atoi(cadena + indice + 1);
            break;
        }
    }

    operacion_t operacion = BuscarOperacion (calculadora, operador);
    if (operacion) {
        result = operacion->funcion(a,b);
    }

    return result;
}

/*---  End of File  ---------------------------------------------------------------------------- */