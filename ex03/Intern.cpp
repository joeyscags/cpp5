/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:18:45 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/08 02:28:00 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	FormFactory factories[] = {
		{"shrubbery creation", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (factories[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return factories[i].creator(target);
		}
	}

	std::cout << "Error: Form name '" << formName << "' does not exist!" << std::endl;
	return NULL;
}
