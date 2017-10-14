#pragma once

#include <stdint.h>

class SpiDriver {
public:
	virtual ~SpiDriver() {}
	virtual void select() = 0;
	virtual void deselect() = 0;
	virtual uint8_t read() = 0;
	virtual void write(uint8_t value) = 0;
};

class Mcp2515CoreDynamic {
public:
	Mcp2515CoreDynamic(SpiDriver& spiDriver) :
		spiDriver(spiDriver) {
	}

	void reset() {
		spiDriver.select();
		spiDriver.write(0xC0);
		spiDriver.deselect();
	}

private:
	SpiDriver& spiDriver;
};

template <typename SpiDriver>
class Mcp2515CoreStatic {
public:
	Mcp2515CoreStatic(SpiDriver& spiDriver) :
		spiDriver(spiDriver) {
	}

	void reset() {
		spiDriver.select();
		spiDriver.write(0xC0);
		spiDriver.deselect();
	}

private:
	SpiDriver& spiDriver;
};
