#include <stdio.h>
#include <stdint.h>

int main() {
    //here comes our parametres
    uint32_t RI, funct7, funct3, opcode, rd, rs1, rs2, shamt;
    int32_t imm32;

    //Let´s put some of the mask we will use the most
    uint32_t last_7_bits_mask = 0x7f;

    //read instruction and identify it using opcode
    scanf("%x", &RI);
    opcode = RI & last_7_bits_mask;

    //checks if it´s an R-type instruction
    if(opcode == 0x33 || opcode ==  0xb3) {

    //checks if it´s an I-type instruction
    } else if (opcode == 0x13) {

    //checks if it´s an S-type instruction
    } else if (opcode == 0x23) {

    }



    return 0;
}