/*
 * SPI.h
 *
 * Created: 2/3/2020 5:35:54 PM
 *  Author: Eslam Yasser
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Config.h"
#include "Data_Types.h"

#define MISO PB6
#define MOSI PB5
#define SCK  PB7
#define SS   PB4

#define Rec_char '#'

typedef enum
{
	Freq_4,
	Freq_16,
	Freq_64,
	Freq_128,
	Freq_2,
	Freq_8,
	Freq_32,
	
}SCK_Freq;

typedef enum
{
	Mode_0,
	Mode_1,
	Mode_2,
	Mode_3
	
}SPI_Mode;

typedef enum
{
	MSB,
	LSB
	
}Data_Order;

typedef struct
{
	Data_Order DO ;
	SPI_Mode   SM ;
	SCK_Freq   frq;

}Spi_ConfigType;


/*
	Service Name	: SPI_Init_Master
	Description		: Initializes the SPI feature for master.	
	Parameters		: Pointer to configuration set.
	Return value	: None
*/
void  SPI_Init_Master	(const Spi_ConfigType*);

/*
	Service Name	: SPI_Init_Slave
	Description		: Initializes the SPI feature for slave.	
	Parameters		: Pointer to configuration set.
	Return value	: None
*/
void  SPI_Init_Slave	(const Spi_ConfigType*);

/*
	Service Name	: SPI_ReceiveByte
	Description		: Receive data byte.	
	Parameters		: None.
	Return value	: Byte Data
*/
uint8 SPI_ReceiveByte	(void);

/*
	Service Name	: SPI_SendByte
	Description		: Send Data Byte.	
	Parameters		: Byte Data .
	Return value	: None
*/
void  SPI_SendByte		(uint8);

/*
	Service Name	: SPI_SendString
	Description		: Send Array of Characters 'String' .	
	Parameters		: Pointer to string .
	Return value	: None
*/
void SPI_SendString		(uint8 *);

/*
	Service Name	: SPI_ReceiveString
	Description		: Receive Array of Characters 'String' depend on special character at the end of string .	
	Parameters		: Pointer to string .
	Return value	: None
*/
void SPI_ReceiveString	(uint8 *);

/*
	Service Name	: SPI_INT_Enable
	Description		: Enable Interrupt for SPI Driver	
	Parameters		: None
	Return value	: None
*/
void  SPI_INT_Enable	(void);

/*
	Service Name	: SPI_INT_Disable
	Description		: Disable Interrupt for SPI Driver	
	Parameters		: None
	Return value	: None
*/
void  SPI_INT_Disable	(void);

/*
	Service Name	: SPI_DeInit
	Description		: End the SPI feature.	
	Parameters		: None.
	Return value	: None
*/
void SPI_DeInit(void);


#endif /* SPI_H_ */