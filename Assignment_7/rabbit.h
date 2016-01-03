#include <stddef.h>
#include <stdlib.h>

#ifndef RABBIT_H_   /* Include guard */
#define RABBIT_H_


/* Type declarations of 32-bit and 8-bit unsigned integers */
typedef unsigned int uint32;
typedef unsigned char byte;

/* Structure to store the instance data (internal state) */
typedef struct t_instance {
    uint32 x[8];
    uint32 c[8];
    uint32 carry;
} t_instance;

#define KEY_LEN 16

void key_setup(t_instance *p_instance, const byte *p_key);

void cipher(t_instance *p_instance, const byte *p_src, byte *p_dest, size_t data_size);

uint32 _rotl(uint32 x, int rot);


/* Square a 32-bit number to obtain the 64-bit result and return
the upper 32-bit XOR the lower 32-bit */
uint32 g_func(uint32 x);

/* Calculate the next internal state */
void next_state(t_instance *p_instance);

/* key_setup */
void key_setup(t_instance *p_instance, const byte *p_key) ;

/* Encrypt or decrypt a block of data */
void cipher(t_instance *p_instance, const byte *p_src, byte *p_dest,size_t data_size) ;

/*check key and init the key for encryption and descryption*/
void check_init_key(char* argument, byte *key);

#endif
