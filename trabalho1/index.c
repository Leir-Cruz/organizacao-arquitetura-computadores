#include <stdio.h>
#include <stdint.h>

int main() {
    //here comes our parametres
    uint32_t RI, funct7, funct3, opcode, rd, rs1, rs2, shamt;
    int32_t imm32;

    //Let´s put some of the mask we will use the most
    uint32_t twelve_bits_mask = 0xfff; //111 1111 1111
    uint32_t seven_bits_mask = 0x7f; //0111 1111
    uint32_t five_bits_mask = 0x1f; //0001 1111
    uint32_t three_bits_mask = 0x7; //0111

    //read instruction and identify it using opcode
    scanf("%x", &RI);
    opcode = RI & seven_bits_mask;

    //checks if it´s an R-type instruction
    if(opcode == 0x33) {

        funct7 = RI >> 25 & seven_bits_mask;
        rs2 = RI >> 20 & five_bits_mask;
        rs1 = RI >> 15 & three_bits_mask;
        funct3 = RI >> 12 & three_bits_mask;
        rd = RI >> 7 & seven_bits_mask;

        printf("opcode: %x\n", opcode);
        printf("funct7: %x\n",funct7 );
        printf("rs2: %x\n", rs2);
        printf("rs1: %x\n", rs1);
        printf("funct3: %x\n", funct3);
        printf("rd: %x\n", rd);

    //checks if it´s an I-type instruction
    } else if (opcode == 0x13) {
        imm32 = RI >> 20 & twelve_bits_mask;
        rs1 = RI >> 15 & five_bits_mask;
        funct3 = RI >> 10 & three_bits_mask;
        rd = RI >> 7 & seven_bits_mask;

        printf("opcode: %x\n", opcode);
        printf("imm: %x\n",imm32 );
        printf("rs1: %x\n", rs1);
        printf("funct3: %x\n", funct3);
        printf("rd: %x\n", rd);

    //checks if it´s an S-type instruction
    } else if (opcode == 0x23) {
        imm32 = ( RI >> 25  & seven_bits_mask ) + ( RI >> 7 & five_bits_mask );
        rs2 = RI >> 20 & five_bits_mask;
        rs1 = RI >> 15 & five_bits_mask;
        funct3 = RI >> 12  & three_bits_mask;

        printf("opcode: %x\n", opcode);
        printf("imm: %x\n",imm32 );
        printf("rs2: %x\n", rs2);
        printf("rs1: %x\n", rs1);
        printf("funct3: %x\n", funct3);
    }



    return 0;
}