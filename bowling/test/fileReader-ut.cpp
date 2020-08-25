#include <gtest/gtest.h>
#include <functional>
#include "fileReader.hpp"

using TestDirectory = std::tuple<std::string, bool>;

struct FileReaderTestFixture : public ::testing::TestWithParam<TestDirectory> 
{};

TEST_P(FileReaderTestFixture, ShouldValidateInputDirectory) {
    // GIVEN
    auto [path, isValid] = GetParam();

    // WHEN
    FileReader fileReader(path);

    // THEN
    ASSERT_EQ(fileReader.isValid(), isValid);
}

INSTANTIATE_TEST_SUITE_P(SomeDirectories,
                         FileReaderTestFixture,
                         ::testing::Values(TestDirectory{"nonexistingPath", false},
                                           TestDirectory{"./bin/bowling-ut", false},
                                           TestDirectory{"..", true}
                         ));

TEST(FileReaderTest, ShouldReadFiles) {
    //GIVEN
    std::string inputDirectory = "../test/inputTestDirectory";

    //WHEN
    FileReader fileReader(inputDirectory);

    //THEN
    ASSERT_TRUE(fileReader.isValid());
    EXPECT_EQ(fileReader.getLanesNum(), 3);
    EXPECT_EQ(fileReader.getLane(0)->getName(), "lane1");
    EXPECT_EQ(fileReader.getLane(0)->getPlayersNum(), 3);
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(0), "Name1:X|4-|3");
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(1), "Name2:34|X|0-");  
    EXPECT_EQ(fileReader.getLane(0)->getPlayer(2), ":X|22|33");

    EXPECT_EQ(fileReader.getLane(1)->getName(), "lane2");
    EXPECT_EQ(fileReader.getLane(1)->getPlayersNum(), 0);
    EXPECT_EQ(fileReader.getLane(2)->getName(), "lane3");
    EXPECT_EQ(fileReader.getLane(2)->getPlayersNum(), 2);
}
