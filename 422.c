int LFSR () {
    static unsigned long ShiftRegister = 1;
    ShiftRegister = ((((ShiftRegister >> 7) 
        ^(ShiftRegister >> 5)
        ^(ShiftRegister >> 3)
        ^(ShiftRegister >> 2)
        ^(ShiftRegister >> 1)
        ^(ShiftRegister))
        & 0x00000001)
        << 31) 
        | (ShiftRegister >> 1);
    return ShiftRegister & 0x00000001; 
}