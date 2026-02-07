/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:35:18 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/02 16:35:18 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n========== SHRUBBERY CREATION FORM TESTS ==========" << std::endl;
	
	std::cout << "\n=== Test 1: Successful Shrubbery Creation ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm form("home");
		
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		
		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Execute Without Signing ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		ShrubberyCreationForm form("garden");
		
		alice.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Sign but Grade Too Low to Execute ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 145);
		Bureaucrat manager("Manager", 137);
		ShrubberyCreationForm form("office");
		
		intern.signForm(form);
		intern.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << std::endl;

	std::cout << "\n=== Test 4: Successful Robotomy (50% chance) ===" << std::endl;
	try
	{
		Bureaucrat engineer("Engineer", 45);
		RobotomyRequestForm form("Bender");
		
		std::cout << form << std::endl;
		engineer.signForm(form);
		engineer.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Multiple Robotomy Attempts ===" << std::endl;
	try
	{
		Bureaucrat scientist("Scientist", 1);
		RobotomyRequestForm form1("Target1");
		RobotomyRequestForm form2("Target2");
		RobotomyRequestForm form3("Target3");
		
		scientist.signForm(form1);
		scientist.executeForm(form1);
		
		scientist.signForm(form2);
		scientist.executeForm(form2);
		
		scientist.signForm(form3);
		scientist.executeForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << std::endl;

	std::cout << "\n=== Test 6: Successful Presidential Pardon ===" << std::endl;
	try
	{
		Bureaucrat president("President", 5);
		PresidentialPardonForm form("Arthur Dent");
		
		std::cout << form << std::endl;
		president.signForm(form);
		president.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Grade Too Low for Presidential Pardon ===" << std::endl;
	try
	{
		Bureaucrat clerk("Clerk", 50);
		PresidentialPardonForm form("Ford Prefect");
		
		clerk.signForm(form);
		clerk.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== MIXED SCENARIO TESTS ==========" << std::endl;

	std::cout << "\n=== Test 8: One Bureaucrat, Multiple Forms ===" << std::endl;
	try
	{
		Bureaucrat ceo("CEO", 1);
		ShrubberyCreationForm shrub("headquarters");
		RobotomyRequestForm robot("Employee");
		PresidentialPardonForm pardon("Marvin");
		
		std::cout << "\n--- Shrubbery ---" << std::endl;
		ceo.signForm(shrub);
		ceo.executeForm(shrub);
		
		std::cout << "\n--- Robotomy ---" << std::endl;
		ceo.signForm(robot);
		ceo.executeForm(robot);
		
		std::cout << "\n--- Presidential Pardon ---" << std::endl;
		ceo.signForm(pardon);
		ceo.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 9: Edge Cases - Grade Boundaries ===" << std::endl;
	try
	{
		std::cout << "\n--- Grade 145 (exact sign requirement) ---" << std::endl;
		Bureaucrat b145("B145", 145);
		ShrubberyCreationForm form1("test1");
		b145.signForm(form1);
		
		std::cout << "\n--- Grade 72 (exact robotomy sign) ---" << std::endl;
		Bureaucrat b72("B72", 72);
		RobotomyRequestForm form2("test2");
		b72.signForm(form2);
		
		std::cout << "\n--- Grade 25 (exact pardon sign) ---" << std::endl;
		Bureaucrat b25("B25", 25);
		PresidentialPardonForm form3("test3");
		b25.signForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
