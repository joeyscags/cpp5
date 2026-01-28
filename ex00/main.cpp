#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n=== Test 1: Valid Bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << "Created: " << bob.getName() << ", grade " << bob.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << "Created: " << invalid.getName() << ", grade " << invalid.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << "Created: " << invalid.getName() << ", grade " << invalid.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 3);
		std::cout << "Created: " << alice.getName() << ", grade " << alice.getGrade() << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice.getName() << ", grade " << alice.getGrade() << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice.getName() << ", grade " << alice.getGrade() << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice.getName() << ", grade " << alice.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 148);
		std::cout << "Created: " << charlie.getName() << ", grade " << charlie.getGrade() << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie.getName() << ", grade " << charlie.getGrade() << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie.getName() << ", grade " << charlie.getGrade() << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie.getName() << ", grade " << charlie.getGrade() << std::endl;
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
		std::cout << "Created: " << top.getName() << ", grade " << top.getGrade() << std::endl;
		std::cout << "Created: " << bottom.getName() << ", grade " << bottom.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
