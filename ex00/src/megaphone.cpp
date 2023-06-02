#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string default_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
	{
		std::cout << default_msg << std::endl;
		return EXIT_SUCCESS;
	}

	for (int i = 1; i < argc; i++)
	{
		const char *arg = argv[i];
		while (*arg)
		{
			std::cout << (char)toupper(*arg);
			arg++;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
