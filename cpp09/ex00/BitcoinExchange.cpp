/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:06:53 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 19:12:26 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <iomanip> 
#include "BitcoinExchange.hpp
 
bool get_date(std::istream &in, std::tm &tm) { 
  in >> std::get_time(&tm, "%m/%d/%Y"); 
  return in; 
} 
 
// tm_year = year - 1900 (may be negative) 
// tm_mon  = month - 1 
// tm_mday = day of the month 
 
std::tm date_info { }; 
bool ok = get_date(std::istringstream(my_date), date_info); 