#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string default_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		std::cout << default_msg;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
