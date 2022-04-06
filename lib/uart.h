/* 
 * File:   uart.h
 * Author: dxstiny
 *
 * Created on 19. Oktober 2020, 08:37
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

void uart_init(void);
void uart_send(unsigned char byte);
void putch(unsigned char byte);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */
