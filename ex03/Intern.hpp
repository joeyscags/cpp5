/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:15:30 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/08 02:28:02 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	struct FormFactory
	{
		std::string	name;
		AForm*		(*creator)(const std::string& target);
	};

	static AForm*	createShrubberyForm(const std::string& target);
	static AForm*	createRobotomyForm(const std::string& target);
	static AForm*	createPresidentialForm(const std::string& target);
};

#endif
