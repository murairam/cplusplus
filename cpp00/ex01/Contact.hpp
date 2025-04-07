/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:25:27 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/04/07 14:45:01 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    int displayIndex;

public:
    // Constructor (optional, initializes values)
    Contact();
    void setDisplayIndex(int index);
    int getDisplayIndex();

    // Setter methods (to set values)
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickname(std::string name);
    void setPhoneNumber(std::string number);
    void setDarkestSecret(std::string secret);

    // Getter methods (to get values)
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
};

#endif
