#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data data;

	data.raw = 9999;
	uintptr_t ptr_t = serialize(&data);
	Data *convertedData = deserialize(ptr_t);
	std::cout << convertedData->raw << std::endl;

	return (0);
}