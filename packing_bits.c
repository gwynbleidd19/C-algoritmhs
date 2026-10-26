#include <stdint.h>
#include <stdio.h>

void pack_u16(uint16_t value, uint8_t *high_byte, uint8_t *low_byte){
    *high_byte = (uint8_t)(value >> 8);
    *low_byte = (uint8_t)(value & 0xFF);
}

uint16_t unpack_u16(uint8_t h, uint8_t l){
    return ((uint16_t)h << 8) | l; 
}

int main(void){
    uint16_t value = 14747;
    
    uint8_t high_byte = 0;
    uint8_t low_byte = 0;
    pack_u16(value, &high_byte, &low_byte);
    
    printf("%d", high_byte);
    printf("%d\r\n", low_byte);

    uint16_t result = unpack_u16(high_byte, low_byte);
    printf("%d", result);
}