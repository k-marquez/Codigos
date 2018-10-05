#include <iostream>
# include <random>
# include <chrono>
#include <vector>

#include <selection_search.H>
#include <person.H>

using namespace std;

using rng_t = mt19937_64;
using unif  = uniform_int_distribution<int>;
using uniff = uniform_real_distribution<float>;
using bern  = bernoulli_distribution;

ostream & operator << (ostream & out,  const vector<Person> & ps)
{
  auto sz = ps.size();
  out << "Set with " << sz;
  if (sz == 1)
    out << " person\n";
  else
    out << " people\n";

  for (const Person & p : ps)
    out << p.to_string() << endl;

  return out;
}

ostream & operator << (ostream & out,  const Person & ps)
{
    out << ps.to_string() << endl;
  return out;
}

//Functor diseñado para ordenar elementos de un contenedor de personas por el peso.
class SortByWeight
{
public:
	bool operator() (const Person & ps1, const Person & ps2) const
	{
		if (ps2.get_weight() < ps1.get_weight())
			return true;
		return false;
	}	
};
//Functor diseñado para ordenar elementos de un contenedor de personas por la altura.
class SortByHeight
{
public:
	bool operator() (const Person & ps1, const Person & ps2) const
	{
		if (ps2.get_height() < ps1.get_height())
			return true;
		return false;
	}	
};

//Functor diseñado para ordenar elementos de un contenedor de personas por la edad.
class SortByAge
{
public:
	bool operator() (const Person & ps1, const Person & ps2) const
	{
		if (ps2.get_age() < ps1.get_age())
			return true;
		return false;
	}	
};

//Functor diseñado para ordenar elementos de un contenedor de personas por el nombre.
class SortByName
{
public:
	bool operator() (const Person & ps1, const Person & ps2) const
	{
		if (ps2.get_name() < ps1.get_name())
			return true;
		return false;
	}	
};

int main(int argc, char const *argv[])
{
	rng_t rng(chrono::system_clock::now().time_since_epoch().count()
	    % rng_t::max());
  
  unif  age_r(18, 45);
  uniff height_r(1.5f, 2.3f);
  uniff weight_r(60.f, 130.f);
  bern  glasses_r(0.3);

  vector<Person>  ps = {
    Person("Steve", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Mike", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Paul", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("John", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("James", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Tarja", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Amy", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Floor", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Bruce", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
  };

vector<Person>  * p = &ps;
  
cout <<  ps << endl;
/*SelectionSearch(p, ps.size(), [](const Person & ps1, const Person &ps2)
    {
      return ps2.get_height() < ps1.get_height();
    });
*/

//SelectionSearch(p, ps.size(), SortByWeight());

//SelectionSearch(p, ps.size(), SortByHeight());

//SelectionSearch(p, ps.size(), SortByAge());

SelectionSearch(p, ps.size(), SortByName());

cout <<  ps << endl;

	return 0;
}