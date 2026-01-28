#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer created" << std::endl;
}
Serializer::Serializer(const Serializer &obj) {
	(void)obj;
	std::cout << "Serializer copied" << std::endl;
}
Serializer &Serializer::operator=(const Serializer &obj) {
	(void)obj;
	std::cout << "Serializer assigned" << std::endl;
	return *this;
}
Serializer::~Serializer() {
	std::cout << "Serializer destroyed" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
