cmake -S . -B build/ && cd build && make
mkdir ../exe
ln -sfr -t ../exe tasks/CalculatingMachine/machine tasks/RegisterAndLogin/login tasks/RegisterAndLogin/register tests/test
