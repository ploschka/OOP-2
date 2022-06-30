cmake -S . -B build/ && cd build && make
mkdir ../exe
ln -sfr debug -t ../exe
cd tasks
ln -sfr CalculatingMachine/machine -t ../../exe
