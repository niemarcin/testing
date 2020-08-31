#include <gtest/gtest.h>
#include <functional>
#include "filesReader.hpp"

using TestDirectory = std::pair<std::string, bool>;

struct FilesReaderTestFixture : public ::testing::TestWithParam<TestDirectory> {};

TEST_P(FilesReaderTestFixture, ShouldValidateInputDirectory) {
    // GIVEN
    auto [path, isValid] = GetParam();

    if (isValid) {
        //WHEN, THEN
        ASSERT_NO_THROW(FilesReader filesReader(path));   
    } else {
        //WHEN, THEN
        ASSERT_THROW(FilesReader filesReader(path), std::invalid_argument);
    }
}

INSTANTIATE_TEST_SUITE_P(SomeDirectories,
                         FilesReaderTestFixture,
                         ::testing::Values(TestDirectory{"nonexistingPath", false},
                                           TestDirectory{"./bin/bowling-ut", false},
                                           TestDirectory{"..", true}));

TEST(FilesReaderTest, ShouldReadFiles) {
    // GIVEN
    std::string inputDirectory = "../test/inputTestDirectory";

    // WHEN
    FilesReader filesReader(inputDirectory);

    // THEN
    EXPECT_EQ(filesReader.getLanesNum(), 3);
    EXPECT_EQ(filesReader.getLane(0)->getName(), "lane1");
    EXPECT_EQ(filesReader.getLane(0)->getPlayersNum(), 3);
    EXPECT_EQ(filesReader.getLane(0)->getPlayer(0), "Name1:X|4-|3");
    EXPECT_EQ(filesReader.getLane(0)->getPlayer(1), "Name2:34|X|0-");
    EXPECT_EQ(filesReader.getLane(0)->getPlayer(2), ":X|22|33");

    EXPECT_EQ(filesReader.getLane(1)->getName(), "lane2");
    EXPECT_EQ(filesReader.getLane(1)->getPlayersNum(), 0);
    EXPECT_EQ(filesReader.getLane(2)->getName(), "lane3");
    EXPECT_EQ(filesReader.getLane(2)->getPlayersNum(), 2);
}
