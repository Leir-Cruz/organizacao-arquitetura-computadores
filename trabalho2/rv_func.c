//
// Created by Ricardo Jacobi on 18/11/22.
//

#include "globals.h"
#include "riscv.h"
#include "memoria.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//
// Initial values for registers
//

void init() {
    pc = 0;
    ri = 0;
    stop_prg = 0;
    sp = 0x3ffc;
    gp = 0x1800;
    build_dic();
}

void fetch() {
    ri = lw(pc, 0);
    pc = pc + 4;
}

void decode() {
    int32_t tmp;

    opcode = ri & 0x7F;
    rs2 = (ri >> 20) & 0x1F;
    rs1 = (ri >> 15) & 0x1F;
    rd = (ri >> 7) & 0x1F;
    shamt = (ri >> 20) & 0x1F;
    funct3 = (ri >> 12) & 0x7;
    funct7 = (ri >> 25);
    imm12_i = ((int32_t) ri) >> 20;
    tmp = get_field(ri, 7, 0x1f);
    imm12_s = set_field(imm12_i, 0, 0x1f, tmp);
    imm13 = imm12_s;
    imm13 = set_bit(imm13, 11, imm12_s & 1);
    imm13 = imm13 & ~1;
    imm20_u = ri & (~0xFFF);
// mais aborrecido...
    imm21 = (int32_t) ri >> 11;            // estende sinal
    tmp = get_field(ri, 12, 0xFF);        // le campo 19:12
    imm21 = set_field(imm21, 12, 0xFF, tmp);    // escreve campo em imm21
    tmp = get_bit(ri, 20);                // le o bit 11 em ri(20)
    imm21 = set_bit(imm21, 11, tmp);            // posiciona bit 11
    tmp = get_field(ri, 21, 0x3FF);
    imm21 = set_field(imm21, 1, 0x3FF, tmp);
    imm21 = imm21 & ~1;                    // zero bit 0
    ins_code = get_instr_code(opcode, funct3, funct7);
    imm32 = get_imm32(get_i_format(opcode, funct3, funct7));
}

int load_mem(const char *fn, int start) {
    FILE *fptr;
    int *m_ptr = mem + (start >> 2);
    int size = 0;

    fptr = fopen(fn, "rb");
    if (!fptr) {
        printf("Arquivo nao encontrado!");
        return -1;
    } else {
        while (!feof(fptr)) {
            fread(m_ptr, 4, 1, fptr);
            m_ptr++;
            size++;
        }
        fclose(fptr);
    }
    return size;
}

int32_t get_imm32(enum FORMATS iformat) {
    switch (iformat) {
        case RType:     return 0;
        case IType:     return imm12_i;
        case SType:     return imm12_i;
        case SBType:    return imm13;
        case UType:     return imm20_u;
        case UJType:    return imm21;
        default:        return 0;
    }
}

enum FORMATS get_i_format(uint32_t opcode, uint32_t func3, uint32_t func7) {
    switch (opcode) {
        case 0x33 :
            return RType;
        case 0x03:
        case 0x13:
        case 0x67:
        case 0x73:
            return IType;
        case 0x23 :
            return SType;
        case 0x63 :
            return SBType;
        case 0x37 :
            return UType;
        case 0x6F:
        case 0x17 :
            return UJType;
        case 0x00:
            if (func3 == 0 && func7 == 0)
                return NOPType;
            else
                return NullFormat;
        default:
            printf("Undefined Format");
            return NullFormat;
    }
}