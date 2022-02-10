#include "unity.h"
#include "../inc/restaurant_operations.h"

/* Prototypes for all the test functions */
void test_total_bill(void);
void test_net_total(void);
void test_grand_total(void);

void setUp(void){}
void tearDown(void){}

int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */

  RUN_TEST(test_total_bill);
  RUN_TEST(test_net_total);
  RUN_TEST(test_grand_total);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_total_bill(void){
    TEST_ASSERT_EQUAL(135, total_bill(5,27));
    TEST_ASSERT_EQUAL(25, total_bill(5,5));
    TEST_ASSERT_EQUAL(0,total_bill(1,0));//invalid
    TEST_ASSERT_EQUAL(4000,total_bill(20,200));//big calculation
    TEST_ASSERT_EQUAL(250, total_bill(1,250));
    TEST_ASSERT_EQUAL(0, total_bill(0,5));
    
}

void test_net_total(void){
    TEST_ASSERT_EQUAL(36, net_total(40));
    TEST_ASSERT_EQUAL(72, net_total(80));
    TEST_ASSERT_EQUAL(121.5, net_total(135));
    TEST_ASSERT_EQUAL(80, net_total(100));
    TEST_ASSERT_EQUAL(2000.20, net_total(2500.25));//float total
    TEST_ASSERT_EQUAL(13960, net_total(17450));//big calculation
    TEST_ASSERT_EQUAL(-1219.2, net_total(-1524));//negative number
}

void test_grand_total(void){
    TEST_ASSERT_EQUAL(94.4, grand_total(80));
    TEST_ASSERT_EQUAL(165.2, grand_total(140));
    TEST_ASSERT_EQUAL(143.37, grand_total(121.5));
    TEST_ASSERT_EQUAL(-1798.32, grand_total(-1524));
    TEST_ASSERT_EQUAL(2950, grand_total(2500));
    TEST_ASSERT_EQUAL(1210308, grand_total(1025685));//wrong case .3 removed
    TEST_ASSERT_EQUAL(14752.65, grand_total(12502.25));//long float calculation

}
