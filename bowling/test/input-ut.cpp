#include <gtest/gtest.h>

#include "input.hpp"

constexpr char NON_EXISTING_PATH[] = "nonexistingPath";
constexpr char INPUT_DIRECTORY[] = "../../test/inputTestDirectory";
constexpr size_t INPUT_DIRECTORY_FILES_COUNT = 3;

constexpr char LANE1_NAME[] = "lane1";
constexpr char LANE2_NAME[] = "lane2";
constexpr char LANE3_NAME[] = "lane3";

TEST(InputTest, ShouldNotValidateWrongPath) {
    //GIVEN
    std::string path = NON_EXISTING_PATH;

    //WHEN
    Input input(path);

    //THEN    
    EXPECT_FALSE(input.isValid());
}

TEST(InputTest, ShouldNotValidateRegularFiles) {
    //GIVEN
    std::string regularFile = "./bowling-ut";

    //WHEN
    Input input(regularFile);

    //THEN    
    EXPECT_FALSE(input.isValid());
}

TEST(InputTest, ShouldValidateDirectoryPath) {
    //GIVEN
    std::string existingDirectory = "..";

    //WHEN
    Input input(existingDirectory);

    //THEN    
    EXPECT_TRUE(input.isValid());
}

TEST(InputTest, ShouldReadFiles) {
    //GIVEN
    std::string inputDirectory = INPUT_DIRECTORY;

    //WHEN
    Input input(inputDirectory);

    //THEN
    EXPECT_EQ(input.getLinesNum(), INPUT_DIRECTORY_FILES_COUNT);
    EXPECT_EQ(input.getLane(0)->getName(), LANE1_NAME);
    EXPECT_EQ(input.getLane(1)->getName(), LANE2_NAME);
    EXPECT_EQ(input.getLane(2)->getName(), LANE3_NAME);
}