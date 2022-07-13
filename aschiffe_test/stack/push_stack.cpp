#include "test_stack.hpp"

void
same_content(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	MutantStack<TP, FT_STACK>	ft_mutant_stack(ft_stack);
	MutantStack<TP, STD_STACK>	std_mutant_stack(std_stack);

	MutantStack<TP, FT_STACK>::iterator fit = ft_mutant_stack.begin();
	MutantStack<TP, STD_STACK>::iterator sit = std_mutant_stack.begin();

	std::ofstream ft_file("ft_file");
	std::ofstream std_file("std_file");
	while (fit != ft_mutant_stack.end())
	{
		ft_file << *fit << std::endl;
		++fit;
	}
	while (sit != std_mutant_stack.end())
	{
		std_file << *sit << std::endl;
		++sit;
	}
	ft_file << ft_stack.size() << std::endl;
	std_file << std_stack.size() << std::endl;
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
		empty == true ? std::cout << CGREEN("Content is identical, nothing is returned in the log file") :
						std::cout << CYELLOW("Content is not identical, check the logfile");
		std::cout << std::endl;
	}
}

void
push_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	ft::vector<time_type> 	ft_time_sample;
	std::vector<time_type>	std_time_sample;
	std::cout << "==============================PUSH==============================" << std::endl
																					<< std::endl;
	for (int i = 0; i < 100; ++i)
	{
		struct timeval start;
		struct timeval stop;
		gettimeofday(&start, NULL);
		ft_stack.push(i);
		gettimeofday(&stop, NULL);
		ft_time_sample.push_back((stop.tv_sec * (int)1e6 + stop.tv_usec) - (start.tv_sec * (int)1e6 + start.tv_usec));
	}
	time_type ft_average = std::accumulate(ft_time_sample.begin(), ft_time_sample.end(), 0);
	for (int i = 0; i < 100; ++i)
	{
		struct timeval start;
		struct timeval stop;
		gettimeofday(&start, NULL);
		std_stack.push(i);
		gettimeofday(&stop, NULL);
		std_time_sample.push_back((stop.tv_sec * (int)1e6 + stop.tv_usec) - (start.tv_sec * (int)1e6 + start.tv_usec));
	}
	time_type std_average = std::accumulate(std_time_sample.begin(), std_time_sample.end(), 0);
	std::cout << "ft_stack speed execution  : " << ft_average << "[ns]" << std::endl;
	std::cout << "std_stack speed execution : " << std_average << "[ns]" << std::endl << std::endl;
	ft_average / std_average >= 20 ? std::cout << CRED("FAIL") : std::cout << CGREEN("SUCCESS");
	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	same_content(ft_stack, std_stack);
 	std::cout << std::endl;
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	push_stack_test(ft_stack, std_stack);
	return 0;
}