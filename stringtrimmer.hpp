#pragma once

#include <iostream>
#include <string>

namespace {
    using std::cout;
    using std::endl;

    namespace dwt {
        void trimRight(char* s) {
            const char STRING_END = '\0';
            const char REMOVE_CHAR = ' ';

            if (*s == STRING_END) {
                return;
            }

            size_t currentId = 1;
            size_t spaceSeqStartId = 0;

            for (char* cur = s; *cur != STRING_END; cur++) {
                if (*(cur) == REMOVE_CHAR && !static_cast<bool>(spaceSeqStartId)) {
                    spaceSeqStartId = currentId;
                }
                else if (*(cur) != REMOVE_CHAR) {
                    spaceSeqStartId = 0;
                }

                ++currentId;
            }

            if (static_cast<bool>(spaceSeqStartId)) {
                *(s + spaceSeqStartId - 1) = STRING_END;
            }
        }

        void testTrimRight() {
            const size_t STR_SIZE = 100;
            const size_t TEST_NUMBER = 19;

            char testStrings[TEST_NUMBER][STR_SIZE] = {
                "",
                " ",
                "  ",
                "   ",
                "           ",
                "a",
                "a ",
                " a",
                "   a",
                "a   ",
                "           a",
                "a            ",
                "a   b   c",
                "a   b   ",
                "hello",
                "                hello ",
                "        hello         ",
                "   he      l         l    o",
                "   he      l         l    o    ",
            };

            char expectedStrings[TEST_NUMBER][STR_SIZE] = {
                "",
                "",
                "",
                "",
                "",
                "a",
                "a",
                " a",
                "   a",
                "a",
                "           a",
                "a",
                "a   b   c",
                "a   b",
                "hello",
                "                hello",
                "        hello",
                "   he      l         l    o",
                "   he      l         l    o",
            };

            for (size_t j = 0; j < TEST_NUMBER; ++j) {
                trimRight(testStrings[j]);
            }

            for (size_t i = 0; i < TEST_NUMBER; ++i) {
                if (strcmp(testStrings[i], expectedStrings[i])) {
                    throw std::exception(std::to_string(i).c_str());
                }
            }
        }

    } // doctor web task

} // end of unnamed namespace