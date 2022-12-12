/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_example6.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:11 by vismaily          #+#    #+#             */
/*   Updated: 2022/12/12 16:26:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Example 6 */
/* Example for const iterators comparison */

#include "test.hpp"

namespace	NS_TEST
{
	const std::string	map_example6()
	{
		std::ostringstream	ss;

		NS::map<int, std::string>					tree;
		NS::map<int, std::string>::const_iterator	it1;
		NS::map<int, std::string>::const_iterator	it2;
		tree.insert(NS::make_pair(0, "0A"));
		tree.insert(NS::make_pair(-2, "-2B"));
		tree.insert(NS::make_pair(2, "2C"));
		tree.insert(NS::make_pair(-1, "-1D"));
		tree.insert(NS::make_pair(-3, "-3E"));
		tree.insert(NS::make_pair(1, "1F"));
		tree.insert(NS::make_pair(3, "3J"));
		it1 = tree.begin();
		it2 = tree.begin();
		++it2;
		++it2;
		ss << " " << (it2 == it1);
		ss << " " << (it2 != it1);
		it1 = it2;
		ss << " " << (it2 == it1);
		ss << " " << (it2 != it1);
		++it1;
		ss << " " << (it2 == it1);
		ss << " " << (it2 != it1);
		return (ss.str());
	}
}
