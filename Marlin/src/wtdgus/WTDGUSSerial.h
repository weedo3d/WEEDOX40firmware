/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

/*
* DGus ´®¿Ú¶ÔÏó
*/


#ifndef WTDGUSSERIAL_H
#define WTDGUSSERIAL_H

class DGUSSerial
{
public:
	DGUSSerial();

	static void Init(unsigned long baud);
	static int read(void);
	static uint8_t available(void);
	static void write(const uint8_t c);
	static void write(const uint8_t* buffer, unsigned int size);

	static void payload_reset();
	static void payload_send();
	static void payload_append_byte(uint8_t data);
	static void payload_append_int(uint16_t data);
	static void payload_append_float(float data);
	static void payload_append_buffer(uint8_t* buffer);
	static void payload_append_string(char* str);

	static void SendString(uint16_t addr, const char* str);
	static void SendString(uint16_t addr, const char* str, uint8_t total_length);
	static void SendUnicodeString(uint16_t addr, const char* str, uint16_t str_len, uint16_t total_length);
	static void SendEmptyUnicodeString(uint16_t addr, uint16_t total_length);
	static void SendString(uint16_t addr, int data, int length);
	static void SendEmptyString(uint16_t addr, uint16_t length);
	static void SendLongString(uint16_t addr, const char* str, uint16_t length);
	static void SendLongString_P(uint16_t addr, const char* str, uint16_t length);
	static void SendInt16(uint16_t addr, int data);
	static void SendFloat(uint16_t addr, float data);
	static void SendBuffer(uint16_t addr, const uint8_t* buffer, uint8_t total_length);
    static void SendTemp(uint16_t addr, int16_t temp);
	static void SendFloatString(uint16_t addr, float data);

	static void JPG_Reset();	
	static void JPG_Send(const uint8_t* str, uint8_t str_len);
	static void JPG_Show();
	static bool JPG_Available();

	static void LoadScreen(uint8_t screenID);
	static void ResetScreen();

};

extern DGUSSerial dserial;

#endif