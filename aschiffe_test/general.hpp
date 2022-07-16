#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <map>
#include <set>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <numeric>
#include <sys/time.h>
#include "../stack.hpp"
#include "../vector.hpp"
#include "../map.hpp"
#include "../set.hpp"
#include "../rainbow.hpp"

#ifndef NB_SAMPLES
#define NB_SAMPLES 100
#endif

/* REDEFINE MAIN() */
#define start main

/* COLORS */
#define CRED(x)		RED2 x RESET
#define CCYAN(x)	CYAN x RESET
#define CGREEN(x)	GREEN x RESET
#define CYELLOW(x)	YELLOW x RESET

/* VECTOR STUFF */
#define TP			int
#define FT_VECTOR	ft::vector<TP>
#define STD_VECTOR	std::vector<TP>

/* MAP STUFF */
#define TP1			int
#define TP2			int
#define FT_MAP		ft::map<TP1, TP2>
#define STD_MAP		std::map<TP1, TP2>

/* SET STUFF */
#define FT_SET		ft::set<TP>
#define STD_SET		std::set<TP>

/* RANDOM STUFF */
#define STD_LST		std::list<TP>

/* TIME STUFF */
typedef double		time_type;

template<typename ContainerType>
time_type
measure_speed_execution(void(*tester)(ContainerType&), ContainerType& x)
{
		clock_t c;
		std::vector<time_type> samples;
		for (int i = 0; i < NB_SAMPLES; ++i)
		{
				c = std::clock();
				(*tester)(x);
				samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
		}
		srand(time(NULL));
		time_type average = std::accumulate(samples.begin(), samples.end(), 0.) / NB_SAMPLES;
		return average;
}

template<typename ftContainer, typename stdContainer>
void
measure_handler(ftContainer& ft_container, stdContainer& std_container, void(*ft_tester)(ftContainer&), void(*std_tester)(stdContainer&))
{
	time_type ft_time_test;
	time_type std_time_test;
	ft_time_test = measure_speed_execution<ftContainer>(ft_tester, ft_container);
	std_time_test = measure_speed_execution<stdContainer>(std_tester, std_container);
	ft_time_test / std_time_test >= 20 ? std::cout << CYELLOW("A bit slower") : std::cout << CGREEN("Success");
	std::cout << std::endl;
	std::cout << "ft::container<>  speed execution  : " << ft_time_test << "[us]" << std::endl;
	std::cout << "std::container<> speed execution  : " << std_time_test << "[us]" << std::endl;
	std::cout << "gap with the real STL             : " << ((float)ft_time_test / std_time_test) << " %" << std::endl;

	

	std::cout << std::endl;
}

template<typename Iter>
const std::string
file_output_spe(Iter x)
{
	std::string y;
	y += *x;
	return (y);
}

const std::string
file_output_spe(FT_MAP::const_iterator& x)
{
	std::string y;
	y += x->first;
	y += x->second;
	return (y);
}

const std::string
file_output_spe(STD_MAP::const_iterator& x)
{
	std::string y;
	y += x->first;
	y += x->second;
	return (y);
}

template<typename ftContainer, typename stdContainer>
void
verify_content(const ftContainer& ft_container, const stdContainer& std_container, int& test_count)
{
	std::ofstream ft_file("ft_file");
	std::ofstream std_file("std_file");
	typename ftContainer::const_iterator fit = ft_container.begin();
	typename stdContainer::const_iterator sit = std_container.begin();

	while (fit != ft_container.end())
	{
		ft_file << file_output_spe(fit);
		++fit;
	}
	while (sit != std_container.end())
	{
		std_file << file_output_spe(sit);
		++sit;
	}
	ft_file << "size(): " << ft_container.size() << std::boolalpha << "empty(): " << ft_container.empty() << std::endl;
	std_file << "size(): "<< std_container.size() << std::boolalpha << "empty(): " << std_container.empty() << std::endl;
	ft_file.close();
	std_file.close();
	system("diff ft_file std_file > log_file.log");
	system("rm -f ft_file std_file");
	std::ifstream in("log_file.log");
	if (!in)
	{
		std::cerr << "log_file.log" << " failed to open" << std::endl;
	}
	else
	{
		bool empty = (in.get(), in.eof());
		std::cout << test_count << ") ";
		empty == true ? std::cout << CGREEN("Content is identical, nothing is returned in the log file") :
						std::cout << CYELLOW("Content is not identical, check the logfile");
		std::cout << std::endl;
	}
}

template<typename ContainerType>
void
print_content(const ContainerType& x)
{
	for (typename ContainerType::const_iterator cit = x.begin(); cit != x.end(); ++cit)
	{
		std::cout << *cit;
		if (cit + 1 != x.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << "[CONTAINER] size     : " << x.size() << std::endl;
	std::cout << "[CONTAINER] max_size : " << x.max_size() << std::endl;
	std::cout << "[CONTAINER] empty    : " << std::boolalpha << x.empty() << std::endl;
}

#endif