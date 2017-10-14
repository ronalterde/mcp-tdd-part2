#include "can.h"
#include "boilerplate.h"
#include <stddef.h>

class DummySpiDriver : public SpiDriver {
public:
	void select() override {
	}

	void deselect() override {
	}

	uint8_t read() override {
		return 0;
	}

	void write(uint8_t value) override {
		(void)value;
	}
};

int main() {
	DummySpiDriver spiDriver;
	Mcp2515CoreDynamic mcpCore{spiDriver};

	mcpCore.reset();

	while(1)
		;
	return 0;
}
