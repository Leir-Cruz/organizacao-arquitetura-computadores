//
// Created by Ricardo Jacobi on 18/11/22.
//

#include <stdint.h>

#define get_bit(word, index) (word >> index)&1
#define set_bit(word, index, val) ((word & ~(1 << index)) | ((val&1) << index))
#define get_field(word, index, mask) (word >> index)&mask
#define set_field(word, index, mask, value) (word & ~(mask << index)) | (value << index)

enum OPCODES {
    LUI = 0x37,		AUIPC = 0x17,		// atribui 20 msbits
    ILType = 0x03,						// Load type
    BType = 0x63,						// branch condicional
    JAL = 0x6F,		JALR = 0x67,		// jumps
    StoreType = 0x23,					// store
    ILAType = 0x13,						// logico-aritmeticas com imediato
    RegType = 0x33,
    ECALL = 0x73
};

enum FUNCT3 {
    BEQ3=0,		BNE3=01,	BLT3=04,	BGE3=05,	BLTU3=0x06, BGEU3=07,
    LB3=0,		LH3=01,		LW3=02,		LBU3=04,	LHU3=05,
    SB3=0,		SH3=01,		SW3=02,
    ADDSUB3=0,	SLL3=01,	SLT3=02,	SLTU3=03,
    XOR3=04,	SR3=05,		OR3=06,		AND3=07,
    ADDI3=0,	ORI3=06,	SLTI3=02,	XORI3=04,	ANDI3=07,
    SLTIU3=03,	SLLI3=01,	SRI3=05
};

enum FUNCT7 {
    ADD7=0,	SUB7=0x20,	SRA7=0x20,	SRL7=0, SRLI7=0x00,	SRAI7=0x20
};

enum FORMATS { RType, IType, SType, SBType, UType, UJType, NullFormat, NOPType };

extern char* iformat_str[8];

enum INSTRUCTIONS {
    I_add,	I_addi, I_and,  I_andi, I_auipc,
    I_beq,	I_bge,	I_bgeu, I_blt,  I_bltu,
    I_bne,  I_jal,	I_jalr, I_lb,	I_lbu,
    I_lw,   I_lh,   I_lhu,  I_lui,  I_sb,
    I_sh,   I_sw,   I_sll,  I_slt,  I_slli,
    I_srl,  I_sra,  I_sub,  I_slti, I_sltiu,
    I_xor,	I_or,	I_srli, I_srai,  I_sltu,
    I_ori, I_ecall, I_xori, I_nop
};


//
// identificacao dos registradores do banco do RV32I
//
enum REGISTERS {
    ZERO=0, RA=1,	SP=2,	GP=3,
    TP=4,	T0=5,	T1=6,	T2=7,
    S0=8,	S1=9,	A0=10,	A1=11,
    A2=12,	A3=13,	A4=14,	A5=15,
    A6=16,	A7=17,  S2=18,	S3=19,
    S4=20,	S5=21, 	S6=22,	S7=23,
    S8=24,	S9=25,  S10=26,	S11=27,
    T3=28,	T4=29,	T5=30,	T6=31
};
