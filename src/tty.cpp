#include "def.h"

void obuff(unsigned short port, unsigned char data);
void move_cursor(unsigned short pos);
void move_cursor(unsigned short pos);
void new_line();
void print_term(const char* msg, unsigned short clr, bool nl);
void print_term(int msg, unsigned short clr, bool nl);
char* itoa(int value, char* str, int base);

short* currCharAddr = (short*)0xb8000;
unsigned short carryCurrOffset;
unsigned short lastStrLen;
unsigned short currLineLen;

void obuff(unsigned short port, unsigned char data) { 
	
	asm ( "outw %w0, %w1"::"a"(data), "Nd"(port) ); 
}

void move_cursor(unsigned short pos) {
	
	carryCurrOffset += pos;

    obuff(FBUFF_COMMAND_PORT,	FBUFF_HIGH_BYTE_COMMAND);
    obuff(FBUFF_DATA_PORT,		((carryCurrOffset >> 8) & 0x00ff));
    obuff(FBUFF_COMMAND_PORT, 	FBUFF_LOW_BYTE_COMMAND);
    obuff(FBUFF_DATA_PORT,    	carryCurrOffset & 0x00ff);
	
}

void new_line() {

	if (currLineLen <= 80) {

		move_cursor(lastStrLen);
		move_cursor(80 - currLineLen); 
		currLineLen = 0;

	}
	else {

		move_cursor(lastStrLen);
		move_cursor((80 - currLineLen) + (currLineLen - 80) + (80 - (currLineLen - 80))); 
		currLineLen = 0;

	}

}

void print_term(const char* msg, unsigned short clr, bool nl) {

	unsigned short currStrLen;

	for (currStrLen = 0; msg[currStrLen] != '\0' ; ++currStrLen) { 
		
		currCharAddr[currStrLen + carryCurrOffset] = clr | msg[currStrLen];
	}

	currLineLen += currStrLen;
	lastStrLen = currStrLen;

	if (nl) new_line();  
	else move_cursor(currStrLen);
	   
}

void print_term(int msg, unsigned short clr, bool nl) {

	char* str = nullptr; 
	itoa(msg, str, 10);

	unsigned short currStrLen;

	for (currStrLen = 0; str[currStrLen] != '\0' ; ++currStrLen) { 
		
		currCharAddr[currStrLen + carryCurrOffset] = clr | str[currStrLen];
	}

	currLineLen += currStrLen;
	lastStrLen = currStrLen;

	if (nl) new_line();  
	else move_cursor(currStrLen);
	
}

char* itoa(int value, char* str, int base) {

    char * rc;
    char * ptr;
    char * low;

    if ( base < 2 || base > 36 ) {
        *str = '\0';
        return str;
    }

    rc = ptr = str;

    if ( value < 0 && base == 10 ) { *ptr++ = '-'; }

    low = ptr;

    do {

        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;

    } 
	while ( value );

    *ptr-- = '\0';

    while ( low < ptr ) {

        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;

    }

    return rc;
}

void clr_screen();
void move_carry();