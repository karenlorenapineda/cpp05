/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:27:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/05/03 14:41:59 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	std::string 		_name;
	int					_grade;
public:
	
	Bureaucrat(void);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat const	&operator=(Bureaucrat const &src);

	std::string const	&getName(void) const;
	int const			&getGrade(void) const;

	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif