/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:24:39 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 23:03:11 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;
	
public:
	AForm(void);
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(AForm const &src);
	virtual ~AForm(void);
	
	AForm &operator=(AForm const &src);

	const std::string&	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();	
	};

protected:
	void		checkExecution(Bureaucrat const& executor) const;
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif