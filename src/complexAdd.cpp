#include "complexAdd.h"

void ComplexAdd::GenRandomInt() {
	st_a_.a = rand() % 100;
}

void ComplexAdd::GenRandomDouble() {
	sum_b_ = 0.0;
	for (size_t i = 0;
		i < sizeof(st_b_.data) / sizeof(double); i++) {
		st_b_.data[i] = rand() / double(RAND_MAX);
		sum_b_ += st_b_.data[i];
	}
	// st_b_buffer_.push_back(st_b_);
}

void ComplexAdd::Add() {
	// std::lock_guard<std::mutex> lk(mtx_lock_);
	if (st_a_.a % 2) {
		sum_b_all_ += sum_b_;
	}
	else {
		sum_b_all_ -= sum_b_;
	}
}

void ComplexAdd::ProducerInt() {
	while (true) {
		//std::lock_guard<std::mutex> lk(mtx_lock_);
		GenRandomInt();
	}
}

void ComplexAdd::ProducerDouble() {
	while (true) {
		std::unique_lock<std::mutex> lk(mtx_lock_);
		if (lk.owns_lock()) {
			GenRandomDouble();
			gen_cond_.notify_one();
		}
	}
}

void ComplexAdd::Comsumer() {
	while (true) {
		std::unique_lock<std::mutex> lk(mtx_lock_);
		gen_cond_.wait(lk);
		Add();
	}
}

void ComplexAdd::Print() {
	while(true) {
		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);
		std::cout << sum_b_all_ << std::endl;
	}
}

