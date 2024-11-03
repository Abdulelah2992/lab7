#include <stdio.h>
#include <stdlib.h>

void convBit2Hex( char *bitFile, char *hexFile) {
    FILE *bFile = fopen(bitFile, "r");
    FILE *hFile = fopen(hexFile, "w");
    if (bFile==NULL || hFile==NULL) {
        printf("Error: could not open file.\n");
        exit(1);}
    int bitCount = 0;
    unsigned char byte = 0;
    char bit;

    while ((bit = fgetc(bFile)) != EOF) {
        if (bit == '0' || bit == '1') {
            byte = (byte >> 1) | ((bit - '0') << 7);
            bitCount++;
            if (bitCount == 8) {
                fprintf(hFile, "%02X\n", byte);
                bitCount = 0;
                byte = 0;}}}
    if (bitCount > 0) {
        byte >>= (8 - bitCount);
        fprintf(hFile, "%02X\n", byte);}

    fclose(bFile);
    fclose(hFile);}

int main() {
    convBit2Hex("/home/it/lab7/lab7/task3/bitstream.bit", "/home/it/lab7/lab7/task3/bitstream.hex");
    return 0;
}

