#include <stdio.h>
#include <stdint.h>

int main() {
    //here comes our parametres
    uint32_t RI, funct7, funct3, opcode, rd, rs1, rs2, shamt;
    int32_t imm32;

    //Lets put some of the mask we will use the most
    uint32_t last_7_bits_mask = 0x7f;

    //read instruction and identify it using opcode
    scanf("%x", &RI);
    printf("%x", (RI & last_7_bits_mask));



    return 0;
}