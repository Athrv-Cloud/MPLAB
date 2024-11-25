#include <xc.h>

void SPI_Init(void) {
    TRISCbits.TRISC3 = 0; // SCK pin as output
    TRISCbits.TRISC4 = 1; // SDI pin as input
    TRISCbits.TRISC5 = 0; // SDO pin as output
    
    SSPSTAT = 0x40; // Slew rate control disabled
    SSPCON = 0x20; // SPI Master mode, clock = FOSC/4
}

void SPI_Write(unsigned char data) {
    SSPBUF = data; // Write data to the buffer
    while (!SSPSTATbits.BF); // Wait until transmission is complete
}

unsigned char SPI_Read(void) {
    SSPBUF = 0xFF; // Send dummy byte to read
    while (!SSPSTATbits.BF); // Wait until reception is complete
    return SSPBUF; // Return received data
}
void main(void) {
    SPI_Init(); // Initialize the SPI

    while (1) {
        SPI_Write(0x55); // Example write
        unsigned char received = SPI_Read(); // Example read
        // Add your logic here
        
        // For example, you could implement some delay or processing based on the received data
    }
}
