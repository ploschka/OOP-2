rm -fr build/*
touch build/.gitkeep
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/ && cd build && make