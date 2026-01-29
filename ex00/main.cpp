#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n=== Test 1: Valid Bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 3);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 148);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Highest and Lowest Valid Grades ===" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);
		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
