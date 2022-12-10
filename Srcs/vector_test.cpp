/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:10:37 by vismaily          #+#    #+#             */
/*   Updated: 2022/12/10 17:23:29 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

static void	example2()
{
	/* Example 2 */
	/* Example for constructor with 2 parametrs with double */
	/* Example for operator[] */

	std::vector<double> vec(3, double(58));
	std::cout << COLOR_PURPLE_B << "Example 2" << COLOR_END << std::endl;
	std::cout << std::fixed << std::setprecision(2) << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[2]: " << vec[2] << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<double> ft_vec(3, double(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[2]: " << ft_vec[2] << '.' << std::endl;
	std::cout << COLOR_END << std::endl;
}

static void	example3()
{
	/* Example 3 */
	/* Example for const operator[] and for function at() with float */

	const std::vector<float> vec(10, float(-60));
	std::cout << COLOR_PURPLE_B << "Example 3" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> at(3): " << vec.at(3);
	try
	{
		std::cout << ", at(13): " << vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << COLOR_END << std::endl;

	const ft::vector<float> ft_vec(10, float(-60));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> at(3): " << ft_vec.at(3);
	try
	{
		std::cout << ", at(13): " << ft_vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << COLOR_END << std::endl << std::endl;
}

static void	example4()
{
	/* Example 4 */
	/* Example for front() and back() functions */

	const std::vector<int> vec(3, int(58));
	std::cout << COLOR_PURPLE_B << "Example 4" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[0]: " << vec[0];
	std::cout << ", front(): " << vec.front();
	std::cout << ", value[2]: " << vec[0];
	std::cout << ", back(): " << vec.back() << '.';
	std::cout << COLOR_END << std::endl;

	const ft::vector<int> ft_vec(3, int(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[0]: " << ft_vec[0];
	std::cout << ", front(): " << ft_vec.front();
	std::cout << ", value[2]: " << ft_vec[0];
	std::cout << ", back(): " << ft_vec.back() << '.';
	std::cout << COLOR_END << std::endl << std::endl;
}

static void	example5()
{
	/* Example 5 */
	/* Example for data() */

	int	*p;

	std::vector<int> vec(5, int(41));
	std::cout << COLOR_PURPLE_B << "Example 5" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	p = vec.data();
	std::cout << ", p[0]: " << p[0] << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(41));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	p = ft_vec.data();
	std::cout << ", p[0]: " << p[0] << '.';
	std::cout << COLOR_END << std::endl << std::endl;
}

static void	example6()
{
	/* Example 6 */
	/* Example for max_size() and get_allocator() */

	long double	*p;

	std::vector<long double> vec(5, (long double)(41));
	std::cout << COLOR_PURPLE_B << "Example 6" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", max_size: " << vec.max_size();

	p = vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ' ' << p[i];
		vec.get_allocator().destroy(&p[i]);
	}
	vec.get_allocator().deallocate(p, 3);

	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<long double> ft_vec(5, (long double)(41));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", max_size: " << ft_vec.max_size();

	p = ft_vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		ft_vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ' ' << p[i];
		ft_vec.get_allocator().destroy(&p[i]);
	}
	ft_vec.get_allocator().deallocate(p, 3);

	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example7()
{
	/* Example 7 */
	/* Example for push_back() and pop_back() */
	/* Example for clear() function */
	/* Example for empty() function */

	std::vector<int> vec(5, (int)(42));
	std::cout << COLOR_PURPLE_B << "Example 7" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	vec.pop_back();
	vec.pop_back();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.clear();
	std::cout << ", after clear capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, (int)(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	ft_vec.pop_back();
	ft_vec.pop_back();
	std::cout << ", is_empty: " << ft_vec.empty();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.clear();
	std::cout << ", after clear capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", is_empty: " << ft_vec.empty();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example8()
{
	/* Example 8 */
	/* Example for iterators */

	std::vector<int> vec;
	std::vector<int>::iterator	it;
	std::cout << COLOR_PURPLE_B << "Example 8" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.begin();
	std::cout << ", it_begin: " << *it;
	it = vec.begin() + 1;
	std::cout << ", it_begin + 1: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it++: " << *(it++);
	std::cout << ", ++it: " << *(++it);
	it = vec.end() - 1;
	std::cout << ", it_end - 1: " << *it;
	it -= 2;
	std::cout << ", it -= 2: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it[-1]: " << it[-1];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	ft::vector<int>::iterator	ft_it;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> ";

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it = ft_vec.begin();
	std::cout << ", it_begin: " << *ft_it;
	ft_it = ft_vec.begin() + 1;
	std::cout << ", it_begin + 1: " << *ft_it;
	ft_it += 1;
	std::cout << ", it += 1: " << *ft_it;
	std::cout << ", it++: " << *(ft_it++);
	std::cout << ", ++it: " << *(++ft_it);
	ft_it = ft_vec.end() - 1;
	std::cout << ", it_end - 1: " << *ft_it;
	ft_it -= 2;
	std::cout << ", it -= 2: " << *ft_it;
	ft_it += 1;
	std::cout << ", it += 1: " << *ft_it;
	std::cout << ", it[-1]: " << ft_it[-1];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example9()
{
	/* Example 9 */
	/* Example for iterators comparison */

	std::vector<int> vec;
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 9" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it1 = vec.begin();
	it2 = vec.begin() + 2;
	std::cout << ", it2 - it1: " << (it2 - it1);
	std::cout << ", it2 > it1: " << (it2 > it1);
	std::cout << ", it2 < it1: " << (it2 < it1);
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	it1 = it2;
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	ft::vector<int>::iterator	ft_it1;
	ft::vector<int>::iterator	ft_it2;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> ";

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it1 = ft_vec.begin();
	ft_it2 = ft_vec.begin() + 2;
	std::cout << ", it2 - it1: " << (ft_it2 - ft_it1);
	std::cout << ", it2 > it1: " << (ft_it2 > ft_it1);
	std::cout << ", it2 < it1: " << (ft_it2 < ft_it1);
	std::cout << ", it2 >= it1: " << (ft_it2 >= ft_it1);
	std::cout << ", it2 <= it1: " << (ft_it2 <= ft_it1);
	std::cout << ", it2 == it1: " << (ft_it2 == ft_it1);
	std::cout << ", it2 != it1: " << (ft_it2 != ft_it1);
	ft_it1 = ft_it2;
	std::cout << ", it2 >= it1: " << (ft_it2 >= ft_it1);
	std::cout << ", it2 <= it1: " << (ft_it2 <= ft_it1);
	std::cout << ", it2 == it1: " << (ft_it2 == ft_it1);
	std::cout << ", it2 != it1: " << (ft_it2 != ft_it1);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example10()
{
	/* Example 10 */
	/* Example for const iterators comparison */

	std::vector< int> vec;
	std::cout << COLOR_PURPLE_B << "Example 10" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int>::const_iterator	it1 = vec.begin();
	std::vector<int>::const_iterator	it2 = vec.begin() + 2;
	std::cout << ", it2 - it1: " << (it2 - it1);
	std::cout << ", it2 > it1: " << (it2 > it1);
	std::cout << ", it2 < it1: " << (it2 < it1);
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	std::vector<int>::const_iterator	it3 = vec.begin() + 2;
	std::vector<int>::const_iterator	it4 = vec.begin() + 2;
	std::cout << ", it2 >= it1: " << (it4 >= it3);
	std::cout << ", it2 <= it1: " << (it4 <= it3);
	std::cout << ", it2 == it1: " << (it4 == it3);
	std::cout << ", it2 != it1: " << (it4 != it3);
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> ";

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int>::const_iterator	ft_it1 = ft_vec.begin();
	ft::vector<int>::const_iterator	ft_it2 = ft_vec.begin() + 2;
	std::cout << ", it2 - it1: " << (ft_it2 - ft_it1);
	std::cout << ", it2 > it1: " << (ft_it2 > ft_it1);
	std::cout << ", it2 < it1: " << (ft_it2 < ft_it1);
	std::cout << ", it2 >= it1: " << (ft_it2 >= ft_it1);
	std::cout << ", it2 <= it1: " << (ft_it2 <= ft_it1);
	std::cout << ", it2 == it1: " << (ft_it2 == ft_it1);
	std::cout << ", it2 != it1: " << (ft_it2 != ft_it1);
	ft::vector<int>::const_iterator	ft_it3 = ft_vec.begin() + 2;
	ft::vector<int>::const_iterator	ft_it4 = ft_vec.begin() + 2;
	std::cout << ", it2 >= it1: " << (ft_it4 >= ft_it3);
	std::cout << ", it2 <= it1: " << (ft_it4 <= ft_it3);
	std::cout << ", it2 == it1: " << (ft_it4 == ft_it3);
	std::cout << ", it2 != it1: " << (ft_it4 != ft_it3);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example11()
{
	/* Example 11 */
	/* Example for copy constructors */

	std::vector<double> vec(2, double(58));
	std::cout << COLOR_PURPLE_B << "Example 12" << COLOR_END << std::endl;
	std::cout << std::fixed << std::setprecision(2) << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", copy-constructor:";
	std::vector<double> vec2(vec);
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	vec.push_back(42);
	vec2 = vec;
	std::cout << ", copy-assignement:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<double> ft_vec(2, double(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", copy-constructor:";
	ft::vector<double> ft_vec2(ft_vec);
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	ft_vec.push_back(42);
	ft_vec2 = ft_vec;
	std::cout << ", copy-assignement:";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example12()
{
	/* Example 12 */
	/* Example for insert */

	std::vector<int> vec(5, int(58));
	std::cout << COLOR_PURPLE_B << "Example 13" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::vector<int>::iterator it = vec.begin() + 2;
	vec.insert(it, 3, 50);
	vec.insert(vec.begin(), 1, 1);
	vec.insert(vec.begin(), 0, 2);
	vec.insert(vec.end(), 3, 2);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.reserve(30);
	it = vec.begin() + 2;
	vec.insert(it, 3, -50);
	vec.insert(vec.begin(), 0, -2);
	vec.insert(vec.end(), 3, -2);
	vec.insert(vec.begin(), 1, -1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;
	ft_vec.insert(ft_it, 3, 50);
	ft_vec.insert(ft_vec.begin(), 1, 1);
	ft_vec.insert(ft_vec.begin(), 0, 2);
	ft_vec.insert(ft_vec.end(), 3, 2);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.reserve(30);
	ft_it = ft_vec.begin() + 2;
	ft_vec.insert(ft_it, 3, -50);
	ft_vec.insert(ft_vec.begin(), 0, -2);
	ft_vec.insert(ft_vec.end(), 3, -2);
	ft_vec.insert(ft_vec.begin(), 1, -1);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example13()
{
	/* Example 13 */
	/* Example for insert part 2 */

	std::vector<int> vec(5, int(58));
	std::cout << COLOR_PURPLE_B << "Example 14" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::vector<int>::iterator it = vec.begin() + 2;
	vec.insert(it, 1);
	it = vec.insert(vec.begin(), 1);
	vec.insert(vec.end(), 1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", it: " << *it;
	vec.reserve(30);
	it = vec.begin() + 2;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::vector<int> vec5;
	vec5.insert(vec5.begin(), 9);
	vec5.insert(vec5.end() - 1, 3, 10);
	std::cout << ", values:";
	for (size_t i = 0; i < vec5.size(); ++i)
		std::cout << ' ' << vec5[i];
	std::cout << ", capacity: " << vec5.capacity();
	std::cout << ", size: " << vec5.size();
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;
	ft_vec.insert(ft_it, 1);
	ft_it = ft_vec.insert(ft_vec.begin(), 1);
	ft_vec.insert(ft_vec.end(), 1);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", it: " << *ft_it;
	ft_vec.reserve(30);
	ft_it = ft_vec.begin() + 2;
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft::vector<int> ft_vec5;
	ft_vec5.insert(ft_vec5.begin(), 9);
	ft_vec5.insert(ft_vec5.end() - 1, 3, 10);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec5.size(); ++i)
		std::cout << ' ' << ft_vec5[i];
	std::cout << ", capacity: " << ft_vec5.capacity();
	std::cout << ", size: " << ft_vec5.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example14()
{
	/* Example 14 */
	/* Example for insert */

	std::vector<int> vec(5, int(58));
	std::cout << COLOR_PURPLE_B << "Example 15" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::vector<int> vec1(2, int(42));
	vec.insert(vec.begin() + 2, vec1.begin(), vec1.end());
	vec.insert(vec.begin(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec1.begin(), vec1.end());
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.reserve(30);
	std::vector<int> vec2(2, int(21));
	vec.insert(vec.begin() + 2, vec2.begin(), vec2.end());
	vec.insert(vec.begin(), vec2.begin(), vec2.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft::vector<int> ft_vec1(2, int(42));
	ft_vec.insert(ft_vec.begin() + 2, ft_vec1.begin(), ft_vec1.end());
	ft_vec.insert(ft_vec.begin(), ft_vec1.begin(), ft_vec1.end());
	ft_vec.insert(ft_vec.end(), ft_vec1.begin(), ft_vec1.end());
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.reserve(30);
	ft::vector<int> ft_vec2(2, int(21));
	ft_vec.insert(ft_vec.begin() + 2, ft_vec2.begin(), ft_vec2.end());
	ft_vec.insert(ft_vec.begin(), ft_vec2.begin(), ft_vec2.end());
	ft_vec.insert(ft_vec.end(), ft_vec2.begin(), ft_vec2.end());
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example15()
{
	/* Example 15 */
	/* Example for erase */

	std::vector<int> vec;
	std::cout << COLOR_PURPLE_B << "Example 16" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	for (size_t i = 0; i < 9; ++i)
		vec.push_back(i);
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int>::iterator it;
	it = vec.erase(vec.begin() + 1);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin() + 2, vec.end() - 2);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin(), vec.begin() + 1);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin(), vec.begin());
	std::cout << ", it: " << *it;
	it = vec.erase(vec.end() - 2, vec.end() - 1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", it: " << *it;
	it = vec.erase(vec.begin(), vec.end());
	std::cout << ", it: " << *it;
	std::cout << ", std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	std::cout << COLOR_GREEN_B;
	for (size_t i = 0; i < 9; ++i)
		ft_vec.push_back(i);
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int>::iterator ft_it;
	ft_it = ft_vec.erase(ft_vec.begin() + 1);
	std::cout << ", it: " << *ft_it;
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it = ft_vec.erase(ft_vec.begin() + 2, ft_vec.end() - 2);
	std::cout << ", it: " << *ft_it;
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it = ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 1);
	std::cout << ", it: " << *ft_it;
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it = ft_vec.erase(ft_vec.begin(), ft_vec.begin());
	std::cout << ", it: " << *ft_it;
	ft_it = ft_vec.erase(ft_vec.end() - 2, ft_vec.end() - 1);
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", it: " << *ft_it;
	ft_it = ft_vec.erase(ft_vec.begin(), ft_vec.end());
	std::cout << ", it: " << *ft_it;
	std::cout << ", ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example16()
{
	/* Example 16 */
	/* Example for resize */

	std::vector<int> vec(5, int(42));
	std::cout << COLOR_PURPLE_B << "Example 17" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(7);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(11, 21);
	vec.resize(11);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(6);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.resize(7);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.resize(11, 21);
	ft_vec.resize(11);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.resize(6);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example17()
{
	/* Example 17 */
	/* Example for assign */

	std::vector<int> vec(5, int(42));
	std::cout << COLOR_PURPLE_B << "Example 18" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(11, 48);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(3, 21);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(0, 2);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.assign(11, 48);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.assign(3, 21);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.assign(0, 2);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example18()
{
	/* Example 18 */
	/* Example for assign part 2 */

	std::vector<int> vec(5, int(42));
	std::cout << COLOR_PURPLE_B << "Example 19" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int> vec2(2, int(21));
	vec.assign(vec2.begin(), vec2.end());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec2.assign(11, 42);
	vec.assign(vec2.begin(), vec2.end());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(vec2.begin(), vec2.begin());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int> ft_vec2(2, int(21));
	ft_vec.assign(ft_vec2.begin(), ft_vec2.end());
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec2.assign(11, 42);
	ft_vec.assign(ft_vec2.begin(), ft_vec2.end());
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.assign(ft_vec2.begin(), ft_vec2.begin());
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example19()
{
	/* Example 19 */
	/* Example for swaps */

	std::vector<int> vec(3, int(42));
	std::cout << COLOR_PURPLE_B << "Example 20" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int> vec2(9, int(21));
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	vec.swap(vec2);
	std::cout << ", vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(3, int(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector1  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int> ft_vec2(9, int(21));
	std::cout << ", vector2 capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	ft_vec.swap(ft_vec2);
	std::cout << ", vector1 -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", vector2 capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example20()
{
	/* Example 20 */
	/* Example for swaps part 2 */

	std::vector<int> vec(3, int(42));
	std::cout << COLOR_PURPLE_B << "Example 21" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int> vec2(9, int(21));
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	swap(vec, vec2);
	std::cout << ", vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(3, int(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector1  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int> ft_vec2(9, int(21));
	std::cout << ", vector2 capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	swap(ft_vec, ft_vec2);
	std::cout << ", vector1 -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << ", vector2 capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ' ' << ft_vec2[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example21()
{
	/* Example 21 */
	/* Example for relational operators */

	std::vector<char> vec1;
	std::vector<char> vec2;
	std::cout << COLOR_PURPLE_B << "Example 22" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	vec1.push_back('h');
	vec1.push_back('e');
	vec1.push_back('l');
	vec1.push_back('l');
	vec1.push_back('o');
	vec2.push_back('h');
	vec2.push_back('e');
	vec2.push_back('l');
	vec2.push_back('l');
	vec2.push_back('o');
	std::cout << "std::vector -> ";
	std::cout << "values1: ";
	for (size_t i = 0; i < vec1.size(); ++i)
		std::cout << vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i];
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec2.push_back('o');
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec1.push_back('o');
	vec1.push_back('o');
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec1.pop_back();
	vec1.erase(vec1.begin() + 1);
	vec1.insert(vec1.begin() + 1, 'E');
	std::cout << ", values1: ";
	for (size_t i = 0; i < vec1.size(); ++i)
		std::cout << vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i];
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<char> ft_vec1;
	ft::vector<char> ft_vec2;
	std::cout << COLOR_GREEN_B;
	ft_vec1.push_back('h');
	ft_vec1.push_back('e');
	ft_vec1.push_back('l');
	ft_vec1.push_back('l');
	ft_vec1.push_back('o');
	ft_vec2.push_back('h');
	ft_vec2.push_back('e');
	ft_vec2.push_back('l');
	ft_vec2.push_back('l');
	ft_vec2.push_back('o');
	std::cout << "ft::vector  -> ";
	std::cout << "values1: ";
	for (size_t i = 0; i < ft_vec1.size(); ++i)
		std::cout << ft_vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ft_vec2[i];
	std::cout << ", == " << (ft_vec1 == ft_vec2);
	std::cout << ", != " << (ft_vec1 != ft_vec2);
	std::cout << ", < " << (ft_vec1 < ft_vec2);
	std::cout << ", <= " << (ft_vec1 <= ft_vec2);
	std::cout << ", > " << (ft_vec1 > ft_vec2);
	std::cout << ", >= " << (ft_vec1 >= ft_vec2);
	ft_vec2.push_back('o');
	std::cout << ", == " << (ft_vec1 == ft_vec2);
	std::cout << ", != " << (ft_vec1 != ft_vec2);
	std::cout << ", < " << (ft_vec1 < ft_vec2);
	std::cout << ", <= " << (ft_vec1 <= ft_vec2);
	std::cout << ", > " << (ft_vec1 > ft_vec2);
	std::cout << ", >= " << (ft_vec1 >= ft_vec2);
	ft_vec1.push_back('o');
	ft_vec1.push_back('o');
	std::cout << ", == " << (ft_vec1 == ft_vec2);
	std::cout << ", != " << (ft_vec1 != ft_vec2);
	std::cout << ", < " << (ft_vec1 < ft_vec2);
	std::cout << ", <= " << (ft_vec1 <= ft_vec2);
	std::cout << ", > " << (ft_vec1 > ft_vec2);
	std::cout << ", >= " << (ft_vec1 >= ft_vec2);
	ft_vec1.pop_back();
	ft_vec1.erase(ft_vec1.begin() + 1);
	ft_vec1.insert(ft_vec1.begin() + 1, 'E');
	std::cout << ", values1: ";
	for (size_t i = 0; i < ft_vec1.size(); ++i)
		std::cout << ft_vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < ft_vec2.size(); ++i)
		std::cout << ft_vec2[i];
	std::cout << ", == " << (ft_vec1 == ft_vec2);
	std::cout << ", != " << (ft_vec1 != ft_vec2);
	std::cout << ", < " << (ft_vec1 < ft_vec2);
	std::cout << ", <= " << (ft_vec1 <= ft_vec2);
	std::cout << ", > " << (ft_vec1 > ft_vec2);
	std::cout << ", >= " << (ft_vec1 >= ft_vec2);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example22()
{
	/* Example 22 */
	/* Example for reverse iterator */

	std::vector<int> vec;
	std::cout << COLOR_PURPLE_B << "Example 23" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(i);
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int>::reverse_iterator	rit(vec.end());
	std::cout << ", it: " << *rit;
	std::cout << ", it: " << *(rit++);
	std::cout << ", it: " << *(++rit);
	std::cout << ", it: " << *(rit--);
	std::cout << ", it: " << *(--rit);
	std::vector<int>::reverse_iterator	rit2(vec.begin() + 1);
	std::cout << ", it: " << *rit2;
	std::cout << ", it: " << *(rit2 - 1);
	rit2 -= 2;
	std::cout << ", it: " << *rit2;
	std::cout << ", it: " << *(rit2 + 1);
	rit2 += 1;
	std::cout << ", it: " << *rit2;
	std::vector<int>::reverse_iterator	rit3;
	rit3 = rit2;
	std::cout << ", it: " << *rit3;
	rit3 = rit3 - 2;
	std::cout << ", it: " << *(rit3.base());
	std::cout << ", it: " << rit3[1];
	std::cout << ", it: " << rit3[3];
	std::vector<int>::reverse_iterator	rit4(rit3);
	std::cout << ", it: " << *rit4;
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	std::cout << COLOR_GREEN_B;
	for (size_t i = 0; i < 5; ++i)
		ft_vec.push_back(i);
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int>::reverse_iterator	ft_rit(ft_vec.end());
	std::cout << ", it: " << *ft_rit;
	std::cout << ", it: " << *(ft_rit++);
	std::cout << ", it: " << *(++ft_rit);
	std::cout << ", it: " << *(ft_rit--);
	std::cout << ", it: " << *(--ft_rit);
	ft::vector<int>::reverse_iterator	ft_rit2(ft_vec.begin() + 1);
	std::cout << ", it: " << *ft_rit2;
	std::cout << ", it: " << *(ft_rit2 - 1);
	ft_rit2 -= 2;
	std::cout << ", it: " << *ft_rit2;
	std::cout << ", it: " << *(ft_rit2 + 1);
	ft_rit2 += 1;
	std::cout << ", it: " << *ft_rit2;
	ft::vector<int>::reverse_iterator	ft_rit3;
	ft_rit3 = ft_rit2;
	std::cout << ", it: " << *ft_rit3;
	ft_rit3 = ft_rit3 - 2;
	std::cout << ", it: " << *(ft_rit3.base());
	std::cout << ", it: " << ft_rit3[1];
	std::cout << ", it: " << ft_rit3[3];
	ft::vector<int>::reverse_iterator	ft_rit4(ft_rit3);
	std::cout << ", it: " << *ft_rit4;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example23()
{
	/* Example 23 */
	/* Example for rbegin, rend */

	std::vector<int> vec;
	std::cout << COLOR_PURPLE_B << "Example 24" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(i);
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::vector<int>::reverse_iterator	rit1;
	rit1 = vec.rbegin();
	std::cout << ", it: " << *rit1;
	rit1 = vec.rend() - 1;
	std::cout << ", it: " << *rit1;
	std::vector<int>::reverse_iterator	rit2(rit1);
	std::cout << ", it: " << *(rit2 - 1);
	std::vector<int>::const_reverse_iterator	rit3 = rit2;
	std::cout << ", it: " << *rit3;
	std::cout << ", == " << (rit3 == rit2);
	std::cout << ", != " << (rit3 != rit2);
	std::cout << ", < " << (rit3 < rit2);
	std::cout << ", <= " << (rit3 <= rit2);
	std::cout << ", > " << (rit3 > rit2);
	std::cout << ", >= " << (rit3 >= rit2);
	rit3 = rit2 - 1;
	std::cout << ", == " << (rit3 == rit2);
	std::cout << ", != " << (rit3 != rit2);
	std::cout << ", < " << (rit3 < rit2);
	std::cout << ", <= " << (rit3 <= rit2);
	std::cout << ", > " << (rit3 > rit2);
	std::cout << ", >= " << (rit3 >= rit2);
	std::cout << ", + " << *(1 + rit3);
	rit2 += 3;
	rit3 += 3;
	std::cout << ", - " << (rit2 - rit1);
	std::cout << ", - " << (rit3 - rit2);
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec;
	std::cout << COLOR_GREEN_B;
	for (size_t i = 0; i < 5; ++i)
		ft_vec.push_back(i);
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft::vector<int>::reverse_iterator	ft_rit1;
	ft_rit1 = ft_vec.rbegin();
	std::cout << ", it: " << *ft_rit1;
	ft_rit1 = ft_vec.rend() - 1;
	std::cout << ", it: " << *ft_rit1;
	ft::vector<int>::reverse_iterator	ft_rit2(ft_rit1);
	std::cout << ", it: " << *(ft_rit2 - 1);
	ft::vector<int>::const_reverse_iterator	ft_rit3 = ft_rit2;
	std::cout << ", it: " << *ft_rit3;
	std::cout << ", == " << (ft_rit3 == ft_rit2);
	std::cout << ", != " << (ft_rit3 != ft_rit2);
	std::cout << ", < " << (ft_rit3 < ft_rit2);
	std::cout << ", <= " << (ft_rit3 <= ft_rit2);
	std::cout << ", > " << (ft_rit3 > ft_rit2);
	std::cout << ", >= " << (ft_rit3 >= ft_rit2);
	ft_rit3 = ft_rit2 - 1;
	std::cout << ", == " << (ft_rit3 == ft_rit2);
	std::cout << ", != " << (ft_rit3 != ft_rit2);
	std::cout << ", < " << (ft_rit3 < ft_rit2);
	std::cout << ", <= " << (ft_rit3 <= ft_rit2);
	std::cout << ", > " << (ft_rit3 > ft_rit2);
	std::cout << ", >= " << (ft_rit3 >= ft_rit2);
	std::cout << ", + " << *(1 + ft_rit3);
	ft_rit2 += 3;
	ft_rit3 += 3;
	std::cout << ", - " << (ft_rit2 - ft_rit1);
	std::cout << ", - " << (ft_rit3 - ft_rit2);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

struct	A
{
	A* operator &() const
	{
		std::cout << "error ";
		return (0);
	}
};

static void	example24()
{
	/* Example 24 */
	/* Example for & and address */

	std::vector<A> vec;
	std::cout << COLOR_PURPLE_B << "Example 25" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(A());
	vec.reserve(20);
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<A> ft_vec;
	std::cout << COLOR_GREEN_B;
	for (size_t i = 0; i < 5; ++i)
		ft_vec.push_back(A());
	ft_vec.reserve(20);
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", values:";
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example25()
{
	/* Example 25 */
	/* Example tests for insert2 */

	const int cut = 3;
	std::cout << COLOR_PURPLE_B << "Example 26" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::vector<int> vct(5);
	std::vector<int> vct2;
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	std::cout << "std::vector ->";
	std::cout << " values:";
	for (unsigned long int i = 0; i < vct.size(); ++i)
		std::cout << " " << vct[i];

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	std::cout << ", " << *vct2.insert(vct2.end(), 42) << ", ";
	std::cout << *vct2.insert(vct2.begin() + 5, 84);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::vector<int> ft_vct(5);
	ft::vector<int> ft_vct2;
	for (unsigned long int i = 0; i < ft_vct.size(); ++i)
		ft_vct[i] = (ft_vct.size() - i) * 7;
	std::cout << "ft::vector ->";
	std::cout << " values:";
	for (unsigned long int i = 0; i < ft_vct.size(); ++i)
		std::cout << " " << ft_vct[i];

	ft_vct2.insert(ft_vct2.begin(), ft_vct.begin(), ft_vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < ft_vct2.size(); ++i)
		std::cout << " " << ft_vct2[i];
	ft_vct2.insert(ft_vct2.begin(), ft_vct.begin() + cut, ft_vct.end());
	std::cout << ", values:";
	for (unsigned long int i = 0; i < ft_vct2.size(); ++i)
		std::cout << " " << ft_vct2[i];
	ft_vct2.insert(ft_vct2.end(), ft_vct.begin(), ft_vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < ft_vct2.size(); ++i)
		std::cout << " " << ft_vct2[i];
	std::cout << ", " << *ft_vct2.insert(ft_vct2.end(), 42) << ", ";
	std::cout << *ft_vct2.insert(ft_vct2.begin() + 5, 84);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < ft_vct2.size(); ++i)
		std::cout << " " << ft_vct2[i];
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example26()
{
	/* Example 26 */
	/* Example tests for copy-constructor */

	std::cout << COLOR_PURPLE_B << "Example 27" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector ->";
	std::vector<int> vct(5);
	std::vector<int>::iterator	it = vct.begin();
	std::vector<int>::iterator	ite = vct.end();
	std::cout << " len: " << (ite - it);
	for (; it != ite; ++it)
		*it = (ite - it);
	it = vct.begin();
	std::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;
	it = vct.begin();
	std::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);
	std::cout << ", vct_size: " << vct.size();
	std::cout << ", vct_range_size: " << vct_range.size();
	std::cout << ", vct_copy_size: " << vct_copy.size();
	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();
	it = vct.begin();
	std::cout << ", vct_values:";
	for (; it != vct.end(); ++it)
		std::cout << " " << *it;
	it = vct_range.begin();
	std::cout << ", vct_range_values:";
	for (; it != vct_range.end(); ++it)
		std::cout << " " << *it;
	it = vct_copy.begin();
	std::cout << ", vct_copy_values:";
	for (; it != vct_copy.end(); ++it)
		std::cout << " " << *it;
	std::cout << ", vct_size: " << vct.size();
	std::cout << ", vct_range_size: " << vct_range.size();
	std::cout << ", vct_copy_size: " << vct_copy.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  ->";
	ft::vector<int> ft_vct(5);
	ft::vector<int>::iterator	ft_it = ft_vct.begin();
	ft::vector<int>::iterator	ft_ite = ft_vct.end();
	std::cout << " len: " << (ft_ite - ft_it);
	for (; ft_it != ft_ite; ++ft_it)
		*ft_it = (ft_ite - ft_it);
	ft_it = ft_vct.begin();
	ft::vector<int> ft_vct_range(ft_it, --(--ft_ite));
	for (int i = 0; ft_it != ft_ite; ++ft_it)
		*ft_it = ++i * 5;
	ft_it = ft_vct.begin();
	ft::vector<int> ft_vct_copy(ft_vct);
	for (int i = 0; ft_it != ft_ite; ++ft_it)
		*ft_it = ++i * 7;
	ft_vct_copy.push_back(42);
	ft_vct_copy.push_back(21);
	std::cout << ", vct_size: " << ft_vct.size();
	std::cout << ", vct_range_size: " << ft_vct_range.size();
	std::cout << ", vct_copy_size: " << ft_vct_copy.size();
	ft_vct = ft_vct_copy;
	ft_vct_copy = ft_vct_range;
	ft_vct_range.clear();
	ft_it = ft_vct.begin();
	std::cout << ", vct_values:";
	for (; ft_it != ft_vct.end(); ++ft_it)
		std::cout << " " << *ft_it;
	ft_it = ft_vct_range.begin();
	std::cout << ", vct_range_values:";
	for (; ft_it != ft_vct_range.end(); ++ft_it)
		std::cout << " " << *ft_it;
	ft_it = ft_vct_copy.begin();
	std::cout << ", vct_copy_values:";
	for (; ft_it != ft_vct_copy.end(); ++ft_it)
		std::cout << " " << *ft_it;
	std::cout << ", vct_size: " << ft_vct.size();
	std::cout << ", vct_range_size: " << ft_vct_range.size();
	std::cout << ", vct_copy_size: " << ft_vct_copy.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example27()
{
	/* Example 27 */
	/* Example tests insert(fill) */

	std::cout << COLOR_PURPLE_B << "Example 28" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector ->";
	std::vector<int> vct;
	std::vector<int> v;
	vct.assign(1000, 1);
	vct.insert(vct.end() - 50, 42000000, 2);
	v.push_back(vct.size());
	v.push_back(vct.capacity());
	std::cout << " value:";
	for (std::vector<int>::iterator first = v.begin(); first != v.end(); ++first)
		std::cout << " " << *first;
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  ->";
	ft::vector<int> ft_vct;
	ft::vector<int> ft_v;
	ft_vct.assign(1000, 1);
	ft_vct.insert(ft_vct.end() - 50, 42000000, 2);
	ft_v.push_back(ft_vct.size());
	ft_v.push_back(ft_vct.capacity());
	std::cout << " value:";
	for (ft::vector<int>::iterator first = ft_v.begin(); first != ft_v.end(); ++first)
		std::cout << " " << *first;
	std::cout << '.' << COLOR_END << std::endl;
}

void	vector_test()
{
	std::cout << COLOR_PURPLE_B << "Example 1" << std::endl;
	std::cout << COLOR_YELLOW_B;
	std_test::example1();
	std::cout << COLOR_GREEN_B << std::endl;
	ft_test::example1();
	std::cout << COLOR_END << std::endl;

/*	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
	example9();
	example10();
	example11();
	example12();
	example13();
	example14();
	example15();
	example16();
	example17();
	example18();
	example19();
	example20();
	example21();
	example22();
	example23();
	example24();
	example25();
	example26();
	example27();*/
}
