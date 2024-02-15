#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl harl;

		int complaintLevel = harl.getComplaint(argv[1]);
		harl.complain(complaintLevel);
	}
	else
	{
		std::cout << COMPLAINSTR << std::endl;
	}

	return (0);
}