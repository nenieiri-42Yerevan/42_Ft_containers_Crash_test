/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_example9.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:27:43 by vismaily          #+#    #+#             */
/*   Updated: 2022/12/12 16:27:55 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Example 9 */
/* Example for reverse iterator */

#include "test.hpp"

namespace	NS_TEST
{
	const std::string	map_example9()
	{
		std::ostringstream	ss;

		NS::map<int, std::string>						A;
		NS::map<int, std::string>::reverse_iterator	it1;
		NS::map<int, std::string>::reverse_iterator	it2;
		it1 = A.rbegin();
		it2 = A.rend();
		ss << (it1 == it2);
		A.insert(NS::make_pair(0, "0A"));
		A.insert(NS::make_pair(-2, "-2B"));
		A.insert(NS::make_pair(2, "2C"));
		A.insert(NS::make_pair(-1, "-1D"));
		A.insert(NS::make_pair(-3, "-3E"));
		A.insert(NS::make_pair(1, "1F"));
		A.insert(NS::make_pair(3, "3J"));
		it1 = A.rbegin();
		it2 = A.rend();
		ss << " " << (it1 == it2);
		ss << " " << it1->first;
		ss << " " << (--it2)->second;
		ss << " " << (it2--)->second;
		ss << " " << it2->second;
		it2->second = "hello";
		it2 = A.rend();
		while (it1 != it2)
			ss << " " << (it1++)->second;
		return (ss.str());
	}
}
