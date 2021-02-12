/*
 * File:   main.c
 * Author: 19179453
 *
 * Created on 4 de Fevereiro de 2021, 16:46
 */


#include <xc.h>
#include "config.h"

void semaforo_init (void)
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD1 = 1;
    
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 0;
}

void verde (int x)
{
    PORTDbits.RD5 = x;
}

int ret_verde (void)
{
    return (PORTDbits.RD5);
}

void amarelo (int x)
{
    PORTDbits.RD6 = x;
}

void vermelho (int x)
{
    PORTDbits.RD7 = x;
}

int btPedestre (void)
{
    return (PORTDbits.RD1);
}

void verde_ped (int x)
{
    PORTDbits.RD3 = x;
}

void verm_pedestre (int x)
{
    PORTDbits.RD2 = x;
}

void delay (int t)
{
    while(t)
    {
        --t;
        __delay_ms(1);
    }
}

int ret_verm (void)
{
    return (PORTDbits.RD7);
}

void main(void) 

{
    semaforo_init();
    while(1)
    {
        if (btPedestre()==1)
        {
            delay(2000);
            verde(0);
            amarelo(1);
            delay(1000);
            amarelo(0);
            vermelho(1);
            verde_ped(1);
            verm_pedestre(0);
            delay(5000);
            verde_ped(0);
        }
        else 
        {
            verde(1);
            verm_pedestre(1);
            amarelo(0);
            vermelho(0);
        }
    }
}
