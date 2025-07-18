/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:59 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 13:47:58 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef HARL_HPP
# define HARL_HPP

class Harl 
{
	
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
public:
	Harl();
	~Harl();

	void complain( std::string level );
};

#endif