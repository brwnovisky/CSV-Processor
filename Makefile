#Info: Makefile to build C++ Shared Library (.so) and run GoogleTest

# Build variables
CXX                 = g++
CXXFLAGS            = -Wall -Wextra -Werror -Iinc -I/usr/local/include -g
LDFLAGS             = -shared -fPIC
SRC_DIR             = src
INC_DIR             = inc
BUILD_DIR           = build
LIBRARY             = libcsv.so
SOURCES             = $(wildcard $(SRC_DIR)/*/*.cpp)
OBJECTS             = $(patsubst $(SRC_DIR)/*/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
# Test variables
TEST_BINARY         = runTests
TEST_DIR            = test
TEST_SOURCES        = $(wildcard $(TEST_DIR)/*/*.cpp)
TEST_OBJECTS        = $(patsubst $(TEST_DIR)/*/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
GTEST_LIBS          = -lgtest -lgtest_main -lpthread

all                 : $(LIBRARY)

$(LIBRARY)          : $(OBJECTS) | $(BUILD_DIR)
					  $(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o    : $(SRC_DIR)/*/%.cpp | $(BUILD_DIR)
					  $(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o    : $(TEST_DIR)/*/%.cpp | $(BUILD_DIR)
					  $(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)        :
					  mkdir -p $(BUILD_DIR)

clean               :
					  rm -rf $(BUILD_DIR)

fclean              : clean
					  rm -rf $(LIBRARY) $(TEST_BINARY)

re                  : fclean
					  make

test                : $(LIBRARY) $(TEST_OBJECTS) | $(BUILD_DIR)
					  $(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(OBJECTS) -L. -lcsv $(GTEST_LIBS) -o $(TEST_BINARY)
					  ./$(TEST_BINARY) --gtest_filter=Mandatory*
					  ./$(TEST_BINARY) --gtest_filter=Bonus*

.PHONY              : all clean fclean re test
