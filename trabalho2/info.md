# Info

### Goal

Build a Simulator of RiscV architecture in c programming language.
- Basic functions of search and decode are given.
- Build execute function of the following functions:

![img.png](img.png)

### Flashback...

- opcode: identify instruction (primarily);
- rs1: first register we are working with;
- rs2: second register we are working with;
- rd: destiny register, where we store the result of instruction;
- funct3: helps identify instruction;
- funct7: also helps identify instruction.

### In C programming language;

- Our memory will be simulated by an int_32 array, simulating ours registers in the processor.
- We will try to identify the instruction via opcode;
- If opcode is not enough to identify given instruction, we will use funct3;
- Else if opcode and funct3 aren´t enough, then we will use funct7;

#### Reading Data
- data in the files should be read for the memory in the simulator. The function _load_mem()_ do this task.
- memory is molded as an integer arrangement of 32 kbytes:
  - #define MEM_SIZE 4096
  - int32_t mem[MEM_SIZE]

#### Memory access
- int32_t lb(uint32_t address, int32_t kte);
- int32_t lw(uint32_t address, int32_t kte);
- int32_t lbu(uint32_t address, int32_t kte);
- void sb(uint32_t address, int32_t kte, int8_t dado);
- void sw(uint32_t address, int32_t kte, int32_t dado);

- All reading operations return an 32-bits integer that will be stored in the simulator as a register. It returns an integer as a bity read in the less significant position.

#### Registers
- The registers _pc, sp, gp_ and _ri_ and the instruction fields(_opcode, rs1, rs2, rd, shamt, funct3, funct7_) will be defined as global variables. _pc_ and _ri_ are unsigned int and store memory address and instructions, as _sp_ and _gp_.
- initial value of registers:
  - c = 0x00000000
  - ri = 0x00000000
  - sp = 0x00003ffc
  - gp = 0x00001800

#### Fetch function
Search the instruction that will be executed from the memory and updates the _pc_

#### Decode function
Extracts all fields from the given instruction

#### Execute function
Executes the instruction read by fetch and decode function

#### Step function
- Executes instruction from RiscV
- _step() => fecth(), decode(), execute()_

#### Run function
Executes program until it finds a system call for the ending or until _pc_ reaches the limit of 2K words.