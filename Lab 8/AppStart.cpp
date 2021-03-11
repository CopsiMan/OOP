#include "Test.h"
#include "UI.h"

#include <crtdbg.h>

int main() {
	// testAll();
	{	
		UI ui{};
		ui.Start();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}