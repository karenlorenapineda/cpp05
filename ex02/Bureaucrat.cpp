/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:31:52 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/22 11:32:41 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	this->_grade = grade;
	if(this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if(this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	
}

Bureaucrat::~Bureaucrat(void)
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if(this != &src)
	{
		this->_grade = src._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName(void) const
{
	return(this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if(this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if(this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("Grade is too low");
}

std::ostream &operator<<(std::ostream& str, const Bureaucrat& bureaucrat)
{
	return(str << bureaucrat.getName() << ", bureacrat grade " << bureaucrat.getGrade());
}