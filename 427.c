#define mask 0x000000AF
static unsigned long ShiftRegister = 1;
void seed_LFSR (unsigned long seed){
	if (seed == 0)
		seed = 1;
	ShiftRegister = seed;
}
int modifier_LFSR (void){
	if (ShiftRegister & 0x0000001){
		ShiftRegister = ((ShiftRegister ^ mask) >> 1) | 0x8000000;
		return 1;
	}
	else{
		ShiftRegister >>= 1;
		return 0;
	}
}
