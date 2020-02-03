/*
 * SPI.c
 *
 * Created: 2/3/2020 5:36:10 PM
 *  Author: Eslam Yasser
 */ 

#include "SPI.h"

void  SPI_Init_Master	(const Spi_ConfigType* ConfigPtr)
{
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK) ;					// PIN Direction 
	
	SPCR  = (SPCR & 0xDF) | (ConfigPtr->DO << 5) ;				// Data Order
	SPCR  = (SPCR & 0xF3) | (ConfigPtr->SM << 2) ;				// SPI Mode
	
	SPCR  = (SPCR & 0xFC) | (ConfigPtr->frq & 0x03) ;			// Clock 
	SPSR  = (SPSR & 0xFE) | (ConfigPtr->frq & 0x04 >> 2);
	
	SPCR |= (1<<SPE) | (1<<MSTR);								// Set as Master and Enable SPI
}

void  SPI_Init_Slave	(const Spi_ConfigType* ConfigPtr)
{
	DDRB |= (1<<MISO);
	
	SPCR  = (SPCR & 0xDF) | (ConfigPtr->DO << 5) ;				// Data Order
	SPCR  = (SPCR & 0xF3) | (ConfigPtr->SM << 2) ;				// SPI Mode
	
	SPCR |= (1<<SPE);											// Enable SPI
}

uint8 SPI_ReceiveByte	(void)
{
	while ( ! (SPSR & (1<<SPIF)) );
		return SPDR ;
}

void  SPI_SendByte		(uint8 data)
{
	SPDR = data ;
	while ( ! (SPSR & (1<<SPIF)) );
}

void SPI_SendString(uint8 *str)
{
	while(*str)
	{
		SPI_SendByte(*str);
		str++;
	}
	SPI_SendByte(Rec_char);
}

void SPI_ReceiveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = SPI_ReceiveByte();
	while(str[i] != Rec_char )
	{
		i++;
		str[i] = SPI_ReceiveByte();
	}
	str[i] = '\0';
}

void  SPI_INT_Enable	(void)
{
	SPCR |= (1<<SPIE);
	SREG |= (1<<7);
}

void  SPI_INT_Disable	(void)
{
	SPCR &= ~(1<<SPIE);
	SREG &= ~(1<<7);
}

void SPI_DeInit			(void)
{
	SPCR &= ~(1<<SPE);
}
