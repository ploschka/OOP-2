cmake -S . -B build/ && cd build && make
mkdir ../exe
ln -sfr debug -t ../exe
