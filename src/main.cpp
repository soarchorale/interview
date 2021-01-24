#include "complexAdd.h"

#include <iostream>
#include <thread>
#include <chrono>

void RunTask(const std::string& task_name) {

}

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

	// std::thread producerB(&ComplexAdd::GenRandomDouble, complex_add);
	//std::thread addC(&ComplexAdd::Add, complex_add);
	//std::thread printD(&ComplexAdd::Print, complex_add);
	delete complex_add;
	return 0;
}