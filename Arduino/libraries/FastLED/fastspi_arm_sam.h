#ifndef __INC_FASTSPI_ARM_SAM_H
#define __INC_FASTSPI_ARM_SAM_H

template <uint8_t _DATA_PIN, uint8_t _CLOCK_PIN, uint8_t _SPI_CLOCK_DIVIDER>
class SAMHardwareSPIOutput {

public:
	SAMHardwareSPIOutput() { /* TODO */ }
	SAMHArdwareSPIOutput(Selectable *pSelect) { /* TODO */ }

	// set the object representing the selectable
	void setSelect(Selectable *pSelect) { /* TODO */ }

	// initialize the SPI subssytem
	void init() { /* TODO */ }

	// latch the CS select
	void select() { /* TODO */ }

	// release the CS select 
	void release() { /* TODO */ }

	// wait until all queued up data has been written
	void waitFully();
	
	// write a byte out via SPI (returns immediately on writing register)
	void writeByte(uint8_t b) { /* TODO */ }
	// write a word out via SPI (returns immediately on writing register)
	void writeWord(uint16_t w) { /* TODO */ }

	// A raw set of writing byte values, assumes setup/init/waiting done elsewhere
	void writeBytesValueRaw(uint8_t value, int len) { /* TODO */ }	

	// A full cycle of writing a value for len bytes, including select, release, and waiting
	void writeBytesValue(uint8_t value, int len) { /* TODO */ }

	// A full cycle of writing a raw block of data out, including select, release, and waiting
	void writeBytes(uint8_t *data, int len) { /* TODO */ }

	// write a single bit out, which bit from the passed in byte is determined by template parameter
	template <uint8_t BIT> inline static void writeBit(uint8_t b) { /* TODO */ }

	template <uint8_t SKIP, class D, EOrder RGB_ORDER> void writeBytes3(register uint8_t *data, int len, register uint8_t scale) { /* TODO*/ }

	// template instantiations for writeBytes 3
	template <uint8_t SKIP, EOrder RGB_ORDER> void writeBytes3(register uint8_t *data, int len, register uint8_t scale) { 
		writeBytes3<SKIP, DATA_NOP, RGB_ORDER>(data, len, scale); 
	}
	template <class D, EOrder RGB_ORDER> void writeBytes3(register uint8_t *data, int len, register uint8_t scale) { 
		writeBytes3<0, D, RGB_ORDER>(data, len, scale); 
	}
	template <EOrder RGB_ORDER> void writeBytes3(register uint8_t *data, int len, register uint8_t scale) { 
		writeBytes3<0, DATA_NOP, RGB_ORDER>(data, len, scale); 
	}
	void writeBytes3(register uint8_t *data, int len, register uint8_t scale) { 
		writeBytes3<0, DATA_NOP, RGB>(data, len, scale); 

};

#endif