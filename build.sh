rm -fr build/*
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/ && cd build && make
mkdir ../exe
ln -sr debug -t ../exe
