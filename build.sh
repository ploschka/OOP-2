cmake -S . -B build/ && cd build && make
mkdir ../exe
ln -sfr debug -t ../exe
cd tasks
ln -sfr -t ../../exe CalculatingMachine/machine RegisterAndLogin/login RegisterAndLogin/register
