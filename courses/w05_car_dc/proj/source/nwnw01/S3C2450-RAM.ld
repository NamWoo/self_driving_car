/*---------------------------------------------------------------------------*/
/*- NAME: Test firmware Linker Script File for RAM Workspace                 */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*- File source          : GCC_RAM.ld                                        */
/*- Object               : Linker Script File for RAM Workspace              */
/*- Modified             : sungho,Park                                       */
/*- Modified			 : Jurngyu,Park(2008.04.23 ~ )						 */
/*- Modified			 : Seonghye,Son(2015.07.10 ~ )						 */
/*---------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
	CODE (rw)    	: ORIGIN  = 0x30000000, LENGTH = 0x04000000
	_ISR_START(rw) 	: ORIGIN  = 0x33ffff00, LENGTH = 0x00000100
}

SECTIONS
{
  .text  : 
  {
  	*s3c2450_startup.o(.text)
    *(.text)     
    . = ALIGN(4);

  } >CODE
  
  .rodata :
  {
    rodata_start_addr = .;

    *(.rodata)
    *(.rodata.*)
    . = ALIGN(4);
       
     rodata_end_addr = .; 
  } 

  .data :
  {
    data_start_addr = .;
    __DATA_START__ = .;
    
    *(.data)
    *(.data.*)
    . = ALIGN(8);

    data_end_addr = .;
    __DATA_END__ = .; 
    
  } 
  
  .bss :
  {
    bss_start_addr = .;
    __BSS_START__ = .;	    

    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(8);
    bss_end_addr = .;
    __BSS_END__ = .;
    
  } 
  end = .;
  PROVIDE(end = .);
  
  .int_vec  : 
  {
      s3c2450_startup.o(int_vect)
  } >_ISR_START 

}
