#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <stack>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <iostream>
#include <numeric>
#include <iomanip>
#include "../stack.hpp"
#include "../vector.hpp"
#include "../map.hpp"
#include "../set.hpp"
#include "../rainbow.hpp"

typedef double time_type;

// #ifndef CONTAINER
#define CONTAINER ft
// #endif

#define start main

/* CONSTRUCTOR SAMPLES */
#define COPY_SAMPLES_NB     1000
#define RANGE_SAMPLES_NB    1000
#define FILL_SAMPLES_NB     1000

/* INSERT SAMPLES */
#define SINGLE_INSERT_NB	1000
#define FILL_INSERT_NB		1000
#define RANGE_INSERT_NB		1000

/* ERASE SAMPLES */
#define SINGLE_ERASE_NB		1000
#define RANGE_ERASE_NB		1000


/* TYPE STUFF */

#define TP          int
#define TP1			int
#define TP2			int

/* VECTOR STUFF */
#define FT_VECTOR	ft::vector<TP>
#define STD_VECTOR	std::vector<TP>
#define SAMPLE_VEC  std::vector<time_type>

/* MAP STUFF */
#define FT_MAP		ft::map<TP1, TP2>
#define STD_MAP		std::map<TP1, TP2>

/* SET STUFF */
#define FT_SET		ft::set<TP>
#define STD_SET		std::set<TP>

/* RANDOM STUFF */
#define STD_LST		std::list<TP>

/* COLORS */
#define CRED(x)		RED2 x RESET
#define CCYAN(x)	CYAN x RESET
#define CGREEN(x)	GREEN x RESET
#define CYELLOW(x)	YELLOW x RESET

#endif