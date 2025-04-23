/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:20 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/04/23 20:06:32 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	char buffer[20];
	std::time_t time = std::time(0);
	std::tm *localTime = std::localtime(&time);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer;
}
//Constructor [timestamp]index:0;amount:y;created
Account::Account(int deposit) : _accountIndex(_nbAccounts),
								_amount(deposit),
								_nbDeposits(0),
								_nbWithdrawals(0)
{
	_totalAmount += deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;
}

//Destructor [timestamp]index:0;amount:y;created
Account::~Account() {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed" << std::endl;

}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << withdrawal;
	if (_amount < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbDeposits++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);
}

int Account::checkAmount() const
{

	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}