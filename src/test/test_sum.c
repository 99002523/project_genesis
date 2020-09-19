    #include "unity.h"
	#include "factorial.h"

	void setUp()
	{	}
	void tearDown()
	{	}
	
	void test_sum(void)
	{
  		TEST_ASSERT_EQUAL(30, sum(10, 20));
  		TEST_ASSERT_EQUAL(-30, sum(-50, 20));
	}

	int test_main(void)
	{
	  	UNITY_BEGIN();
  	
	  	RUN_TEST(test_sum);

  		return UNITY_END();
	}