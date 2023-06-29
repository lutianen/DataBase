#!/bin/bash

# Format
clang-format -i `find MySQL/include/MySQL/ -type f -name *.h`
clang-format -i `find MySQL/src/ -type f -name *.cc`
clang-format -i `find MySQL/test/ -type f -name *.cc`

clang-format -i `find Redis/include/Redis/ -type f -name *.h`
clang-format -i `find Redis/src/ -type f -name *.cc`
clang-format -i `find Redis/test/ -type f -name *.cc`

# Count
cloc --git `git branch --show-current`
