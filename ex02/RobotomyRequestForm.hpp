#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	std::string	_target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	std::string getTarget() const;
	void execute(Bureaucrat const& executor) const;

};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &robotomyRequestForm);

#endif