#include "can.h"
#include "boilerplate.h"
#include <stddef.h>

class DummySpiDriver {
public:
	void select() {
	}

	void deselect() {
	}

	uint8_t read() {
		return 0;
	}

	void write(uint8_t value) {
		(void)value;
	}
};

int main() {
	DummySpiDriver spiDriver;
	Mcp2515CoreStatic<DummySpiDriver> mcpCore{spiDriver};

	mcpCore.reset();

	while(1)
		;
	return 0;
}
