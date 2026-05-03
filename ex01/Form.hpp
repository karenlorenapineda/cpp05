/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:24:39 by kpineda-          #+#    #+#             */
/*   Updated: 2026/05/03 21:24:39 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_execGrade;
public:
	Form(void);
	Form(std::string const &name, int const &signGrade, int const &execGrade);
	Form(Form const &src);
	~Form(void);
	
	Form const &operator=(Form const &src);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void	beSigned(const Bureaucrat &bureaucrat);
	
	class GradeTooHighException: public std::exception
	{
	public:
		virtual char const *what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
	public:
		virtual char const *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif