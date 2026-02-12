/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:20:18 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/12 13:43:34 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "\n========== INTERN TESTS ==========" << std::endl;

	std::cout << "\n=== Test 1: Create Shrubbery Form via Intern ===" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			
			Bureaucrat bob("Bob", 137);
			bob.signForm(*form);
			bob.executeForm(*form);
			
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Create Robotomy Form via Intern ===" << std::endl;
	try
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			
			Bureaucrat alice("Alice", 45);
			alice.signForm(*form);
			alice.executeForm(*form);
			
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Create Presidential Pardon via Intern ===" << std::endl;
	try
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			std::cout << *form << std::endl;
			
			Bureaucrat president("President", 5);
			president.signForm(*form);
			president.executeForm(*form);
			
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Invalid Form Name ===" << std::endl;
	try
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("invalid form", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation returned NULL as expected." << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Multiple Forms from Same Intern ===" << std::endl;
	try
	{
		Intern intern;
		AForm* form1 = intern.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern.makeForm("robotomy request", "Target1");
		AForm* form3 = intern.makeForm("presidential pardon", "Criminal");
		
		Bureaucrat ceo("CEO", 1);
		
		if (form1)
		{
			std::cout << "\n--- Form 1 ---" << std::endl;
			ceo.signForm(*form1);
			ceo.executeForm(*form1);
			delete form1;
		}
		
		if (form2)
		{
			std::cout << "\n--- Form 2 ---" << std::endl;
			ceo.signForm(*form2);
			ceo.executeForm(*form2);
			delete form2;
		}
		
		if (form3)
		{
			std::cout << "\n--- Form 3 ---" << std::endl;
			ceo.signForm(*form3);
			ceo.executeForm(*form3);
			delete form3;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Multiple Invalid Form Names ===" << std::endl;
	{
		Intern intern;
		
		std::cout << "\nTrying 'unknown form':" << std::endl;
		AForm* f1 = intern.makeForm("unknown form", "test");
		if (!f1) std::cout << "Correctly returned NULL" << std::endl;
		
		std::cout << "\nTrying 'Shrubbery Creation' (wrong case):" << std::endl;
		AForm* f2 = intern.makeForm("Shrubbery Creation", "test");
		if (!f2) std::cout << "Correctly returned NULL" << std::endl;
		
		std::cout << "\nTrying empty string:" << std::endl;
		AForm* f3 = intern.makeForm("", "test");
		if (!f3) std::cout << "Correctly returned NULL" << std::endl;
	}

	std::cout << "\n=== Test 7: Intern Without Execution ===" << std::endl;
	try
	{
		Intern intern;
		AForm* form = intern.makeForm("robotomy request", "TestSubject");
		
		if (form)
		{
			std::cout << "Form created successfully: " << form->getName() << std::endl;
			std::cout << "But we won't execute it - just delete it." << std::endl;
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
