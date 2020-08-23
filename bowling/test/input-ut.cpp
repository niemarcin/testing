#include <gtest/gtest.h>

#include "input.hpp"

constexpr char NON_EXISTING_PATH[] = "nonexistingPath";
constexpr char INPUT_DIRECTORY[] = "../../test/inputTestDirectory";
constexpr size_t INPUT_DIRECTORY_FILES_COUNT = 3;

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

}