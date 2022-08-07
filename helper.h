#pragma once

#include <random>
#include <chrono>
#include <iomanip>  

int randNum(int range_from, int range_to);

std::chrono::duration<float> timeTrial(std::size_t size);

template<typename T> 
void printElement(T el, const int& width);

#include "print.tpp"