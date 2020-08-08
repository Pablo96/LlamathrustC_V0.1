#include "CoreLib.h"
#include "Threading.h"
#include "Networking.h"
#include "test_framework.h"
#include <ErrorCodes.h>

int main(int argc, const char **argv) {
  log_set_level(LOG_ERROR);

  LT_ADD_TEST(TestArrayCount, TEST_SUCCESS);
  LT_ADD_TEST(TestArray, TEST_SUCCESS);
  LT_ADD_TEST(TestArrayOutRange, ERROR_INDEX_OUT_OF_BOUNDS);

  LT_ADD_TEST(TestStack, TEST_SUCCESS);
  LT_ADD_TEST(TestQueue, TEST_SUCCESS);

  LT_ADD_TEST(TestThreadSpawn, TEST_SUCCESS);
  LT_ADD_TEST(TestThreadExitCode, TEST_SUCCESS);
  LT_ADD_TEST(TestThreadLock, TEST_SUCCESS);
  LT_ADD_TEST(TestThreadPool, TEST_SUCCESS);

  LT_ADD_TEST(TestNetworking, TEST_SUCCESS);

  return LT_TestRun();
}
