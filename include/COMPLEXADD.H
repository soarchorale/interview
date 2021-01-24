#ifndef COMPLEXADD_H_
#define COMPLEXADD_H_

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <random>
#include <thread>
#include <condition_variable>
#include <mutex>

class ComplexAdd {
 public:
  ComplexAdd(){
	  st_a_.a = 0;
	  for (size_t i = 0;
		  i < sizeof(st_b_.data) / sizeof(double); i++) {
		  st_b_.data[i] = 0.0;
	  }
	  sum_b_all_ = 0.0;
  }
  ~ComplexAdd(){}
  ComplexAdd(const ComplexAdd& other) {
	  st_a_ = other.st_a_;
	  st_b_ = other.st_b_;
	  sum_b_ = other.sum_b_;
	  sum_b_all_ = other.sum_b_all_;
  }
  void operator()() {}

  void GenRandomInt();
  void GenRandomDouble();
  void Add();
  void Print();

  void ProducerInt();
  void ProducerDouble();
  void Comsumer();

 public:
  struct A_struct {
	int a;
  }st_a_;

  struct B_struct {
	double data[5];
  }st_b_;
  std::list<A_struct> st_a_buffer_;
  std::list<B_struct> st_b_buffer_;
  double sum_b_;
  double sum_b_all_;

 private:
  std::mutex mtx_lock_;
  std::condition_variable gen_cond_;
};

#endif // !COMPLEXADD_H_
