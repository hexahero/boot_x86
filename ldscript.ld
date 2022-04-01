ENTRY(_btldr_start)

OUTPUT_FORMAT("binary")

SECTIONS {

	. = 0x7c00;
	
	.text :
	{
    	    *(.btldr)
	    *(.text)
	}
    
    	.rodata :
    	{
    		*(.rodata)
    	}

    	.data :
    	{
    		*(.data)
    	}

    	.bss :
    	{
    		*(.bss)
    	}

}