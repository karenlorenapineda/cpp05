/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:27:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/16 20:29:48 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	const std::string 	_name;
	int					_grade;
public:
	
	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& src);

	const std::string& getName(void) const;
	int			 getGrade(void) const;

	void	incrementGrade(void);
	void	decrementGrade(void);

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

std::ostream	&operator<<(std::ostream& str, const Bureaucrat& bureaucrat);

#endif