//=============================================================================
// File Name : macro.h
//=============================================================================

// Bit opreation macros

#define	Macro_Erase_Area(dest, bits, position)		((dest) &= ~((bits) << (position)))
#define	Macro_Write_Area(dest, data, position)		((dest) |= ((data) << (position)))

#define	Macro_Set_Bit(dest, position)				((dest) |= (0x1 << (position)))
#define	Macro_Clear_Bit(dest, position)			((dest) &= ~(0x1 << (position)))
#define	Macro_Invert_Bit(dest, position)			((dest) ^= (0x1 << (position)))

#define	Macro_Check_Bit_Clear(dest, position)			(!(((dest) >> (position)) & 0x1))
#define	Macro_Check_Bit_Set(dest, position)			(((dest) >> (position)) & 0x1)

