/**
* Copyright (C) 2021 Wiibooxtech Perron
*/


#include "../MarlinCore.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"

#define DGUS_PAYLOAD_LENGTH	64

#define DGUS_PAGE_SIZE 		(DGUS_PAYLOAD_LENGTH - 4)

#define LCD_SERIAL	MSerial3

uint8_t dgus_payload[DGUS_PAYLOAD_LENGTH];
uint8_t dgus_outbuffer[DGUS_PAYLOAD_LENGTH + 3];
uint8_t dpayload_length = 0;

uint32_t jpg_addr;
bool jpg_available;

void DGUSSerial::payload_reset()
{
	dpayload_length = 0;
	memset((char *)dgus_payload, 0, DGUS_PAYLOAD_LENGTH);
}

void DGUSSerial::payload_send()
{
	dgus_outbuffer[0] = DGUS_START_BYTE_1;
	dgus_outbuffer[1] = DGUS_START_BYTE_2;
	dgus_outbuffer[2] = dpayload_length;
	for (uint8_t i = 0; i < dpayload_length; i++)
		dgus_outbuffer[i + 3] = dgus_payload[i];
	write(dgus_outbuffer, dpayload_length + 3);
}

void DGUSSerial::payload_append_byte(uint8_t data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH)
	{
		dgus_payload[dpayload_length] = data;
		dpayload_length++;
	}
}

void DGUSSerial::payload_append_int(uint16_t data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH - 1)
	{
		dgus_payload[dpayload_length] = data >> 8;
		dgus_payload[dpayload_length + 1] = data & 0xFF;
		dpayload_length += 2;
	}
}

void DGUSSerial::payload_append_float(float data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH - 1)
	{
		uint8_t a[4], i;

		uint8_t *pdata = (uint8_t*)(&data);
		for (i = 0; i < 4; i++)
			a[i] = *pdata++;

		payload_append_byte(a[3]);
		payload_append_byte(a[2]);
		payload_append_byte(a[1]);
		payload_append_byte(a[0]);
	}
}

void DGUSSerial::payload_append_buffer(uint8_t* buffer)
{
	uint8_t* p = buffer;

	while (*p != 0 && dpayload_length < DGUS_PAYLOAD_LENGTH)
	{
		dgus_payload[dpayload_length] = *p;
		dpayload_length++;
		p++;
	}
}

void DGUSSerial::payload_append_string(char* str)
{
	payload_append_buffer((uint8_t*) str);
}

void DGUSSerial::SendString(uint16_t addr, const char* str)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	payload_append_string((char*)str);
	payload_send();
}

void DGUSSerial::SendString(uint16_t addr, const char* str, uint8_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (byte ch = *str++)
	{
		payload_append_byte(ch);
		count++;
	}
	while (count < total_length)
	{
		payload_append_byte(0x20);
		count++;
	}
	payload_send();
}

void DGUSSerial::SendUnicodeString(uint16_t addr, const char* str, uint16_t str_len, uint16_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	byte ch;
	while (count < str_len)
	{
		ch= *str++;
		payload_append_byte(ch);
		count++;
	}
	while (count < total_length)
	{
		payload_append_byte(0x00);
		payload_append_byte(0x20);
		count+=2;
	}
	payload_send();
}

void DGUSSerial::SendEmptyUnicodeString(uint16_t addr, uint16_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (count < total_length)
	{
		payload_append_byte(0x00);
		payload_append_byte(0x20);
		count+=2;
	}
	payload_send();
}

void DGUSSerial::SendString(uint16_t addr, int data, int length)
{
	if (length == 5)
	{
		char b[6];
		sprintf_P(b, PSTR("%-5d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[5] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 4)
	{
		char b[5];
		sprintf_P(b, PSTR("%-4d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[4] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 3)
	{
		char b[4];
		memset(b, 0x20, 4);
		sprintf_P(b, PSTR("%-3d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[3] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 2)
	{
		char b[3];
		sprintf_P(b, PSTR("%-2d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[2] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else
	{
		char b[2];
		sprintf_P(b, PSTR("%1d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[1] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	
}

void DGUSSerial::SendEmptyString(uint16_t addr, uint16_t length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (count < length)
	{
		payload_append_byte(0x20);
		count ++;
	}
	payload_send();
}

void DGUSSerial::SendLongString(uint16_t addr, const char* str, uint16_t length)
{
	uint16_t totalcount = 0;
	uint16_t pagecount = 0;
	uint16_t bufferlen = strlen(str);
	uint16_t startaddr = addr;
	char tempdata[DGUS_PAGE_SIZE];

	while (totalcount < length)
	{
		if (totalcount < bufferlen)
			tempdata[pagecount] = str[totalcount];
		else
			tempdata[pagecount] = 0x00;

		totalcount++;
		pagecount++;

		if (pagecount >= DGUS_PAGE_SIZE || totalcount >= length)
		{
			SendString(startaddr, tempdata, pagecount);
			startaddr += (DGUS_PAGE_SIZE >> 1);
			pagecount = 0;
		}
	}
}

void DGUSSerial::SendLongString_P(uint16_t addr, const char* str, uint16_t length)
{
	uint16_t totalcount = 0;
	uint16_t pagecount = 0;
	uint16_t bufferlen = strlen(str);
	uint16_t startaddr = addr;
	char tempdata[DGUS_PAGE_SIZE];

	while (totalcount < length)
	{
		if (totalcount < bufferlen)
			tempdata[pagecount] = pgm_read_byte(str++);
		else
			tempdata[pagecount] = 0x00;

		totalcount++;
		pagecount++;

		if (pagecount >= DGUS_PAGE_SIZE || totalcount >= length)
		{
			SendString(startaddr, tempdata, pagecount);
			startaddr += (DGUS_PAGE_SIZE >> 1);
			pagecount = 0;
		}
	}
}

void DGUSSerial::SendInt16(uint16_t addr, int data)
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_WriteVAR);
	dserial.payload_append_int(addr);
	dserial.payload_append_int(data);
	dserial.payload_send();
}

void DGUSSerial::SendFloat(uint16_t addr, float data)
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_WriteVAR);
	dserial.payload_append_int(addr);
	dserial.payload_append_float(data);
	dserial.payload_send();
}

void DGUSSerial::SendFloatString(uint16_t addr, float data)
{
	char a[8];
	ZERO(a);
	dtostrf(data, 3, 2, a);
	dserial.SendString(addr, a, 8);
    
}

DGUSSerial::DGUSSerial()
{

}

void DGUSSerial::Init(unsigned long baud)
{
	jpg_available = false;
#ifndef DMA_RX_SUPPORT
	LCD_SERIAL.begin(DGUS_BAUDRATE);
    uint32_t serial_connect_timeout = millis() + 1000UL;
    while (!LCD_SERIAL && PENDING(millis(), serial_connect_timeout)) { /*nada*/ }
#endif
}


void DGUSSerial::write(const uint8_t c)
{
	LCD_SERIAL.write(c);
}

void DGUSSerial::write(const uint8_t* buffer, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		write(buffer[i]);
}

int DGUSSerial::read()
{
	return LCD_SERIAL.read();
}

uint8_t DGUSSerial::available()
{
	return LCD_SERIAL.available();
}

void DGUSSerial::LoadScreen(uint8_t screenID)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(DGUS_SYS_PIC_Set);
	payload_append_byte(0x5A);
	payload_append_byte(0x01);
	payload_append_byte(0x00);
	payload_append_byte(screenID);
	payload_send();
}

void DGUSSerial::ResetScreen()
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(DGUS_SYS_System_Reset);
	payload_append_byte(0x55);
	payload_append_byte(0xAA);
	payload_append_byte(0x5A);
	payload_append_byte(0xA5);
	payload_send();
}


void DGUSSerial::SendBuffer(uint16_t addr, const uint8_t* buffer, uint8_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (count < total_length)
	{
		byte ch = *buffer++;
		payload_append_byte(ch);
		count++;
	}
	payload_send();
}

void DGUSSerial::JPG_Reset()
{
	jpg_addr = DGUS_JPG_CACHE_ADDR;
	jpg_available = false;
}

void DGUSSerial::JPG_Send(const uint8_t* str, uint8_t str_len)
{
	SendBuffer(jpg_addr, str, str_len);
	jpg_addr += str_len / 2;
}

void DGUSSerial::JPG_Show()
{
	uint8_t param[] = { 0x5a, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00 };

	param[2] = DGUS_JPG_CACHE_ADDR >> 8;
	param[3] = DGUS_JPG_CACHE_ADDR & 0xFF;
	param[4] = DGUS_JPG_X >> 8;
	param[5] = DGUS_JPG_X & 0xFF;
	param[6] = DGUS_JPG_Y >> 8;
	param[7] = DGUS_JPG_Y & 0xFF;

	SendBuffer(0xA6, param, 8);

	jpg_available = true;
}

bool DGUSSerial::JPG_Available()
{
	return jpg_available;
}

void DGUSSerial::SendTemp(uint16_t addr, int16_t temp)
{
    char b[10] = {0};
	sprintf_P(b, TEMP_STRING, temp);
	dserial.SendString(addr, b, 6);
}