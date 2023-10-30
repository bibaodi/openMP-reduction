echo "start build run sycl01"

SRC=${1:-NULL}

test ${SRC} = "NULL" && (echo "usage:app src.cc" && exit 0)

echo "01. build"
source /opt/intel/oneapi/setvars.sh
icpx -fsycl ${SRC}

echo "02. run"
./a.out

rm ./a.out

echo "end./"
