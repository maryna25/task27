#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include <iostream>
#include "Volume.h"

TEST_CASE("Checking set()")
{
	Volume& v = Volume::set(20);
	REQUIRE(v.get() == 20);
	Volume& v1 = Volume::set(28);
	REQUIRE(v1.get() == 20);
}

TEST_CASE("Checking singleton property")
{
	Volume& v = Volume::set();
	Volume& v1 = Volume::set();
	REQUIRE(&v == &v1);
}

TEST_CASE("Checking increase()")
{
	Volume& v = Volume::set(20);
	v.increase();
	REQUIRE(v.get() == 21);
	v.increase(3);
	REQUIRE(v.get() == 24);
}

TEST_CASE("Checking decrease()")
{
	Volume& v = Volume::set(24);
	v.decrease();
	REQUIRE(v.get() == 23);
	v.decrease(3);
	REQUIRE(v.get() == 20);
}

int main(int argc, char* argv[])
{
	/*Volume::set(7);

	Volume& v = Volume::set(20);
	v.increase(2);
	std::cout << v.get() << std::endl;

	Volume& v = Volume::set();
	Volume& v1 = Volume::set();

	//Volume v1(v);
	//Volume v1(12);
	//Volume v1;

	getchar();
	return 0;*/
	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}