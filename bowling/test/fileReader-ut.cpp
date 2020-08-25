#include <gtest/gtest.h>

#include "fileReader.hpp"

constexpr char NON_EXISTING_PATH[] = "nonexistingPath";
constexpr char INPUT_DIRECTORY[] = "../test/inputTestDirectory";
constexpr size_t INPUT_DIRECTORY_FILES_COUNT = 3;

constexpr char LANE1_NAME[] = "lane1";
constexpr char LANE2_NAME[] = "lane2";
constexpr char LANE3_NAME[] = "lane3";

constexpr size_t LANE1_PLAYERS_NUM = 3;
constexpr size_t LANE2_PLAYERS_NUM = 0;
constexpr size_t LANE3_PLAYERS_NUM = 2;

constexpr char LANE1_PLAYER1[] = "Name1:X|4-|3";
constexpr char LANE1_PLAYER2[] = "Name2:34|X|0-";
constexpr char LANE1_PLAYER3[] = ":X|22|33";

TEST(FileReaderTest, ShouldNotValidateWrongPath) {
    //GIVEN
    std::string path = NON_EXISTING_PATH;

    //WHEN
    FileReader fileReader(path);

    //THEN    
    EXPECT_FALSE(fileReader.isValid());
}

TEST(FileReaderTest, ShouldNotValidateRegularFiles) {
    //GIVEN
    std::string regularFile = "./bowling-ut";

    //WHEN
    FileReader fileReader(regularFile);

    //THEN    
    EXPECT_FALSE(fileReader.isValid());
}

TEST(FileReaderTest, ShouldValidateDirectoryPath) {
    //GIVEN
    std::string existingDirectory = "..";

    //WHEN
    FileReader fileReader(existingDirectory);

    //THEN    
    EXPECT_TRUE(fileReader.isValid());
}

TEST(InputTest, ShouldReadFiles) {
    //GIVEN
    std::string inputDirectory = INPUT_DIRECTORY;

    //WHEN
    FileReader fileReader(inputDirectory);

    //THEN
    ASSERT_TRUE(fileReader.isValid());
    EXPECT_EQ(fileReader.getLanesNum(), INPUT_DIRECTORY_FILES_COUNT);
    EXPECT_EQ(fileReader.getLane(0)->getName(), LANE1_NAME);
    EXPECT_EQ(fileReader.getLane(0)->getPlayersNum(), LANE1_PLAYERS_NUM);
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(0), LANE1_PLAYER1);
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(1), LANE1_PLAYER2);  
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(2), LANE1_PLAYER3);

    EXPECT_EQ(fileReader.getLane(1)->getName(), LANE2_NAME);
    EXPECT_EQ(fileReader.getLane(1)->getPlayersNum(), LANE2_PLAYERS_NUM);
    EXPECT_EQ(fileReader.getLane(2)->getName(), LANE3_NAME);
    EXPECT_EQ(fileReader.getLane(2)->getPlayersNum(), LANE3_PLAYERS_NUM);
}
