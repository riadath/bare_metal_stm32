ENTRY(Reset_Handler)
MEMORY
{
	FLASH(RX): ORIGIN = 0x08000000, LENGTH = 512K
	SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 128K /* combined both SRAM1 and SRAM2 */
}
SECTIONS
{
	.text :
	{	_stext = .;
		*(.isr_vector)
		*(.text) 
		*(.rodata)
		. = ALIGN(4);
		_etext = .;
	}> FLASH AT> FLASH 
	_la_data = LOADADDR(.data);
	.data :
	{
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	}>SRAM AT> FLASH
	.bss :
	{
		_sbss = .;
		*(.bss)
		_ebss = .; 
	}>SRAM
}
