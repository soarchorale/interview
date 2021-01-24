#include "complexAdd.h"

#include <iostream>
#include <thread>

int main() {
	ComplexAdd* complex_add = new ComplexAdd();

	std::thread A(&ComplexAdd::ProducerInt, complex_add);
	std::thread B(&ComplexAdd::ProducerDouble, complex_add);
	std::thread C(&ComplexAdd::Comsumer, complex_add);
	std::thread D(&ComplexAdd::Print, complex_add);

	A.join();
	B.join();
	C.join();
	D.join();

	delete complex_add;
	return 0;
}
