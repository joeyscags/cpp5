/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:47:37 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/04 19:54:46 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n========== FORM TESTS ==========" << std::endl;

	std::cout << "\n=== Test 1: Create Valid Forms ===" << std::endl;
	try
	{
		Form formA("Tax Form A38", 50, 25);
		Form formB("Permit B12", 100, 75);
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form Grade Too High (0) ===" << std::endl;
	try
	{
		Form invalid("Invalid Form", 0, 50);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form Grade Too Low (151) ===" << std::endl;
	try
	{
		Form invalid("Invalid Form", 50, 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Successful Form Signing ===" << std::endl;
	try
	{
		Form form("Request Form", 100, 50);
		Bureaucrat alice("Alice", 50);
		
		std::cout << form << std::endl;
		std::cout << alice << std::endl;
		
		alice.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Failed Form Signing (Grade Too Low) ===" << std::endl;
	try
	{
		Form form("Top Secret Form", 10, 5);
		Bureaucrat bob("Bob", 50);
		
		std::cout << form << std::endl;
		std::cout << bob << std::endl;
		
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Multiple Bureaucrats, Same Form ===" << std::endl;
	try
	{
		Form form("Shared Form", 75, 50);
		Bureaucrat charlie("Charlie", 100);
		Bureaucrat diana("Diana", 50);
		
		std::cout << form << std::endl;
		charlie.signForm(form);
		diana.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Edge Cases (Grade 1 and 150) ===" << std::endl;
	try
	{
		Form easyForm("Easy Form", 150, 150);
		Form hardForm("Hard Form", 1, 1);
		Bureaucrat intern("Intern", 150);
		Bureaucrat ceo("CEO", 1);
		
		std::cout << "\n--- Easy Form ---" << std::endl;
		std::cout << easyForm << std::endl;
		intern.signForm(easyForm);
		
		std::cout << "\n--- Hard Form ---" << std::endl;
		std::cout << hardForm << std::endl;
		ceo.signForm(hardForm);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
