#include "cpu/instr.h"


static void instr_execute_1op() {
	printf("lgdt...\n");
	operand_read(&opr_src);
	laddr_t mem_addr = opr_src.addr;
	printf("addr = 0x%x, value = 0x%x\n", opr_src.addr, opr_src.val);
	// printf("mem_addr = 0x%x\n", mem_addr);
	cpu.gdtr.limit = laddr_read(mem_addr, 2) & 0xffff;
	// printf("gdtr limit = 0x%x\n", cpu.gdtr.limit);
	cpu.gdtr.base =  laddr_read(mem_addr + 2, 4) & 0xffffffff;
	// printf("gdtr base = 0x%x\n", cpu.gdtr.base);
	if (data_size == 16)
		cpu.gdtr.base &= 0x00ffffff;
		// not sure if it's correct
	// printf("gdtr: limit = 0x%x, base = 0x%x\n", cpu.gdtr.limit, cpu.gdtr.base);	
}


make_instr_impl_1op(lgdt, rm, v)








