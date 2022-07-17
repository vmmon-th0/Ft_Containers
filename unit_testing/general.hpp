#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <map>
#include <set>
#include <ctime>
#include <deque>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <unistd.h>
#include <sys/time.h>
#include "../stack.hpp"
#include "../vector.hpp"
#include "../map.hpp"
#include "../set.hpp"
#include "../rainbow.hpp"

#define start main

#if !defined(CONTAINER)
#error unit testing require namespaces.
#endif

/* COLORS */
#define CRED(x)		RED2 x RESET
#define CCYAN(x)	CYAN x RESET
#define CGREEN(x)	GREEN x RESET
#define CYELLOW(x)	YELLOW x RESET

/* VECTOR */
#define TP			int
#define FT_VECTOR	ft::vector<TP>
#define STD_VECTOR	std::vector<TP>

/* MAP */
#define TP1			int
#define TP2			int
#define FT_MAP		ft::map<TP1, TP2>
#define STD_MAP		std::map<TP1, TP2>

/* SET */
#define FT_SET		ft::set<TP>
#define STD_SET		std::set<TP>

/* OTHER */
#define STD_LST		std::list<TP>

enum err
{
	EXIT_FILE
};

static int x = 0;

#endif