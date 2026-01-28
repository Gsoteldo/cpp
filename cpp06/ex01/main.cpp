#include "Serializer.hpp"

int main() {
	Data* data = new Data();
	data->value = 42;
	data->info = "This is a test for reinterpret_cast with the serialization.";

	std::cout << "Serialized Data pointer: " << data << std::endl;
	std::cout << "Data-> " << data->value << std::endl;
	std::cout << "Data-> " << data->info << std::endl;
	std::cout << "------------------------" << std::endl;

	uintptr_t rawData = Serializer::serialize(data);

	std::cout << "Raw serialized data: " << rawData << std::endl;

	std::cout << "------------------------" << std::endl;
	
	Data* deserializedData = Serializer::deserialize(rawData);

	std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
	std::cout << "Deserialized Data-> " << deserializedData->value << std::endl;
	std::cout << "Deserialized Data-> " << deserializedData->info << std::endl;

	// delete(deserializedData);
	delete(data);

    return (0);
}