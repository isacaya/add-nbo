#include <stdio.h>
#include <stdint.h>

void calc(uint32_t num1, uint32_t num2)
{   
    uint32_t a1 = (num1 & 0xff000000) >> 24;
    uint32_t a2 = (num1 & 0x00ff0000) >> 8;
    uint32_t a3 = (num1 & 0x0000ff00) << 8;
    uint32_t a4 = (num1 & 0x000000ff) << 24;

    num1 = a1 | a2 | a3 | a4;

    uint32_t b1 = (num2 & 0xff000000) >> 24;
    uint32_t b2 = (num2 & 0x00ff0000) >> 8;
    uint32_t b3 = (num2 & 0x0000ff00) << 8;
    uint32_t b4 = (num2 & 0x000000ff) << 24;

    num2 = b1 | b2 | b3 | b4;
    
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
}

int main(int argc, char* argv[]) {
    uint32_t* num1, num2;

    FILE* pFile1 = fopen(argv[1], "rb");
    FILE* pFile2 = fopen(argv[2], "rb");

    fread(&num1, 4, 1, pFile1);
    fread(&num2, 4, 1, pFile2);

    calc(num1, num2);

    fclose(pFile1);
    fclose(pFile2);

    return 0;
}