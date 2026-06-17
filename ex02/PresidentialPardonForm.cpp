#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if(this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void  PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);
	std::cout << _target << " has been pardoned by zaphod Beeblebrox." << std::endl;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	str << "Form: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Exec Grade: " << form.getExecGrade();
    return str;
}