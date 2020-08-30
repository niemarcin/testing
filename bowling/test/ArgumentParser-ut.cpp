#include <gtest/gtest.h>

#include "ArgumentParser.hpp"

TEST(ArgumentParserTests, shouldBeInitializedWithGivenAppName) {
    // GIVEN
    char appName[] = "./bowling";
    char* argumentsArray[] = {appName};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getAppName();

    // THEN
    ASSERT_EQ(result, appName);
}

TEST(ArgumentParserTests, inputDirectoryStringShouldBeEmptyWhenNoArgumentsWereGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char* argumentsArray[] = {appName};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getInputDirectory();

    // THEN
    ASSERT_EQ(result, "");
}

TEST(ArgumentParserTests, outputFileNameStringShouldBeEmptyWhenNoArgumentsWereGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char* argumentsArray[] = {appName};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getOutputFileName();

    // THEN
    ASSERT_EQ(result, "");
}

TEST(ArgumentParserTests, outputFileNameStringShouldBeEmptyWhenOnlyInputDirectoryWasGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "inputDir";
    char* argumentsArray[] = {appName, arg1};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getOutputFileName();

    // THEN
    ASSERT_EQ(result, "");
}

TEST(ArgumentParserTests, inputDirectoryAndOutputFileNameStringsShouldBeEmptyWhenNoArgumentsWereGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char* argumentsArray[] = {appName};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto inputDirectory = ap.getInputDirectory();
    auto outputFileName = ap.getOutputFileName();
    auto result = inputDirectory.empty() && outputFileName.empty();

    // THEN
    ASSERT_TRUE(result);
}

TEST(ArgumentParserTests, inputDirectoryShouldBeInitializedWithGivenArgument) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "inputDir";
    char* argumentsArray[] = {appName, arg1};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getInputDirectory();

    // THEN
    ASSERT_EQ(result, arg1);
}

TEST(ArgumentParserTests, outputFileNameShouldBeInitializedWithGivenArgument) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "inputDir";
    char arg2[] = "outputFileName";
    char* argumentsArray[] = {appName, arg1, arg2};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.getOutputFileName();

    // THEN
    ASSERT_EQ(result, arg2);
}

TEST(ArgumentParserTests, helpShouldBeCalledWhenNotEnoughArguments) {
    // GIVEN
    char appName[] = "./bowling";
    char* argumentsArray[] = {appName};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, true);
}

TEST(ArgumentParserTests, helpShouldBeCalledWhenTooMuchArguments) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "arg1";
    char arg2[] = "arg2";
    char arg3[] = "arg3";
    char* argumentsArray[] = {appName, arg1, arg2, arg3};   
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, true);
}

TEST(ArgumentParserTests, helpShouldBeCalledWhenHFlagUsed) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "-h";
    char* argumentsArray[] = {appName, arg1};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, true);
}

TEST(ArgumentParserTests, helpShouldBeCalledWhenHelpFlagUsed) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "--help";
    char* argumentsArray[] = {appName, arg1};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, true);
}

TEST(ArgumentParserTests, helpShouldNotBeCalledWhenSingleArgumentWasGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "inputDir";
    char* argumentsArray[] = {appName, arg1};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, false);
}

TEST(ArgumentParserTests, helpShouldNotBeCalledWhenTwoArgumentsWereGiven) {
    // GIVEN
    char appName[] = "./bowling";
    char arg1[] = "inputDir";
    char arg2[] = "outputFile";
    char* argumentsArray[] = {appName, arg1, arg2};
    int argumentsCounter = sizeof(argumentsArray) / sizeof(char*);
    ArgumentParser ap{argumentsCounter, argumentsArray};

    // WHEN
    auto result = ap.isHelpNeeded();

    // THEN
    ASSERT_EQ(result, false);
}
